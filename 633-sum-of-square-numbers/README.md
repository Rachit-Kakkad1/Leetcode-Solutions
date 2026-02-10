# 633 - Sum of Square Numbers

**Difficulty:** Medium  
**Problem Link:** [sum-of-square-numbers](https://leetcode.com/problems/sum-of-square-numbers/)

## Problem Description

Given a non-negative integer `c`, decide whether there are two integers `a` and `b` such that `a² + b² = c`.

## Solution Approach

**Two Pointer:**
1. Start with a = 0, b = sqrt(c)
2. Calculate a² + b² and compare with c
3. If sum < c, increment a; if sum > c, decrement b
4. Continue until a <= b

## Complexity Analysis

- **Time Complexity:** O(sqrt(c))
- **Space Complexity:** O(1)

## Accepted Solutions

| File | Runtime | Memory | Language |
|------|---------|--------|----------|
| 2026-02-10 23.13.43 - Accepted - runtime 6ms - memory 55.8MB.js | 6ms | 55.8MB | JavaScript |

## Best Code Example

```javascript
function judgeSquareSum(c) {
    let a = 0;
    let b = Math.floor(Math.sqrt(c));

    while (a <= b) {
        const sum = a * a + b * b;

        if (sum === c) return true;
        if (sum < c) a++;
        else b--;
    }

    return false;
}
```