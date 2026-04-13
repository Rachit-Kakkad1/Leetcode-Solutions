import config from './config.js';
import { fetchAllProblems, fetchSubmissions, fetchSubmissionDetails, delay } from './api.js';
import { saveSubmission, initGit, commitAndPush } from './utils.js';
import fs from 'fs';
import path from 'path';

async function fetchProcess() {
  if (!config.sessionCookie) {
    console.error('[ERROR] LEETCODE_SESSION is missing in .env config.');
    process.exit(1);
  }

  console.log('[INFO] Fetching all questions to map difficulties...');
  let diffMap = {};
  try {
    diffMap = await fetchAllProblems();
    console.log(`[INFO] Successfully fetched mappings for ${Object.keys(diffMap).length} problems.`);
  } catch (e) {
    console.warn('[WARN] Could not fetch problem list from REST API. Difficulties will default to "unknown".', e.message);
  }

  if (!fs.existsSync(config.outDir)) {
    fs.mkdirSync(config.outDir, { recursive: true });
  }

  console.log('[INFO] Initializing git repository if necessary...');
  await initGit(config.outDir);

  console.log('[INFO] Fetching accepted submissions...');
  let offset = 0;
  const limit = 20;
  let hasNext = true;
  let totalFetched = 0;
  let newSaved = 0;

  while (hasNext) {
    const data = await fetchSubmissions(offset, limit);
    if (!data) break;

    const submissions = data.submissions || [];
    hasNext = data.hasNext;
    offset += limit;

    for (const sub of submissions) {
      if (sub.statusDisplay !== 'Accepted') continue;
      if (config.languageFilter && sub.lang !== config.languageFilter) continue;

      totalFetched++;
      const difficulty = diffMap[sub.titleSlug] || 'unknown';
      
      try {
        const details = await fetchSubmissionDetails(parseInt(sub.id, 10));
        const code = details.code;
        const saved = await saveSubmission(config.outDir, sub, difficulty, code);
        
        if (saved) {
          console.log(`[+] Saved new solution: ${sub.title} (${sub.lang})`);
          newSaved++;

          // Commit and push for each saved solution individually
          await commitAndPush(config.outDir, sub.title, difficulty, config.commitMessage);
        } else {
          console.log(`[-] Skipped (already exists): ${sub.title} (${sub.lang})`);
        }
      } catch (err) {
        console.error(`[ERROR] Fetching details for ${sub.titleSlug}: ${err.message}`);
      }
      
      await delay(config.delayMs);
    }
  }

  console.log(`\n[INFO] Fetch complete! Scanned ${totalFetched} AC submissions. Saved ${newSaved} new solutions.`);
}

async function pushProcess() {
  console.log('[INFO] Starting batch git commit & push...');
  if (!fs.existsSync(config.outDir)) {
    console.warn('[WARN] Output directory does not exist. Nothing to push.');
    return;
  }
  await initGit(config.outDir);
  
  const didCommit = await commitAndPush(
    config.outDir, 
    "Multiple Solutions", 
    "Batch update", 
    "Sync LeetCode Solutions"
  );
  if (didCommit) {
    console.log('[INFO] Changes committed and pushed successfully.');
  } else {
    console.log('[INFO] No new changes to commit.');
  }
}

async function main() {
  const args = process.argv.slice(2);
  const command = args[0] || 'all';

  if (command === 'fetch' || command === 'all') {
    await fetchProcess();
  } else if (command === 'push') {
    await pushProcess();
  } else {
    console.log('Usage: node index.js [fetch|push|all]');
  }
}

main().catch(console.error);
