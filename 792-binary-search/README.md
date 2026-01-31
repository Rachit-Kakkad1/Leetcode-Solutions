# 792 - Binary Search

**Difficulty:** Easy  
**Problem Link:** [binary-search](https://leetcode.com/problems/binary-search/)

## Problem Description

Given a sorted array of integers `nums` and an integer `target`, search for `target` in `nums`. Return its index if found, otherwise return -1. Must use O(log n) runtime complexity.

## Solution Approach

**Standard Binary Search:**
1. Set left = 0, right = length - 1
2. While left <= right:
   - Calculate mid = (left + right) / 2
   - If nums[mid] == target, return mid
   - If nums[mid] < target, search right half
   - Otherwise search left half
3. Return -1 if not found

## Complexity Analysis

- **Time Complexity:** O(log n)
- **Space Complexity:** O(1)

## Accepted Solutions

| File | Runtime | Memory | Language |
|------|---------|--------|----------|
| 2026-01-31 15.01.52 - Accepted - runtime 0ms - memory 58.1MB.js | 0ms | 58.1MB | JavaScript |

## Best Code Example

```javascript
function search(nums, target) {
    let left = 0;
    let right = nums.length - 1;

    while (left <= right) {
        const mid = Math.floor((left + right) / 2);

        if (nums[mid] === target) {
            return mid;
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1;
}
```