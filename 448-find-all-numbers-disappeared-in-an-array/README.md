# 448 - Find All Numbers Disappeared in an Array

**Difficulty:** Easy  
**Problem Link:** [find-all-numbers-disappeared-in-an-array](https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/)

## Problem Description

Given an array `nums` of `n` integers where `nums[i]` is in range `[1, n]`, return all integers in `[1, n]` that do not appear in `nums`.

## Solution Approach

**In-place Marking:**
1. For each element, mark its corresponding index as negative (if not already)
2. Use absolute value to handle already marked elements
3. Second pass: collect all indices with positive values (+1 for number)

## Complexity Analysis

- **Time Complexity:** O(n)
- **Space Complexity:** O(1) excluding output

## Accepted Solutions

| File | Runtime | Memory | Language |
|------|---------|--------|----------|
| 2026-02-17 13.59.20 - Accepted - runtime 6ms - memory 71MB.js | 6ms | 71MB | JavaScript |

## Best Code Example

```javascript
function findDisappearedNumbers(nums) {
    const result = [];

    for (let i = 0; i < nums.length; i++) {
        const index = Math.abs(nums[i]) - 1;

        if (nums[index] > 0) {
            nums[index] = -nums[index];
        }
    }

    for (let i = 0; i < nums.length; i++) {
        if (nums[i] > 0) {
            result.push(i + 1);
        }
    }

    return result;
}
```