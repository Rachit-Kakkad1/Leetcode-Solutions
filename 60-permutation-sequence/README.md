# 60 - Permutation Sequence

**Difficulty:** Hard  
**Problem Link:** [permutation-sequence](https://leetcode.com/problems/permutation-sequence/)

## Problem Description

The set [1, 2, 3, ..., n] contains a total of n! unique permutations. Given n and k, return the kth permutation sequence.

## Solution Approach

**Mathematical Construction (Lehmer Code):**
1. Convert k to 0-indexed (k-1)
2. For each position, determine which remaining number to use
3. Use factorial to determine the block size for each position
4. Calculate index: k // factorial(n-1)
5. Remove used number and update k

## Complexity Analysis

- **Time Complexity:** O(n^2) due to list operations
- **Space Complexity:** O(n)

## Accepted Solutions

| File | Runtime | Memory | Language |
|------|---------|--------|----------|
| 2025-11-10 17.01.20 - Accepted - runtime 6ms - memory 12.3MB.py | 6ms | 12.3MB | Python |

## Best Code Example

```python
class Solution(object):
    def getPermutation(self, n, k):
        import math
        nums = [str(i) for i in range(1, n + 1)]
        k -= 1
        res = ""
        for i in range(n, 0, -1):
            idx = k // math.factorial(i - 1)
            res += nums[idx]
            nums.pop(idx)
            k %= math.factorial(i - 1)
        return res
```