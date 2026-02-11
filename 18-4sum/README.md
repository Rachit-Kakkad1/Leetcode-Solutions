# 18. 4Sum

**Difficulty: Medium**

## Problem Description

Given an array `nums` of integers and a target, return all unique quadruplets `[nums[a], nums[b], nums[c], nums[d]]` such that they sum to the target.

Notice that the solution set must not contain duplicate quadruplets.

**Example 1:**
```
Input: nums = [1,0,-1,0,-2,2], target = 0
Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
```

**Constraints:**
* `3 <= nums.length <= 200`
* `-10^9 <= nums[i] <= 10^9`
* `-10^9 <= target <= 10^9`

## Solution Approach

This extends the 3Sum solution with an extra loop:
1. Sort the array.
2. Use two nested loops for the first two numbers.
3. Use two pointers for the remaining two numbers.
4. Skip duplicates at each level.

## Complexity Analysis

- **Time Complexity:** O(n³) - two nested loops plus two-pointer technique.
- **Space Complexity:** O(1) excluding output space.

## Accepted Solution Files

| File | Language | Runtime | Memory |
|------|----------|----------|--------|
| 2026-02-11 10.52.26 - Accepted - runtime 16ms - memory 56.8MB.js | JavaScript | 16ms | 56.8MB |

## Best Code Example

```javascript
function fourSum(nums, target) {
    nums.sort((a, b) => a - b);
    const result = [];
    const n = nums.length;

    for (let i = 0; i < n - 3; i++) {
        if (i > 0 && nums[i] === nums[i - 1]) continue;

        for (let j = i + 1; j < n - 2; j++) {
            if (j > i + 1 && nums[j] === nums[j - 1]) continue;

            let left = j + 1;
            let right = n - 1;

            while (left < right) {
                const sum = nums[i] + nums[j] + nums[left] + nums[right];

                if (sum === target) {
                    result.push([nums[i], nums[j], nums[left], nums[right]]);
                    while (left < right && nums[left] === nums[left + 1]) left++;
                    while (left < right && nums[right] === nums[right - 1]) right--;
                    left++;
                    right--;
                }
                else if (sum < target) {
                    left++;
                }
                else {
                    right--;
                }
            }
        }
    }

    return result;
}
```