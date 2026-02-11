# 34 - Find First and Last Position of Element in Sorted Array

**Difficulty:** Medium  
**Problem Link:** [find-first-and-last-position-of-element-in-sorted-array](https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/)

## Problem Description

Given a sorted array `nums`, find the starting and ending position of a given `target` value. If `target` is not found, return `[-1, -1]`. Must use O(log n) runtime complexity.

## Solution Approach

**Binary Search for Boundaries:**
1. Use binary search twice: once to find first position, once for last
2. When target is found, continue searching in appropriate direction
3. For first position: continue searching left
4. For last position: continue searching right

## Complexity Analysis

- **Time Complexity:** O(log n)
- **Space Complexity:** O(1)

## Accepted Solutions

| File | Runtime | Memory | Language |
|------|---------|--------|----------|
| 2026-02-11 10.34.48 - Accepted - runtime 2ms - memory 54.5MB.js | 2ms | 54.5MB | JavaScript |
| 2026-02-11 10.36.40 - Accepted - runtime 0ms - memory 54.6MB.js | 0ms | 54.6MB | JavaScript |

## Best Code Example

```javascript
function searchRange(nums, target) {
    function boundary(isFirst) {
        let left = 0, right = nums.length - 1;
        let ans = -1;

        while (left <= right) {
            const mid = Math.floor((left + right) / 2);

            if (nums[mid] === target) {
                ans = mid;
                isFirst ? right = mid - 1 : left = mid + 1;
            } 
            else if (nums[mid] < target) {
                left = mid + 1;
            } 
            else {
                right = mid - 1;
            }
        }
        return ans;
    }

    return [boundary(true), boundary(false)];
}
```