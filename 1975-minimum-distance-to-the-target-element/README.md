# 1975. Minimum Distance to the Target Element

**Difficulty: Easy**

## Problem Description

Given an array of integers `nums`, an integer `target`, and an integer `start`, return the minimum distance to the target element.

Return the minimum index `i` such that `abs(i - start)` is minimized. If there are multiple occurrences, return the smallest index.

**Example 1:**
```
Input: nums = [1,2,3,4,5], target = 5, start = 3
Output: 1
Explanation: Position 4 has value 5, which is 1 index away from start position 3.
```

**Example 2:**
```
Input: nums = [1,1,1,1,1,1], target = 1, start = 0
Output: 0
```

**Constraints:**
* `1 <= nums.length <= 10^4`
* `1 <= nums[i] <= 10^4`
* `1 <= target <= 10^4`
* `0 <= start < nums.length`

## Solution Approach

We use a simple linear scan:
1. Initialize answer to infinity.
2. Iterate through all indices.
3. When we find the target, calculate the absolute distance.
4. Keep the minimum distance found.

## Complexity Analysis

- **Time Complexity:** O(n) where n is the array length.
- **Space Complexity:** O(1).

## Accepted Solution Files

| File | Language | Runtime | Memory |
|------|----------|----------|--------|
| 2026-04-13 08.48.59 - Accepted - runtime 0ms - memory 13.3MB.cpp | C++ | 0ms | 13.3MB |

## Best Code Example

```cpp
class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int ans = INT_MAX;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == target) {
                ans = min(ans, abs(i - start));
            }
        }

        return ans;
    }
};
```