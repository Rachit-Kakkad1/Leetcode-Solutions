# 139 - Word Break

**Difficulty:** Medium

**Link:** [Word Break - LeetCode](https://leetcode.com/problems/word-break/)

## Problem Description

Given a string `s` and a dictionary of strings `wordDict`, return `true` if `s` can be segmented into a space-separated sequence of one or more dictionary words.

**Note** that the same word in the dictionary may be reused multiple times in the segmentation.

## Example Test Cases

### Example 1:
```
Input: s = "leetcode", wordDict = ["leet","code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".
```

### Example 2:
```
Input: s = "applepenapple", wordDict = ["apple","pen"]
Output: true
Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
```

### Example 3:
```
Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
Output: false
```

## Constraints

- `1 <= s.length <= 300`
- `1 <= wordDict.length <= 1000`
- `1 <= wordDict[i].length <= 20`
- `s` and `wordDict[i]` consist of only lowercase English letters.
- All the strings of `wordDict` are **unique**.

## Solution Approach

### Algorithm Explanation

Use **dynamic programming** with a set for O(1) lookups:

1. Create a set from wordDict for fast membership checking
2. dp[i] represents whether s[0...i] can be segmented
3. For each position i, check all possible previous positions j
4. If dp[j] is true and substring s[j...i) is in dictionary, mark dp[i] as true

### Step-by-Step Logic

1. Create set from wordDict
2. Initialize dp array of size n+1 with false, dp[0] = true
3. For each i from 1 to n:
   - For each j from 0 to i-1:
     - If dp[j] is true and s.substring(j, i) in set: dp[i] = true, break
4. Return dp[n]

### Why It Works

- dp[j] correctly captures if prefix s[0...j) is segmentable
- Checking all j values finds all possible word boundaries
- Set provides O(1) dictionary word lookup

## Complexity Analysis

- **Time Complexity:** O(n² * m) where n = s.length, m = avg word length
- **Space Complexity:** O(n + k) where k = total characters in dictionary

## Accepted Solutions

| File Name | Language | Runtime | Memory |
|-----------|----------|---------|--------|
| 2026-02-12 06.05.02 - Accepted - runtime 6ms - memory 55.3MB.js | JavaScript | 6ms | 55.3MB |

## Code Example (Best Solution - JavaScript)

```javascript
/**
 * @param {string} s
 * @param {string[]} wordDict
 * @return {boolean}
 */
function wordBreak(s, wordDict) {
    const wordSet = new Set(wordDict);
    const n = s.length;

    const dp = new Array(n + 1).fill(false);
    dp[0] = true;

    for (let i = 1; i <= n; i++) {
        for (let j = 0; j < i; j++) {
            if (dp[j] && wordSet.has(s.substring(j, i))) {
                dp[i] = true;
                break;
            }
        }
    }

    return dp[n];
}
```

**Runtime:** 6ms | **Memory:** 55.3MB