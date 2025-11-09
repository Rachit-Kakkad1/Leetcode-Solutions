# 3986 - Maximum Path Score in a Grid

**Difficulty:** Medium

**Link:** [Maximum Path Score in a Grid - LeetCode](https://leetcode.com/problems/maximum-path-score-in-a-grid/)

## Problem Description

You are given an `m x n` grid where each cell contains one of the values 0, 1, or 2. You are also given an integer `k`.

You start from the top-left corner `(0, 0)` and want to reach the bottom-right corner `(m - 1, n - 1)` by moving only **right** or **down**.

Each cell contributes a specific score and incurs an associated cost:

- 0: adds 0 to score, costs 0
- 1: adds 1 to score, costs 1
- 2: adds 2 to score, costs 1

Return the **maximum** score achievable without exceeding total cost `k`, or -1 if no valid path exists.

## Example Test Cases

### Example 1:
```
Input: grid = [[0, 1],[2, 0]], k = 1
Output: 2
Path: (0,0)→(1,0)→(1,1): score=2+0=2, cost=1
```

### Example 2:
```
Input: grid = [[0, 1],[1, 2]], k = 1
Output: -1
```

## Constraints

- `1 <= m, n <= 200`
- `0 <= k <= 10^3`
- `grid[0][0] == 0`
- `0 <= grid[i][j] <= 2`

## Solution Approach

### Algorithm Explanation

Dynamic programming with cost dimension:

1. DP[i][j][used] = max score reaching cell (i,j) with exactly used cost
2. Transition from top or left cell
3. For each cell, consider all cost combinations
4. Track maximum score at destination within budget k

### Step-by-Step Logic

1. Initialize dp array: dp[j][cost] = max score at column j with cost
2. Process first row (only right moves)
3. Process remaining rows (from top or left)
4. Return maximum score at destination

### Complexity Analysis

- **Time Complexity:** O(m × n × k)
- **Space Complexity:** O(n × k)

## Accepted Solutions

| File Name | Language | Runtime | Memory |
|----------|----------|---------|--------|
| 2025-11-09 11.44.55 - Accepted - runtime 12189ms - memory 14.1MB.py | Python | 12189ms | 14.1MB |

## Code Example (Best Solution - Python)

```python
class Solution(object):
    def maxPathScore(self, grid, k):
        m, n = len(grid), len(grid[0])
        def cost(v):
            return 0 if v == 0 else 1
        def score(v):
            return v
        dp = [[-1] * (k + 1) for _ in range(n)]
        dp[0][0] = 0
        cc, ss = cost(grid[0][0]), score(grid[0][0])
        if cc <= k:
            dp[0][cc] = ss
        for j in range(1, n):
            val = grid[0][j]
            cc, ss = cost(val), score(val)
            for used in range(cc, k + 1):
                if dp[j - 1][used - cc] != -1:
                    dp[j][used] = max(dp[j][used], dp[j - 1][used - cc] + ss)
        for i in range(1, m):
            new_dp = [[-1] * (k + 1) for _ in range(n)]
            for j in range(n):
                val = grid[i][j]
                cc, ss = cost(val), score(val)
                for used in range(cc, k + 1):
                    best_prev = -1
                    if dp[j][used - cc] != -1:
                        best_prev = max(best_prev, dp[j][used - cc])
                    if j > 0 and new_dp[j - 1][used - cc] != -1:
                        best_prev = max(best_prev, new_dp[j - 1][used - cc])
                    if best_prev != -1:
                        new_dp[j][used] = max(new_dp[j][used], best_prev + ss)
            dp = new_dp
        ans = max(dp[n - 1])
        return ans if ans != -1 else -1
```

**Runtime:** 12189ms | **Memory:** 14.1MB