# 201. Bitwise AND of Numbers Range

**Difficulty: Medium**

## Problem Description

Given two integers `left` and `right`, find the bitwise AND of all numbers in the range `[left, right]`.

**Example 1:**
```
Input: left = 5, right = 7
Output: 4
```

**Constraints:**
* `0 <= left <= right <= 2^31 - 1`

## Solution Approach

We use the **shift** technique:
1. When left != right, both shift right by 1.
2. Count the number of shifts.
3. Shift left back to get the result.

This works because the common prefix of all numbers in the range is what remains after the AND operation.

## Complexity Analysis

- **Time Complexity:** O(log(left - right)) ~ O(31) - at most 31 iterations for 32-bit integers.
- **Space Complexity:** O(1).

## Accepted Solution Files

| File | Language | Runtime | Memory |
|------|----------|----------|--------|
| 2026-03-07 23.39.05 - Accepted - runtime 0ms - memory 11.3MB.cpp | C++ | 0ms | 11.3MB |

## Best Code Example

```cpp
class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int shift = 0;

        while (left != right) {
            left >>= 1;
            right >>= 1;
            shift++;
        }

        return left << shift;
    }
};
```