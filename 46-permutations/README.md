# 46 - Permutations

**Difficulty:** Medium  
**Problem Link:** [permutations](https://leetcode.com/problems/permutations/)

## Problem Description

Given an array `nums` of distinct integers, return all the possible permutations. You can return the answer in any order.

## Solution Approach

**Backtracking:**
1. Use recursion with a path (current permutation)
2. Track used elements with a boolean array
3. For each position, try each unused element
4. Backtrack by removing the element from path
5. Base case: when path length equals nums length

## Complexity Analysis

- **Time Complexity:** O(n * n!) where n = array length
- **Space Complexity:** O(n) for recursion stack and used array

## Accepted Solutions

| File | Runtime | Memory | Language |
|------|---------|--------|----------|
| 2026-03-09 10.03.55 - Accepted - runtime 0ms - memory 60MB.js | 0ms | 60MB | JavaScript |

## Best Code Example

```javascript
function permute(nums) {
    const res = [];
    const used = new Array(nums.length).fill(false);

    function backtrack(path) {
        if (path.length === nums.length) {
            res.push([...path]);
            return;
        }

        for (let i = 0; i < nums.length; i++) {
            if (used[i]) continue;

            used[i] = true;
            path.push(nums[i]);

            backtrack(path);

            path.pop();
            used[i] = false;
        }
    }

    backtrack([]);
    return res;
}
```