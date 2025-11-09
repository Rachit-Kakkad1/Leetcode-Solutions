# 4115 - Minimum Distance Between Three Equal Elements I

**Difficulty:** Easy

**Link:** [Minimum Distance Between Three Equal Elements I - LeetCode](https://leetcode.com/problems/minimum-distance-between-three-equal-elements-i/)

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
Explanation: Good tuple (0,2,3), distance = |0-2| + |2-3| + |3-0| = 2+1+3 = 6
```

### Example 2:
```
Input: nums = [1,1,2,3,2,1,2]
Output: 8
Explanation: Good tuple (2,4,6), distance = 2+2+4 = 8
```

### Example 3:
```
Input: nums = [1]
Output: -1
```

## Constraints

- `1 <= n == nums.length <= 100`
- `1 <= nums[i] <= n`

## Solution Approach

### Algorithm Explanation

Group indices by value and find minimum distance using three consecutive indices:

1. Group all indices for each unique value
2. For each value with 3+ indices, consider consecutive triples
3. Distance = 2 × (indices[i+2] - indices[i])
4. Return minimum across all values

### Step-by-Step Logic

1. Build map: value → list of indices
2. For each list with ≥3 elements:
   - Iterate through consecutive triples
   - Calculate distance
   - Track minimum
3. Return min distance or -1

### Why It Works

- For fixed value, adjacent indices minimize the span
- Using three consecutive indices gives the minimum possible distance

## Complexity Analysis

- **Time Complexity:** O(n)
- **Space Complexity:** O(n)

## Accepted Solutions

| File Name | Language | Runtime | Memory |
|----------|----------|---------|--------|
| 2025-11-09 11.30.50 - Accepted - runtime 0ms - memory 12.3MB.py | Python | 0ms | 12.3MB |
| 2026-04-10 09.06.20 - Accepted - runtime 0ms - memory 29.8MB.cpp | C++ | 0ms | 29.8MB |

## Code Example (Best Solution - C++)

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

**Runtime:** 0ms | **Memory:** 29.8MB