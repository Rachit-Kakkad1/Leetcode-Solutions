# 31 - Next Permutation

**Difficulty:** Medium  
**Problem Link:** [next-permutation](https://leetcode.com/problems/next-permutation/)

## Problem Description

A permutation of an array of integers is an arrangement of its members into a sequence or linear order.

The next permutation of an array is the next lexicographically greater permutation. If such arrangement is not possible, the array must be rearranged as the lowest possible order (i.e., sorted in ascending order).

The replacement must be in place and use only constant extra memory.

## Solution Approach

**Three-step Algorithm:**
1. Find the first decreasing element from the right (pivot)
2. Find the smallest element greater than pivot from the right
3. Swap them and reverse the suffix after pivot

## Complexity Analysis

- **Time Complexity:** O(n) where n = array length
- **Space Complexity:** O(1)

## Accepted Solutions

| File | Runtime | Memory | Language |
|------|---------|--------|----------|
| 2026-03-06 18.19.26 - Accepted - runtime 0ms - memory 54.7MB.js | 0ms | 54.7MB | JavaScript |

## Best Code Example

```javascript
function nextPermutation(nums) {
    let n = nums.length;
    let i = n - 2;

    while (i >= 0 && nums[i] >= nums[i + 1]) {
        i--;
    }

    if (i >= 0) {
        let j = n - 1;
        while (nums[j] <= nums[i]) {
            j--;
        }

        let temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }

    let left = i + 1;
    let right = n - 1;

    while (left < right) {
        let temp = nums[left];
        nums[left] = nums[right];
        nums[right] = temp;
        left++;
        right--;
    }
}
```