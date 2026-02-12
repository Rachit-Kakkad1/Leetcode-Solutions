# 132 - Palindrome Partitioning II

**Difficulty:** Hard

**Link:** [Palindrome Partitioning II - LeetCode](https://leetcode.com/problems/palindrome-partitioning-ii/)

## Problem Description

Given a string `s`, partition `s` such that every substring of the partition is a **palindrome**.

Return *the **minimum** cuts needed for a palindrome partitioning of* `s`.

## Example Test Cases

### Example 1:
```
Input: s = "aab"
Output: 1
Explanation: The palindrome partitioning ["aa","b"] could be produced using 1 cut.
```

### Example 2:
```
Input: s = "a"
Output: 0
```

### Example 3:
```
Input: s = "ab"
Output: 1
```

## Constraints

- `1 <= s.length <= 2000`
- `s` consists of lowercase English letters only.

## Solution Approach

### Algorithm Explanation

Use **dynamic programming** with two arrays:

1. `dp[i]` - minimum cuts needed for substring s[0...i]
2. `isPal[j][i]` - whether substring s[j...i] is a palindrome

Build the palindrome table first, then compute minimum cuts.

### Step-by-Step Logic

1. Initialize `dp[i] = i` (maximum cuts is i for i+1 chars)
2. Build `isPal` table using DP:
   - For each pair (j, i), check if s[j] == s[i] and inner substring is palindrome
3. For each position i, check all j from 0 to i:
   - If s[j...i] is palindrome:
     - If j == 0: no cut needed, dp[i] = 0
     - Else: dp[i] = min(dp[i], dp[j-1] + 1)
4. Return dp[n-1]

### Why It Works

- Precomputing palindromes allows O(1) substring palindrome checks
- dp[i] correctly captures minimum cuts for prefix s[0...i]
- Time complexity is O(n²) which works for n <= 2000

## Complexity Analysis

- **Time Complexity:** O(n²) - Building palindrome table and computing dp
- **Space Complexity:** O(n²) - isPal table storage

## Accepted Solutions

| File Name | Language | Runtime | Memory |
|-----------|----------|---------|--------|
| 2026-02-12 06.03.25 - Accepted - runtime 155ms - memory 98.1MB.js | JavaScript | 155ms | 98.1MB |

## Code Example (Best Solution - JavaScript)

```javascript
/**
 * @param {string} s
 * @return {number}
 */
function minCut(s) {
    const n = s.length;

    
    const dp = new Array(n).fill(0);

    
    const isPal = Array.from({ length: n }, () => new Array(n).fill(false));

    for (let i = 0; i < n; i++) {
        dp[i] = i; 

        for (let j = 0; j <= i; j++) {
            if (
                s[i] === s[j] &&
                (i - j <= 2 || isPal[j + 1][i - 1])
            ) {
                isPal[j][i] = true;

                if (j === 0) {
                    dp[i] = 0; 
                } else {
                    dp[i] = Math.min(dp[i], dp[j - 1] + 1);
                }
            }
        }
    }

    return dp[n - 1];
}
```

**Runtime:** 155ms | **Memory:** 98.1MB