# 140. Word Break II

**Difficulty: Hard**

## Problem Description

Given a string `s` and a dictionary of strings `wordDict`, add spaces in `s` to construct a sentence where each word is a valid dictionary word. Return all such possible sentences in **any order**. Note that the same word in the dictionary may be reused multiple times in the segmentation.

**Example 1:**
```
Input: s = "catsanddog", wordDict = ["cat","cats","and","sand","dog"]
Output: ["cats and dog","cat sand dog"]
```

**Example 2:**
```
Input: s = "pineapplepenapple", wordDict = ["apple","pen","applepen","pine","pineapple"]
Output: ["pine apple pen apple","pineapple pen apple","pine applepen apple"]
```

**Example 3:**
```
Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
Output: []
```

**Constraints:**
* `1 <= s.length <= 20`
* `1 <= wordDict.length <= 1000`
* `1 <= wordDict[i].length <= 10`
* `s` and `wordDict[i]` consist of only lowercase English letters.
* All the strings of `wordDict` are unique.
* Input is generated in a way that the length of the answer doesn't exceed 10^5.

## Solution Approach

We use **DFS with Memoization** to solve this problem. The idea is to recursively build sentences by trying all possible words from the dictionary that match the prefix of the remaining string.

1. Use a `Set` for O(1) lookups in the dictionary.
2. Use a memoization map to store results for each starting index to avoid recomputation.
3. For each position, try all possible substrings that exist in the dictionary.
4. Recursively build the remaining sentences and combine them with the current word.

## Complexity Analysis

- **Time Complexity:** O(n * m * L) where n is the string length, m is the number of words, and L is the max word length. With memoization, exponential worst case is avoided.
- **Space Complexity:** O(n * k) where k is the number of valid sentences, due to memo storage.

## Accepted Solution Files

| File | Language | Runtime | Memory |
|------|----------|----------|--------|
| 2026-02-12 06.05.56 - Accepted - runtime 0ms - memory 53.5MB.js | JavaScript | 0ms | 53.5MB |

## Best Code Example

```javascript
function wordBreak(s, wordDict) {
    const wordSet = new Set(wordDict);
    const memo = new Map();

    function dfs(start) {
        if (memo.has(start)) return memo.get(start);
        if (start === s.length) return [""];

        const result = [];

        for (let end = start + 1; end <= s.length; end++) {
            const word = s.substring(start, end);

            if (wordSet.has(word)) {
                const subSentences = dfs(end);

                for (const sub of subSentences) {
                    result.push(sub ? word + " " + sub : word);
                }
            }
        }

        memo.set(start, result);
        return result;
    }

    return dfs(0);
}
```