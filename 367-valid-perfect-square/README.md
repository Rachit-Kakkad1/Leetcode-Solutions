# 367 - Valid Perfect Square

**Difficulty:** Easy  
**Problem Link:** [valid-perfect-square](https://leetcode.com/problems/valid-perfect-square/)

## Problem Description

Given a positive integer `num`, return `true` if `num` is a perfect square or `false` otherwise. Cannot use built-in sqrt function.

## Solution Approach

**Binary Search:**
1. Set search range from 1 to num
2. Use binary search to find if any number squared equals num
3. Handle overflow by comparing mid * mid with num

## Complexity Analysis

- **Time Complexity:** O(log n)
- **Space Complexity:** O(1)

## Accepted Solutions

| File | Runtime | Memory | Language |
|------|---------|--------|----------|
| 2026-02-10 23.03.36 - Accepted - runtime 0ms - memory 54.2MB.js | 0ms | 54.2MB | JavaScript |

## Best Code Example

```javascript
function isPerfectSquare(num) {
    let left = 1;
    let right = num;

    while (left <= right) {
        const mid = Math.floor((left + right) / 2);
        const square = mid * mid;

        if (square === num) return true;
        if (square < num) left = mid + 1;
        else right = mid - 1;
    }

    return false;
}
```