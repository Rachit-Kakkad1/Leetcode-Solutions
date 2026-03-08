# 2107 - Find Unique Binary String

**Difficulty:** Medium  
**Problem Link:** [find-unique-binary-string](https://leetcode.com/problems/find-unique-binary-string/)

## Problem Description

Given an array of strings `nums` containing n unique binary strings each of length n, return a binary string of length n that does not appear in nums.

## Solution Approach

**Diagonal Construction:**
1. For each position i, check nums[i][i] (the ith character of the ith string)
2. If it's '0', put '1' at position i; otherwise put '0'
3. This ensures the result differs from each string in at least one position
4. Since there are n strings of length n (2^n possible strings), the result is guaranteed to be unique

## Complexity Analysis

- **Time Complexity:** O(n^2) where n = number of strings
- **Space Complexity:** O(n) for the result string

## Accepted Solutions

| File | Runtime | Memory | Language |
|------|---------|--------|----------|
| 2026-03-08 17.53.23 - Accepted - runtime 4ms - memory 12.3MB.py | 4ms | 12.3MB | Python |

## Best Code Example

```python
class Solution:
    def findDifferentBinaryString(self, nums):
        res = []

        for i in range(len(nums)):
            if nums[i][i] == '0':
                res.append('1')
            else:
                res.append('0')

        return "".join(res)
```