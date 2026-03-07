# 209. Minimum Size Subarray Sum

**Difficulty: Medium**

## Problem Description

Given an array of positive integers `nums` and a positive integer `target`, return the minimal length of a subarray whose sum is at least `target`. If there is no such subarray, return 0.

**Example 1:**
```
Input: target = 7, nums = [2,3,1,2,4,2]
Output: 2
Explanation: Subarray [4,2] has sum 7.
```

**Constraints:**
* `1 <= target <= 10^9`
* `1 <= nums.length <= 10^5`
* `1 <= nums[i] <= 10^4`

## Solution Approach

We use the **sliding window** technique:
1. Expand the window by moving right pointer.
2. When sum >= target, shrink from left.
3. Track minimum length.

## Complexity Analysis

- **Time Complexity:** O(n) - each element is visited at most twice.
- **Space Complexity:** O(1).

## Accepted Solution Files

| File | Language | Runtime | Memory |
|------|----------|----------|--------|
| 2026-03-07 15.47.59 - Accepted - runtime 3ms - memory 60MB.js | JavaScript | 3ms | 60MB |

## Best Code Example

```javascript
function minSubArrayLen(target, nums) {
    let left = 0;
    let sum = 0;
    let minLen = Infinity;

    for (let right = 0; right < nums.length; right++) {
        sum += nums[right];

        while (sum >= target) {
            minLen = Math.min(minLen, right - left + 1);
            sum -= nums[left];
            left++;
        }
    }

    return minLen === Infinity ? 0 : minLen;
}
```