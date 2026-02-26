# 2480 - Find Subarrays With Equal Sum

**Difficulty:** Easy  
**Problem Link:** [find-subarrays-with-equal-sum](https://leetcode.com/problems/find-subarrays-with-equal-sum/)

## Problem Description

Given an integer array `nums`, determine whether there exist two subarrays of length 2 with equal sum. Note that the two subarrays must begin at different indices.

## Solution Approach

**Brute Force Comparison:**
1. Calculate sum of each pair of consecutive elements
2. Compare each sum with all subsequent sums
3. Return true if any two sums match

## Complexity Analysis

- **Time Complexity:** O(n^2) in worst case
- **Space Complexity:** O(1)

## Accepted Solutions

| File | Runtime | Memory | Language |
|------|---------|--------|----------|
| 2026-02-26 18.32.59 - Accepted - runtime 0ms - memory 10.7MB.cpp | 0ms | 10.7MB | C++ |
| 2026-02-26 18.35.58 - Accepted - runtime 0ms - memory 53.7MB.js | 0ms | 53.7MB | JavaScript |

## Best Code Example

```javascript
function findSubarrays(nums) {
    for (let i = 0; i < nums.length - 1; i++) {
        let sum1 = nums[i] + nums[i + 1];
        
        for (let j = i + 1; j < nums.length - 1; j++) {
            let sum2 = nums[j] + nums[j + 1];
            
            if (sum1 === sum2) {
                return true;
            }
        }
    }
    
    return false;
}
```