import dotenv from 'dotenv';
dotenv.config();

export default {
  outDir: '..', // Saves solutions to the root of Leetcode Solution
  delayMs: 2000, // Important: delay between requests to avoid Leetcode rate limits
  sessionCookie: process.env.LEETCODE_SESSION,
  csrfToken: process.env.CSRF_TOKEN,
  languageFilter: null, // Set to something like 'cpp', 'python3', 'javascript' to filter
  commitMessage: 'Added: {title} ({difficulty})'
};
