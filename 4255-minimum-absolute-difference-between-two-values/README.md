# 4255 - Minimum Absolute Difference Between Two Values

**Difficulty:** Easy

**Link:** [Minimum Absolute Difference Between Two Values - LeetCode](https://leetcode.com/problems/minimum-absolute-difference-between-two-values/)

## Problem Description

You are given an integer array `nums` consisting only of 0, 1, and 2.

A pair of indices `(i, j)` is called **valid** if `nums[i] == 1` and `nums[j] == 2`.

Return the **minimum** absolute difference between `i` and `j` among all valid pairs. If no valid pair exists, return -1.

## Example Test Cases

### Example 1:
```
Input: nums = [1,0,0,2,0,1]
Output: 2
Explanation: Valid pairs: (0,3) diff=3, (5,3) diff=2 → minimum is 2
```

### Example 2:
```
Input: nums = [1,0,1,0]
Output: -1
Explanation: No 2 in array
```

## Constraints

- `1 <= nums.length <= 100`
- `0 <= nums[i] <= 2`

## Solution Approach

### Algorithm Explanation

Two-pointer technique on sorted indices:

1. Separate indices of 1s and 2s into two lists
2. Use two pointers to find minimum difference
3. Move the pointer with smaller index forward

### Step-by-Step Logic

1. Collect indices of 1s and 2s
2. Edge case: if either list is empty, return -1
3. Two-pointer traversal:
   - Calculate abs difference
   - Move smaller index forward

### Why It Works

- Both lists are sorted (by insertion order)
- At each step, moving smaller index can only potentially reduce difference

## Complexity Analysis

- **Time Complexity:** O(n)
- **Space Complexity:** O(n)

## Accepted Solutions

| File Name | Language | Runtime | Memory |
|----------|----------|---------|--------|
| 2026-04-10 17.35.34 - Accepted - runtime 0ms - memory 26.2MB.cpp | C++ | 0ms | 26.2MB |

## Code Example (C++)

```cpp
class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums) {
        vector<int> ones, twos;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) ones.push_back(i);
            else if (nums[i] == 2) twos.push_back(i);
        }

        if (ones.empty() || twos.empty()) return -1;

        int i = 0, j = 0;
        int ans = INT_MAX;

        while (i < ones.size() && j < twos.size()) {
            ans = min(ans, abs(ones[i] - twos[j]));

            if (ones[i] < twos[j]) i++;
            else j++;
        }

        return ans;
    }
};
```

**Runtime:** 0ms | **Memory:** 26.2MB