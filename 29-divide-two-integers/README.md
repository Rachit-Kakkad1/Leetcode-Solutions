# 29. Divide Two Integers

**Difficulty: Medium**

## Problem Description

Divide two integers without using multiplication, division, or modulo. Return the quotient.

**Example 1:**
```
Input: dividend = 10, divisor = 3
Output: 3
```

**Constraints:**
* `-2^31 <= dividend <= 2^31 - 1`
* `divisor != 0`

## Solution Approach

We use the **double shift** technique:
1. Repeatedly subtract multiples of divisor.
2. Double the divisor each time for efficiency.
3. Handle overflow edge case.

## Complexity Analysis

- **Time Complexity:** O(log n).
- **Space Complexity:** O(1).

## Accepted Solution Files

| File | Language | Runtime | Memory |
|------|----------|----------|--------|
| 2025-11-10 16.31.22 - Accepted - runtime 0ms - memory 12.6MB.py | Python | 0ms | 12.6MB |

## Best Code Example

```python
class Solution(object):
    def divide(self, dividend, divisor):
        INT_MAX = 2**31 - 1
        INT_MIN = -2**31
        if dividend == INT_MIN and divisor == -1:
            return INT_MAX
        negative = (dividend < 0) ^ (divisor < 0)
        dividend, divisor = abs(dividend), abs(divisor)
        quotient = 0
        while dividend >= divisor:
            temp, multiple = divisor, 1
            while dividend >= (temp << 1):
                temp <<= 1
                multiple <<= 1
            dividend -= temp
            quotient += multiple
        if negative:
            quotient = -quotient
        return max(min(quotient, INT_MAX), INT_MIN)
```