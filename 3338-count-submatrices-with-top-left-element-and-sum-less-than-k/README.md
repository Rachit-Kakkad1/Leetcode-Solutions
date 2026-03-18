# 3338 - Count Submatrices with Top-Left Element and Sum Less Than k

**Difficulty:** Medium  
**Problem Link:** [count-submatrices-with-top-left-element-and-sum-less-than-k](https://leetcode.com/problems/count-submatrices-with-top-left-element-and-sum-less-than-k/)

## Problem Description

Given a 0-indexed integer matrix `grid` and an integer `k`, return the number of submatrices that contain the top-left element of the grid and have a sum less than or equal to `k`.

## Solution Approach

**Prefix Sum Array:**
1. Build 2D prefix sum for the matrix
2. For each cell (i, j), calculate sum of submatrix from (0, 0) to (i, j)
3. If prefix sum <= k, increment count

## Complexity Analysis

- **Time Complexity:** O(m * n) where m, n are matrix dimensions
- **Space Complexity:** O(m * n) for prefix sum

## Accepted Solutions

| File | Runtime | Memory | Language |
|------|---------|--------|----------|
| 2026-03-18 13.52.25 - Accepted - runtime 11ms - memory 110.1MB.cpp | 11ms | 110.1MB | C++ |
| 2026-03-18 14.04.23 - Accepted - runtime 451ms - memory 46.5MB.py | 451ms | 46.5MB | Python |

## Best Code Example

```cpp
class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<long long>> prefix(m, vector<long long>(n, 0));
        int count = 0;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                prefix[i][j] = grid[i][j];
                
                if (i > 0) prefix[i][j] += prefix[i - 1][j];
                if (j > 0) prefix[i][j] += prefix[i][j - 1];
                if (i > 0 && j > 0) prefix[i][j] -= prefix[i - 1][j - 1];
                
                if (prefix[i][j] <= k) count++;
            }
        }
        
        return count;
    }
};
```