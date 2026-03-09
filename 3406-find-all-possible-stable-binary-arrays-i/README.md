# 3406 - Find All Possible Stable Binary Arrays I

**Difficulty:** Medium  
**Problem Link:** [find-all-possible-stable-binary-arrays-i](https://leetcode.com/problems/find-all-possible-stable-binary-arrays-i/)

## Problem Description

Given zero, one, and limit, count stable binary arrays where:
- Exactly zero zeros and one ones
- Every subarray larger than limit contains both 0 and 1

Return count modulo 10^9 + 7.

## Solution Approach

**DP with run-length tracking:**
- dp[i][j][last] = number of arrays with i zeros, j ones, ending with 'last' digit
- Transition: add 1-limit consecutive same digits before switching
- Track run length to ensure no run > limit

## Complexity Analysis

- **Time Complexity:** O(zero * one * limit)
- **Space Complexity:** O(zero * one * 2)

## Accepted Solutions

| File | Runtime | Memory | Language |
|------|---------|--------|----------|
| 2026-03-09 09.48.11 - Accepted - runtime 292ms - memory 61.3MB.js | 292ms | 61.3MB | JavaScript |

## Best Code Example

```javascript
function numberOfStableArrays(zero, one, limit) {
    const MOD = 1e9 + 7;

    const dp = Array.from({ length: zero + 1 }, () =>
        Array.from({ length: one + 1 }, () => [0, 0])
    );

    for (let i = 1; i <= Math.min(limit, zero); i++) dp[i][0][0] = 1;
    for (let j = 1; j <= Math.min(limit, one); j++) dp[0][j][1] = 1;

    for (let i = 0; i <= zero; i++) {
        for (let j = 0; j <= one; j++) {
            if (i > 0) {
                for (let k = 1; k <= limit && i - k >= 0; k++) {
                    dp[i][j][0] = (dp[i][j][0] + dp[i - k][j][1]) % MOD;
                }
            }

            if (j > 0) {
                for (let k = 1; k <= limit && j - k >= 0; k++) {
                    dp[i][j][1] = (dp[i][j][1] + dp[i][j - k][0]) % MOD;
                }
            }
        }
    }

    return (dp[zero][one][0] + dp[zero][one][1]) % MOD;
}
```