# 4030 - Maximize Cyclic Partition Score

**Difficulty:** Hard

**Link:** [Maximize Cyclic Partition Score - LeetCode](https://leetcode.com/problems/maximize-cyclic-partition-score/)

## Problem Description

You are given a **cyclic** array `nums` and an integer `k`.

**Partition** `nums` into **at most** `k` **subarrays**. As `nums` is cyclic, these subarrays may wrap around from the end of the array back to the beginning.

The **range** of a subarray is the difference between its **maximum** and **minimum** values. The **score** of a partition is the sum of subarray **ranges**.

Return the **maximum** possible **score** among all cyclic partitions.

## Example Test Cases

### Example 1:
```
Input: nums = [1,2,3,3], k = 2
Output: 3
Explanation: Partition into [2,3] (range=1) and [3,1] (range=2), score=3
```

### Example 2:
```
Input: nums = [1,2,3,3], k = 1
Output: 2
Explanation: Full array [1,2,3,3], range=3-1=2
```

### Example 3:
```
Input: nums = [1,2,3,3], k = 4
Output: 3
```

## Constraints

- `1 <= nums.length <= 1000`
- `1 <= nums[i] <= 10^9`
- `1 <= k <= nums.length`

## Solution Approach

### Algorithm Explanation

This problem has no accepted solution in the folder. The general approach would involve:

1. Since array is cyclic, duplicate nums to handle wrap-around
2. Find optimal partition points to maximize sum of ranges
3. Use dynamic programming similar topartition array problems

### Complexity Analysis

- **Time Complexity:** O(n² × k) typical
- **Space Complexity:** O(n × k)

## Accepted Solutions

No accepted solutions found in this folder.

## Status

Awaiting solution implementation.