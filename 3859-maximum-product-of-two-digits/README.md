# 3859 - Maximum Product of Two Digits

**Difficulty:** Easy  
**Problem Link:** [maximum-product-of-two-digits](https://leetcode.com/problems/maximum-product-of-two-digits/)

## Problem Description

Given a positive integer n, return the maximum product of any two digits in n. Same digit can be used twice if it appears more than once.

## Solution Approach

**Track two largest digits:**
1. Extract each digit using modulo
2. Track the two largest digits
3. Multiply them for the answer

## Complexity Analysis

- **Time Complexity:** O(d) where d = number of digits
- **Space Complexity:** O(1)

## Accepted Solutions

| File | Runtime | Memory | Language |
|------|---------|--------|----------|
| 2026-02-17 20.39.56 - Accepted - runtime 1ms - memory 57.5MB.js | 1ms | 57.5MB | JavaScript |

## Best Code Example

```javascript
function maxProduct(n) {
    let max1 = 0; 
    let max2 = 0; 

    while (n > 0) {
        let a = n % 10;

        if (a > max1) {
            max2 = max1;
            max1 = a;
        } else if (a > max2) {
            max2 = a;
        }

        n = Math.floor(n / 10);
    }

    return max1 * max2;
}
```