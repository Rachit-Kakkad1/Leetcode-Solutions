# 2271 - Rearrange Array Elements by Sign

**Difficulty:** Medium  
**Problem Link:** [rearrange-array-elements-by-sign](https://leetcode.com/problems/rearrange-array-elements-by-sign/)

## Problem Description

Given a 0-indexed integer array `nums` of even length with equal number of positive and negative integers, return the array where:
1. Every consecutive pair has opposite signs
2. Order of same-sign elements is preserved from original
3. Array begins with a positive integer

## Solution Approach

**Separate and Interleave:**
1. Separate positive and negative numbers into two vectors
2. Maintain original order while extracting
3. Interleave them: positive, negative, positive, negative...

## Complexity Analysis

- **Time Complexity:** O(n)
- **Space Complexity:** O(n)

## Accepted Solutions

| File | Runtime | Memory | Language |
|------|---------|--------|----------|
| 2026-04-10 17.57.52 - Accepted - runtime 8ms - memory 144.9MB.cpp | 8ms | 144.9MB | C++ |

## Best Code Example

```cpp
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> pos, neg;

        for (int x : nums) {
            if (x > 0) pos.push_back(x);
            else neg.push_back(x);
        }

        vector<int> ans;
        int i = 0;
        while (i < pos.size()) {
            ans.push_back(pos[i]);
            ans.push_back(neg[i]);
            i++;
        }

        return ans;
    }
};
```