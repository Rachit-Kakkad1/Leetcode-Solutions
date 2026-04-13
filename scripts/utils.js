import fs from 'fs/promises';
import { existsSync } from 'fs';
import path from 'path';
import { exec } from 'child_process';
import { promisify } from 'util';

const execAsync = promisify(exec);

export const EXTENSIONS = {
  cpp: 'cpp',
  java: 'java',
  python: 'py',
  python3: 'py',
  c: 'c',
  csharp: 'cs',
  javascript: 'js',
  ruby: 'rb',
  swift: 'swift',
  golang: 'go',
  scala: 'scala',
  kotlin: 'kt',
  rust: 'rs',
  php: 'php',
  typescript: 'ts',
  racket: 'rkt',
  erlang: 'erl',
  elixir: 'ex'
};

export function normalizeName(name) {
  return name.toLowerCase().replace(/[^a-z0-9]+/g, '-').replace(/(^-|-$)/g, '');
}

export async function saveSubmission(outDir, submission, difficulty, code) {
  const langExt = EXTENSIONS[submission.lang] || 'txt';
  const folderName = normalizeName(submission.titleSlug);
  const diffDir = path.join(outDir, difficulty);
  const probDir = path.join(diffDir, folderName);

  if (!existsSync(probDir)) {
    await fs.mkdir(probDir, { recursive: true });
  }

  const solutionPath = path.join(probDir, `solution.${langExt}`);
  const metadataPath = path.join(probDir, 'metadata.json');

  let shouldSave = true;
  if (existsSync(metadataPath)) {
    try {
      const existing = JSON.parse(await fs.readFile(metadataPath, 'utf8'));
      if (existing.timestamp >= parseInt(submission.timestamp, 10)) {
        shouldSave = false; // We already have this or a newer submission
      }
    } catch (e) {
      // If metadata is somehow corrupt, we overwrite
    }
  }

  if (shouldSave) {
    await fs.writeFile(solutionPath, code);
    await fs.writeFile(metadataPath, JSON.stringify({
      title: submission.title,
      difficulty,
      language: submission.lang,
      timestamp: parseInt(submission.timestamp, 10),
      url: `https://leetcode.com/problems/${submission.titleSlug}/`
    }, null, 2));
    return true;
  }
  return false;
}

export async function initGit(outDir) {
  if (!existsSync(path.join(outDir, '.git'))) {
    console.log('[Git] Initializing repository...');
    await execAsync('git init', { cwd: outDir });
  }
}

export async function commitAndPush(outDir, title, difficulty, messageTemplate) {
  try {
    const statusResult = await execAsync('git status --porcelain', { cwd: outDir });
    if (!statusResult.stdout.trim()) {
      return false; // No changes to commit
    }

    const commitMsg = messageTemplate.replace('{title}', title).replace('{difficulty}', difficulty);
    await execAsync('git add .', { cwd: outDir });
    await execAsync(`git commit -m "${commitMsg}"`, { cwd: outDir });
    
    // Attempt push. We enclose in try-catch in case upstream is not set
    try {
      await execAsync('git push', { cwd: outDir });
      console.log(`[Git] Pushed: ${commitMsg}`);
    } catch (pushErr) {
      console.log(`[Git] Committed: ${commitMsg}`);
      console.warn('[WARN] Push failed. Make sure your git remote is configured. Run: `git remote add origin <url>` and `git push -u origin main`');
    }
    return true;
  } catch (error) {
    console.error(`[ERROR] Git operation failed: ${error.message}`);
    return false;
  }
}
