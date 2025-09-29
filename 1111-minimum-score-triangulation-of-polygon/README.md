# 1111 - Minimum Score Triangulation of Polygon

**Difficulty:** Medium

**Link:** [Minimum Score Triangulation of Polygon - LeetCode](https://leetcode.com/problems/minimum-score-triangulation-of-polygon/)

## Problem Description

You have a convex `n`-sided polygon where each vertex has an integer value. You are given an integer array `values` where `values[i]` is the value of the i-th vertex in **clockwise order**.

**Polygon triangulation** is a process where you divide a polygon into a set of triangles and the vertices of each triangle must also be vertices of the original polygon.

You will **triangulate** the polygon. For each triangle, the *weight* of that triangle is the product of the values at its vertices. The total score of the triangulation is the sum of these *weights* over all `n - 2` triangles.

Return the *minimum possible score* that you can achieve with some **triangulation** of the polygon.

## Example Test Cases

### Example 1:
```
Input: values = [1,2,3]
Output: 6
Explanation: The polygon is already triangulated, and the score of the only triangle is 6.
```

### Example 2:
```
Input: values = [3,7,4,5]
Output: 144
Explanation: There are two triangulations, with possible scores: 3*7*5 + 4*5*7 = 245, or 3*4*5 + 3*4*7 = 144.
The minimum score is 144.
```

### Example 3:
```
Input: values = [1,3,1,4,1,5]
Output: 13
Explanation: The minimum score triangulation is 1*1*3 + 1*1*4 + 1*1*5 + 1*1*1 = 13.
```

## Constraints

- `n == values.length`
- `3 <= n <= 50`
- `1 <= values[i] <= 100`

## Solution Approach

### Algorithm Explanation

Use **dynamic programming** to find minimum score:

1. dp[i][j] = minimum score to triangulate polygon from vertex i to j
2. For each sub-polygon length >= 3, try all possible triangles
3. The cost of adding a triangle (i, k, j) is values[i] * values[k] * values[j]

### Step-by-Step Logic

1. Initialize dp matrix
2. For each length from 3 to n:
   - For each starting vertex i:
     - j = i + length - 1 (ending vertex)
     - dp[i][j] = infinity
     - For each possible k between i+1 and j-1:
       - dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + values[i]*values[k]*values[j])
3. Return dp[0][n-1]

### Why It Works

- The problem has optimal substructure: optimal triangulation of whole polygon contains optimal triangulations of sub-polygons
- We consider all possible triangles and pick minimum cost combination

## Complexity Analysis

- **Time Complexity:** O(n³) - Three nested loops
- **Space Complexity:** O(n²) - DP table

## Accepted Solutions

| File Name | Language | Runtime | Memory |
|-----------|----------|---------|--------|
| 2025-09-29 09.59.23 - Accepted - runtime 41ms - memory 17.7MB.py | Python | 41ms | 17.7MB |

## Code Example (Best Solution - Python)

```python
class Solution:
    def minScoreTriangulation(self, values):
        n = len(values)
        dp = [[0] * n for _ in range(n)]
        
        # length of the sub-polygon (at least 3 vertices to form a triangle)
        for length in range(3, n + 1):
            for i in range(n - length + 1):
                j = i + length - 1
                dp[i][j] = float("inf")
                for k in range(i + 1, j):
                    dp[i][j] = min(
                        dp[i][j],
                        dp[i][k] + dp[k][j] + values[i] * values[j] * values[k]
                    )
        
        return dp[0][n - 1]
```

**Runtime:** 41ms | **Memory:** 17.7MB