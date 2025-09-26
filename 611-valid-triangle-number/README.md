# 611 - Valid Triangle Number

**Difficulty:** Medium  
**Problem Link:** [valid-triangle-number](https://leetcode.com/problems/valid-triangle-number/)

## Problem Description

Given an integer array `nums`, return the number of triplets that can form triangles (where sum of two sides is greater than the third side).

## Solution Approach

**Sorted Two Pointer:**
1. Sort the array
2. Fix the largest side (k) and use two pointers for remaining two sides
3. If nums[i] + nums[j] > nums[k], all triplets between i and j are valid

## Complexity Analysis

- **Time Complexity:** O(n^2)
- **Space Complexity:** O(1) excluding sort

## Accepted Solutions

| File | Runtime | Memory | Language |
|------|---------|--------|----------|
| 2025-09-26 11.01.23 - Accepted - runtime 31ms - memory 8.3MB.c | 31ms | 8.3MB | C |
| 2026-03-29 17.09.29 - Accepted - runtime 36ms - memory 9.1MB.c | 36ms | 9.1MB | C |

## Best Code Example

```c
int cmpfunc(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int triangleNumber(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), cmpfunc);  
    int count = 0;

    for (int k = numsSize - 1; k >= 2; k--) {  
        int i = 0, j = k - 1;
        while (i < j) {
            if (nums[i] + nums[j] > nums[k]) {
                count += (j - i);  
                j--;
            } else {
                i++;
            }
        }
    }
    return count;
}
```