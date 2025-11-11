# 415 - Add Strings

**Difficulty:** Easy  
**Problem Link:** [add-strings](https://leetcode.com/problems/add-strings/)

## Problem Description

Given two non-negative integers `num1` and `num2` represented as strings, return the sum of `num1` and `num2` as a string without using BigInteger or converting to integers.

## Solution Approach

**Digit-by-Digit Addition:**
1. Start from rightmost digits
2. Add corresponding digits with carry
3. Store result in array (reversed)
4. Reverse and join at the end

## Complexity Analysis

- **Time Complexity:** O(max(n, m)) where n, m = lengths of strings
- **Space Complexity:** O(max(n, m))

## Accepted Solutions

| File | Runtime | Memory | Language |
|------|---------|--------|----------|
| 2025-11-11 18.35.11 - Accepted - runtime 7ms - memory 12.5MB.py | 7ms | 12.5MB | Python |
| 2025-11-11 18.35.46 - Accepted - runtime 8ms - memory 12.6MB.py | 8ms | 12.6MB | Python |
| 2025-11-11 18.36.35 - Accepted - runtime 3ms - memory 55.2MB.js | 3ms | 55.2MB | JavaScript |
| 2025-11-11 18.37.27 - Accepted - runtime 0ms - memory 56.1MB.js | 0ms | 56.1MB | JavaScript |
| 2025-11-11 18.39.48 - Accepted - runtime 0ms - memory 8.2MB.c | 0ms | 8.2MB | C |

## Best Code Example

```javascript
function addStrings(num1, num2) {
    let i = num1.length - 1;
    let j = num2.length - 1;
    let carry = 0;
    const res = [];

    while (i >= 0 || j >= 0 || carry) {
        const x = i >= 0 ? num1.charCodeAt(i) - 48 : 0;
        const y = j >= 0 ? num2.charCodeAt(j) - 48 : 0;
        const sum = x + y + carry;

        res.push(sum % 10);
        carry = (sum / 10) | 0;
        i--;
        j--;
    }

    res.reverse();
    return res.join('');
}
```