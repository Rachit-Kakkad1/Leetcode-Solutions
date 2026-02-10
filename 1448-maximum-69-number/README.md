# 1448. Maximum 69 Number

**Difficulty: Easy**

## Problem Description

Given a positive integer `num` consisting only of digits 6 and 9, return the maximum number you can get by changing **at most** one digit (6 becomes 9, and 9 becomes 6).

**Example 1:**
```
Input: num = 9669
Output: 9969
Explanation: Changing the first digit results in 6669. Changing the second digit results in 9969. Changing the third digit results in 9699. Changing the fourth digit results in 9666. The maximum number is 9969.
```

**Example 2:**
```
Input: num = 9996
Output: 9999
Explanation: Changing the last digit 6 to 9 results in the maximum number.
```

**Example 3:**
```
Input: num = 9999
Output: 9999
Explanation: It is better not to apply any change.
```

**Constraints:**
* `1 <= num <= 10^4`
* `num` consists of only 6 and 9 digits.

## Solution Approach

We use a **Greedy** approach:
1. Convert the number to a string so we can manipulate individual digits.
2. Find the first occurrence of digit '6' (from left to right).
3. Change that '6' to '9' to maximize the number.
4. Since changing a 6 to 9 at any position increases the number, doing it at the earliest (leftmost) position gives the maximum result.
5. If there's no '6' in the number, return the original number unchanged.

## Complexity Analysis

- **Time Complexity:** O(d) where d is the number of digits (at most 5 for num <= 10^4).
- **Space Complexity:** O(d) for converting to string.

## Accepted Solution Files

| File | Language | Runtime | Memory |
|------|----------|----------|--------|
| 2026-02-10 23.23.54 - Accepted - runtime 0ms - memory 54.2MB.js | JavaScript | 0ms | 54.2MB |

## Best Code Example

```javascript
function maximum69Number(num) {
  return Number(num.toString().replace('6','9'))
}
```

This elegant one-liner converts the number to a string, replaces the first occurrence of '6' with '9', and converts back to a number.