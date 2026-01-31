# 349 - Intersection of Two Arrays

**Difficulty:** Easy

**Link:** [Intersection of Two Arrays - LeetCode](https://leetcode.com/problems/intersection-of-two-arrays/)

## Problem Description

Given two integer arrays `nums1` and `nums2`, return *an array of their intersection*. Each element in the result must be **unique** and you may return the result in **any order**.

## Example Test Cases

### Example 1:
```
Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2]
```

### Example 2:
```
Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [9,4]
Explanation: [4,9] is also accepted.
```

## Constraints

- `1 <= nums1.length, nums2.length <= 1000`
- `0 <= nums1[i], nums2[i] <= 1000`

## Solution Approach

### Algorithm Explanation

Use hash sets for efficient O(n) time complexity:

1. Convert the smaller array to a set for O(1) lookups
2. Iterate through the other array and collect elements that exist in the set
3. Use set comprehension to ensure uniqueness

### Step-by-Step Logic

1. If nums1 is longer than nums2, swap to use smaller as base
2. Convert nums1 to a set for O(1) membership checking
3. Use set comprehension to find elements in nums2 that exist in set1
4. Return as list

### Why It Works

- Set provides O(1) lookup instead of O(n) with array
- Set comprehension automatically handles duplicates
- Result can be in any order, so we don't need to sort

## Complexity Analysis

- **Time Complexity:** O(n + m) - Each element processed once
- **Space Complexity:** O(min(n, m)) - Set size bounded by smaller array

## Accepted Solutions

| File Name | Language | Runtime | Memory |
|-----------|----------|---------|--------|
| 2026-01-31 13.49.26 - Accepted - runtime 3ms - memory 12.7MB.py | Python | 3ms | 12.7MB |
| 2026-01-31 13.52.09 - Accepted - runtime 5ms - memory 12.6MB.py | Python | 5ms | 12.6MB |
| 2026-01-31 13.56.45 - Accepted - runtime 0ms - memory 12.7MB.py | Python | 0ms | 12.7MB |

## Code Example (Best Solution - Python)

```python
class Solution:
    def intersection(self, nums1, nums2):
        if len(nums1) > len(nums2):
            nums1, nums2 = nums2, nums1

        set1 = set(nums1)
        return list({x for x in nums2 if x in set1})
```

**Runtime:** 0ms | **Memory:** 12.7MB