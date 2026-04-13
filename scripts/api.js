import axios from 'axios';
import config from './config.js';

const API_URL = 'https://leetcode.com/graphql';

const getHeaders = () => ({
  'Content-Type': 'application/json',
  'Cookie': `LEETCODE_SESSION=${config.sessionCookie}; csrftoken=${config.csrfToken}`,
  'x-csrftoken': config.csrfToken,
  'Referer': 'https://leetcode.com',
  'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36'
});

export const delay = ms => new Promise(res => setTimeout(res, ms));

async function fetchWithRetry(query, variables, retries = 3) {
  const headers = getHeaders();
  for (let i = 0; i < retries; i++) {
    try {
      const response = await axios.post(API_URL, { query, variables }, { headers });
      if (response.data.errors) {
        throw new Error(JSON.stringify(response.data.errors));
      }
      return response.data;
    } catch (error) {
      console.warn(`[WARN] API call failed: ${error.message}. Retrying... (${i + 1}/${retries})`);
      if (error.response?.status === 429) {
        console.warn(`[WARN] Rate limit hit. Backing off...`);
        await delay(5000 * (i + 1)); 
      } else {
        await delay(config.delayMs);
      }
      if (i === retries - 1) throw error;
    }
  }
}

export async function fetchAllProblems() {
  // We use the REST endpoint strictly to gather the difficulty level of all problems quickly.
  // This avoids hammering the GraphQL API for each problem's difficulty.
  const res = await axios.get('https://leetcode.com/api/problems/algorithms/');
  const map = {};
  res.data.stat_status_pairs.forEach(p => {
    const slug = p.stat.question__title_slug;
    const diff = p.difficulty.level === 1 ? 'easy' : p.difficulty.level === 2 ? 'medium' : 'hard';
    map[slug] = diff;
  });
  return map;
}

export async function fetchSubmissions(offset = 0, limit = 20) {
  const query = `
    query submissionList($offset: Int!, $limit: Int!) {
      submissionList(offset: $offset, limit: $limit) {
        hasNext
        submissions {
          id
          title
          titleSlug
          statusDisplay
          lang
          timestamp
        }
      }
    }
  `;
  const data = await fetchWithRetry(query, { offset, limit });
  return data.data.submissionList;
}

export async function fetchSubmissionDetails(submissionId) {
  const query = `
    query submissionDetails($submissionId: Int!) {
      submissionDetails(submissionId: $submissionId) {
        code
        timestamp
        statusCode
      }
    }
  `;
  const data = await fetchWithRetry(query, { submissionId });
  return data.data.submissionDetails;
}
