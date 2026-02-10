# 507 - Perfect Number

**Difficulty:** Easy  
**Problem Link:** [perfect-number](https://leetcode.com/problems/perfect-number/)

## Problem Description

A perfect number is a positive integer that is equal to the sum of its positive divisors, excluding the number itself. Given an integer `n`, return `true` if `n` is a perfect number, otherwise return `false`.

## Solution Approach

**Divisor Summation:**
1. Start with sum = 1 (1 is always a divisor for n > 1)
2. Iterate from 2 to sqrt(n)
3. For each divisor found, add both the divisor and n/divisor
4. Check if sum equals n

## Complexity Analysis

- **Time Complexity:** O(sqrt(n))
- **Space Complexity:** O(1)

## Accepted Solutions

| File | Runtime | Memory | Language |
|------|---------|--------|----------|
| 2026-02-10 23.07.39 - Accepted - runtime 2ms - memory 55.7MB.js | 2ms | 55.7MB | JavaScript |

## Best Code Example

```javascript
function checkPerfectNumber(num) {
    if (num <= 1) return false;

    let sum = 1; 

    for (let i = 2; i * i <= num; i++) {
        if (num % i === 0) {
            sum += i;

            if (i !== num / i) {
                sum += num / i;
            }
        }
    }

    return sum === num;
}
```