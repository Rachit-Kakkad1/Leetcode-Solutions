# 227 - Basic Calculator II

**Difficulty:** Medium  
**Problem Link:** [basic-calculator-ii](https://leetcode.com/problems/basic-calculator-ii/)

## Problem Description

Given a string `s` which represents an expression, evaluate this expression and return its value. The expression contains integers and operators (+, -, *, /) separated by spaces. Integer division should truncate toward zero.

## Solution Approach

**Stack-based Evaluation:**
1. Parse the string character by character
2. Build numbers and track the last operator
3. Apply operations immediately for * and / (push to stack)
4. For + and -, push the signed number to stack
5. Sum all values in the stack at the end
6. Handle integer division with proper truncation (Math.ceil for negative numbers)

## Complexity Analysis

- **Time Complexity:** O(n) where n = string length
- **Space Complexity:** O(n) for the stack

## Accepted Solutions

| File | Runtime | Memory | Language |
|------|---------|--------|----------|
| 2026-02-12 06.11.34 - Accepted - runtime 12ms - memory 62.3MB.js | 12ms | 62.3MB | JavaScript |

## Best Code Example

```javascript
function calculate(s) {
    const stack = [];
    let num = 0;
    let sign = '+';

    for (let i = 0; i < s.length; i++) {
        const ch = s[i];

        if (ch >= '0' && ch <= '9') {
            num = num * 10 + (ch.charCodeAt(0) - 48);
        }

        if ((ch !== ' ' && (ch < '0' || ch > '9')) || i === s.length - 1) {
            if (sign === '+') stack.push(num);
            else if (sign === '-') stack.push(-num);
            else if (sign === '*') stack.push(stack.pop() * num);
            else if (sign === '/') {
                const prev = stack.pop();
                stack.push(prev < 0 ? Math.ceil(prev / num) : Math.floor(prev / num));
            }

            sign = ch;
            num = 0;
        }
    }

    return stack.reduce((a, b) => a + b, 0);
}
```