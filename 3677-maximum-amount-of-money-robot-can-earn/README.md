# 3677 - Maximum Amount of Money Robot Can Earn

**Difficulty:** Medium  
**Problem Link:** [maximum-amount-of-money-robot-can-earn](https://leetcode.com/problems/maximum-amount-of-money-robot-can-earn/)

## Problem Description

A robot moves from (0,0) to (m-1, n-1), moving only right or down. Each cell has coins (positive = gain, negative = robbery). The robot can neutralize at most 2 robbers. Find maximum profit.

## Solution Approach

**3D DP:**
- dp[i][j][k] = max coins at (i,j) using k neutralizations (0, 1, or 2)
- Transition: from top or left cell
- If cell is negative and k > 0, can neutralize (add 0 instead of negative value)
- Track minimum value as -10^18 for invalid states

## Complexity Analysis

- **Time Complexity:** O(m * n * 3)
- **Space Complexity:** O(m * n * 3)

## Accepted Solutions

| File | Runtime | Memory | Language |
|------|---------|--------|----------|
| 2026-04-02 15.04.39 - Accepted - runtime 4800ms - memory 71.3MB.py | 4800ms | 71.3MB | Python |

## Best Code Example

```python
class Solution:
    def maximumAmount(self, coins):
        m, n = len(coins), len(coins[0])
        
        dp = [[[-10**18] * 3 for _ in range(n)] for _ in range(m)]
        
        
        for k in range(3):
            if coins[0][0] >= 0:
                dp[0][0][k] = coins[0][0]
            else:
                if k > 0:
                    dp[0][0][k] = 0
                dp[0][0][0] = coins[0][0]
        
        for i in range(m):
            for j in range(n):
                if i == 0 and j == 0:
                    continue
                
                for k in range(3):
                    best = -10**18
                    
                    if i > 0:
                        best = max(best, dp[i-1][j][k])
                    if j > 0:
                        best = max(best, dp[i][j-1][k])
                    
                    if best != -10**18:
                        dp[i][j][k] = max(dp[i][j][k], best + coins[i][j])
                    
                    if coins[i][j] < 0 and k > 0:
                        best_prev = -10**18
                        
                        if i > 0:
                            best_prev = max(best_prev, dp[i-1][j][k-1])
                        if j > 0:
                            best_prev = max(best_prev, dp[i][j-1][k-1])
                        
                        if best_prev != -10**18:
                            dp[i][j][k] = max(dp[i][j][k], best_prev)
        
        return max(dp[m-1][n-1])
```