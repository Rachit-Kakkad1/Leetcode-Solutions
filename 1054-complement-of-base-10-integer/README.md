# 1054 - Complement of Base 10 Integer

**Difficulty:** Easy

**Link:** [Complement of Base 10 Integer - LeetCode](https://leetcode.com/problems/complement-of-base-10-integer/)

## Problem Description

The **complement** of an integer is the integer you get when you flip all the `0`'s to `1`'s and all the `1`'s to `0`'s in its binary representation.

- For example, The integer `5` is `"101"` in binary and its **complement** is `"010"` which is the integer `2`.

Given an integer `n`, return *its complement*.

## Example Test Cases

### Example 1:
```
Input: n = 5
Output: 2
Explanation: 5 is "101" in binary, with complement "010" in binary, which is 2 in base-10.
```

### Example 2:
```
Input: n = 7
Output: 0
Explanation: 7 is "111" in binary, with complement "000" in binary, which is 0 in base-10.
```

### Example 3:
```
Input: n = 10
Output: 5
Explanation: 10 is "1010" in binary, with complement "0101" in binary, which is 5 in base-10.
```

## Constraints

- `0 <= n < 10^9`

## Solution Approach

### Algorithm Explanation

Use bit manipulation to compute the complement efficiently:

1. Edge case: if n == 0, return 1
2. Find the bit length of n (number of bits needed)
3. Create a mask with all 1s of that bit length
4. XOR n with mask to flip bits

Formula: `(1 << bit_length) - 1 - n`

### Step-by-Step Logic

1. If n == 0: return 1
2. Get bit length using `n.bit_length()` in Python
3. Compute mask: `1 << bit_length` gives value with 1 followed by bit_length zeros
4. Subtract 1 to get all 1s of that length
5. Subtract n from mask to get complement

### Why It Works

- XOR with 1 flips each bit
- The mask ensures we only flip bits within n's bit length
- Bit length correctly handles leading zeros

## Complexity Analysis

- **Time Complexity:** O(1) - Constant time operations
- **Space Complexity:** O(1)

## Accepted Solutions

| File Name | Language | Runtime | Memory |
|-----------|----------|---------|--------|
| 2026-03-11 20.21.51 - Accepted - runtime 0ms - memory 12.5MB.py | Python | 0ms | 12.5MB |

## Code Example (Best Solution - Python)

```python
class Solution:
    def bitwiseComplement(self, n):
        if n == 0:
            return 1
        return (1 << n.bit_length()) - 1 - n
```

**Runtime:** 0ms | **Memory:** 12.5MB