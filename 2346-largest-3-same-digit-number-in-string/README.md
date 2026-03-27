# 2346 - Largest 3-Same-Digit Number in String

**Difficulty:** Easy  
**Problem Link:** [largest-3-same-digit-number-in-string](https://leetcode.com/problems/largest-3-same-digit-number-in-string/)

## Problem Description

Given a string `num` representing a large integer, find the maximum "good" integer - a substring of length 3 consisting of only one unique digit. Return empty string if none exists.

## Solution Approach

**Linear Scan:**
1. Iterate through the string
2. For each position, check if three consecutive characters are equal
3. Compare and track the maximum
4. String comparison handles numeric comparison since digits are same length

## Complexity Analysis

- **Time Complexity:** O(n) where n = string length
- **Space Complexity:** O(1)

## Accepted Solutions

| File | Runtime | Memory | Language |
|------|---------|--------|----------|
| 2026-03-27 23.09.27 - Accepted - runtime 0ms - memory 9MB.cpp | 0ms | 9MB | C++ |
| 2026-03-27 23.16.23 - Accepted - runtime 2ms - memory 53.2MB.js | 2ms | 53.2MB | JavaScript |

## Best Code Example

```javascript
function largestGoodInteger(num) {
    let ans = "";

    for (let i = 0; i < num.length - 2; i++) {
        if (num[i] === num[i+1] && num[i] === num[i+2]) {
            let temp = num.substring(i, i+3);
            if (temp > ans) ans = temp;
        }
    }

    return ans;
}
```