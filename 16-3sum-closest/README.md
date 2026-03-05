# 16 - 3Sum Closest

**Difficulty:** Medium

**Link:** [3Sum Closest - LeetCode](https://leetcode.com/problems/3sum-closest/)

## Problem Description

Given an integer array `nums` of length `n` and an integer `target`, find three integers at **distinct indices** in `nums` such that the sum is closest to `target`.

Return *the sum of the three integers*.

You may assume that each input would have exactly one solution.

## Example Test Cases

### Example 1:
```
Input: nums = [-1,2,1,-4], target = 1
Output: 2
Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
```

### Example 2:
```
Input: nums = [0,0,0], target = 1
Output: 0
Explanation: The sum that is closest to the target is 0. (0 + 0 + 0 = 0).
```

## Constraints

- `3 <= nums.length <= 500`
- `-1000 <= nums[i] <= 1000`
- `-10^4 <= target <= 10^4`

## Solution Approach

### Algorithm Explanation

Use **two-pointer** technique after sorting:

1. Sort the array
2. For each element, use two pointers to find best pair
3. Track closest sum to target
4. If exact match found, return immediately

### Step-by-Step Logic

1. Sort nums
2. Initialize closestSum with first three elements
3. For each i from 0 to n-3:
   - Set left = i+1, right = n-1
   - While left < right:
     - Calculate currentSum = nums[i] + nums[left] + nums[right]
     - Update closestSum if currentSum is closer to target
     - Move pointers based on comparison with target
4. Return closestSum

### Why It Works

- Sorting enables two-pointer narrowing
- Each iteration explores all valid triplet combinations
- Early termination on exact match

## Complexity Analysis

- **Time Complexity:** O(n²) - Sort O(n log n) + nested two-pointer loops
- **Space Complexity:** O(1) - In-place sorting or O(log n) for sort

## Accepted Solutions

| File Name | Language | Runtime | Memory |
|-----------|----------|---------|--------|
| 2026-03-06 02.00.32 - Accepted - runtime 14ms - memory 55.6MB.js | JavaScript | 14ms | 55.6MB |

## Code Example (Best Solution - JavaScript)

```javascript
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
function threeSumClosest(nums, target) {
    nums.sort((a, b) => a - b);

    let closestSum = nums[0] + nums[1] + nums[2];

    for (let i = 0; i < nums.length - 2; i++) {
        let left = i + 1;
        let right = nums.length - 1;

        while (left < right) {
            let currentSum = nums[i] + nums[left] + nums[right];

            if (Math.abs(currentSum - target) < Math.abs(closestSum - target)) {
                closestSum = currentSum;
            }

            if (currentSum < target) {
                left++;
            } else if (currentSum > target) {
                right--;
            } else {
                return currentSum;
            }
        }
    }

    return closestSum;
}
```

**Runtime:** 14ms | **Memory:** 55.6MB