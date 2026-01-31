# 350 - Intersection of Two Arrays II

**Difficulty:** Easy  
**Problem Link:** [intersection-of-two-arrays-ii](https://leetcode.com/problems/intersection-of-two-arrays-ii/)

## Problem Description

Given two integer arrays `nums1` and `nums2`, return an array of their intersection. Each element in the result must appear as many times as it shows in both arrays.

## Solution Approach

**Hash Map Counter:**
1. Build frequency map from nums1
2. Iterate nums2 and collect matching elements with remaining count
3. Decrement frequency after each match

## Complexity Analysis

- **Time Complexity:** O(n + m)
- **Space Complexity:** O(n)

## Accepted Solutions

| File | Runtime | Memory | Language |
|------|---------|--------|----------|
| 2026-01-31 13.58.44 - Accepted - runtime 0ms - memory 12.6MB.py | 0ms | 12.6MB | Python |

## Best Code Example

```python
class Solution:
    def intersect(self, nums1, nums2):
        freq = {}
        result = []

        for num in nums1:
            freq[num] = freq.get(num, 0) + 1

        for num in nums2:
            if num in freq and freq[num] > 0:
                result.append(num)
                freq[num] -= 1

        return result
```