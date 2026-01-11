# 414 - Third Maximum Number

**Difficulty:** Easy  
**Problem Link:** [third-maximum-number](https://leetcode.com/problems/third-maximum-number/)

## Problem Description

Given an integer array `nums`, return the third distinct maximum number in this array. If the third maximum does not exist, return the maximum number.

## Solution Approach

**Three Maximum Variables:**
1. Track first, second, and third maximum values
2. Skip duplicates using equality checks
3. Update values in descending order when finding larger numbers
4. Return third if exists, otherwise return first

## Complexity Analysis

- **Time Complexity:** O(n)
- **Space Complexity:** O(1)

## Accepted Solutions

| File | Runtime | Memory | Language |
|------|---------|--------|----------|
| 2026-01-11 13.48.51 - Accepted - runtime 1ms - memory 57.3MB.js | 1ms | 57.3MB | JavaScript |
| 2026-01-31 14.00.01 - Accepted - runtime 3ms - memory 13MB.py | 3ms | 13MB | Python |
| 2026-01-31 14.00.15 - Accepted - runtime 3ms - memory 12.7MB.py | 3ms | 12.7MB | Python |
| 2026-01-31 14.01.10 - Accepted - runtime 0ms - memory 13.2MB.py | 0ms | 13.2MB | Python |

## Best Code Example

```python
class Solution:
    def thirdMax(self, nums):
        first = second = third = None

        for num in nums:
            if num == first or num == second or num == third:
                continue

            if first is None or num > first:
                third = second
                second = first
                first = num
            elif second is None or num > second:
                third = second
                second = num
            elif third is None or num > third:
                third = num

        return third if third is not None else first
```