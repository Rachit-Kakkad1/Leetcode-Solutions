# 202. Happy Number

**Difficulty: Medium**

## Problem Description

Write an algorithm to determine whether a number `n` is happy. A happy number is defined by repeatedly replacing the number with the sum of the squares of its digits until it equals 1. If it never reaches 1, it's not happy.

**Example 1:**
```
Input: n = 19
Output: true
Explanation: 1^2 + 9^2 = 82 -> 8^2 + 2^2 = 68 -> 6^2 + 8^2 = 100 -> 1^2 + 0^2 + 0^2 = 1
```

**Constraints:**
* `1 <= n <= 2^31 - 1`

## Solution Approach

We use either **Floyd's cycle detection** or a **hash set**:
1. Calculate sum of squares of digits.
2. Detect cycles using either:
   - Hash set to store visited numbers, or
   - Two pointers (slow/fast) - if they meet, there's a cycle.
3. Return true if we reach 1.

## Complexity Analysis

- **Time Complexity:** O(log n) - number of digits decreases.
- **Space Complexity:** O(log n) for hash set, O(1) for Floyd's algorithm.

## Accepted Solution Files

| File | Language | Runtime | Memory |
|------|----------|----------|--------|
| 2025-11-10 17.03.19 - Accepted - runtime 0ms - memory 8.9MB.c | C | 0ms | 8.9MB |

## Best Code Example

```c
bool isHappy(int n) {
    int seen[1000] = {0};
    while (n != 1) {
        if (seen[n % 1000]) return false;
        seen[n % 1000] = 1;
        int sum = 0;
        while (n > 0) {
            int d = n % 10;
            sum += d * d;
            n /= 10;
        }
        n = sum;
    }
    return true;
}
```