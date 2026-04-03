# 2048 - Build Array from Permutation

**Difficulty:** Easy  
**Problem Link:** [build-array-from-permutation](https://leetcode.com/problems/build-array-from-permutation/)

## Problem Description

Given a zero-based permutation `nums`, build an array `ans` where `ans[i] = nums[nums[i]]` for each 0 <= i < nums.length.

## Solution Approach

**Direct Indexing:**
1. Iterate through each index
2. For each i, get nums[i], then use that as index to get nums[nums[i]]
3. Build result array

## Complexity Analysis

- **Time Complexity:** O(n)
- **Space Complexity:** O(n)

## Accepted Solutions

| File | Runtime | Memory | Language |
|------|---------|--------|----------|
| 2026-04-03 22.55.50 - Accepted - runtime 0ms - memory 21MB.cpp | 0ms | 21MB | C++ |

## Best Code Example

```cpp
class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        vector<int> ans;
        
        for (int i = 0; i < nums.size(); i++) {
            ans.push_back(nums[nums[i]]);
        }
        
        return ans;
    }
};
```