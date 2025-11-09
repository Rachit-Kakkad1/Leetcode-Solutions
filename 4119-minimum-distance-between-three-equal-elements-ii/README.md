# 4119 - Minimum Distance Between Three Equal Elements II

**Difficulty:** Medium

**Link:** [Minimum Distance Between Three Equal Elements II - LeetCode](https://leetcode.com/problems/minimum-distance-between-three-equal-elements-ii/)

## Problem Description

You are given an integer array `nums`.

A tuple `(i, j, k)` of 3 **distinct** indices is **good** if `nums[i] == nums[j] == nums[k]`.

The **distance** of a **good** tuple is `abs(i - j) + abs(j - k) + abs(k - i)`.

Return an integer denoting the **minimum** possible **distance** of a **good** tuple. If no **good** tuples exist, return `-1`.

## Example Test Cases

### Example 1:
```
Input: nums = [1,2,1,1,3]
Output: 6
```

### Example 2:
```
Input: nums = [1,1,2,3,2,1,2]
Output: 8
```

### Example 3:
```
Input: nums = [1]
Output: -1
```

## Constraints

- `1 <= n == nums.length <= 10^5`
- `1 <= nums[i] <= n`

## Solution Approach

### Algorithm Explanation

Same approach as 4115 but optimized for larger input:

1. Group indices by value using hash map
2. For each value with 3+ indices, check consecutive triples
3. Distance formula: 2 × (indices[i+2] - indices[i])

### Complexity Analysis

- **Time Complexity:** O(n)
- **Space Complexity:** O(n)

## Accepted Solutions

| File Name | Language | Runtime | Memory |
|----------|----------|---------|--------|
| 2025-11-09 11.37.14 - Accepted - runtime 699ms - memory 49.9MB.py | Python | 699ms | 49.9MB |
| 2026-04-11 09.36.03 - Accepted - runtime 359ms - memory 343.5MB.cpp | C++ | 359ms | 343.5MB |

## Code Example (C++)

```cpp
class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]].push_back(i);
        }
        
        int ans = INT_MAX;
        for (auto &p : mp) {
            auto &v = p.second;
            if (v.size() < 3) continue;
            for (int i = 0; i + 2 < v.size(); i++) {
                int dist = 2 * (v[i + 2] - v[i]);
                ans = min(ans, dist);
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};
```

**Runtime:** 359ms | **Memory:** 343.5MB