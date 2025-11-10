# 224. Basic Calculator

**Difficulty: Hard**

## Problem Description

Given a string `s` representing a valid mathematical expression, calculate and return its result. The expression may contain:
- Non-negative integers (0-9)
- Spaces ' '
- Operators '+', '-', '(', ')'

**Example 1:**
```
Input: s = "1 + 1"
Output: 2
```

**Constraints:**
* `1 <= s.length <= 10^5`
* `s` consists of digits, spaces, and operators '+', '-', '(', ')'.

## Solution Approach

We use a **stack** to handle parentheses:
1. Use two stack elements: previous result and previous sign.
2. Handle numbers, operators, and parentheses.
3. At ')', pop from stack to restore state.

## Complexity Analysis

- **Time Complexity:** O(n) - single pass.
- **Space Complexity:** O(n) - for stack.

## Accepted Solution Files

| File | Language | Runtime | Memory |
|------|----------|----------|--------|
| 2025-11-10 17.27.26 - Accepted - runtime 0ms - memory 9.4MB.c | C | 0ms | 9.4MB |

## Best Code Example

```c
int calculate(char *s) {
    int stack[20000];
    int top = -1;
    int res = 0, num = 0, sign = 1;

    for (char *p = s; *p; p++) {
        char c = *p;
        if (c == ' ') continue;

        if (c >= '0' && c <= '9') {
            num = num * 10 + (c - '0');
        } else if (c == '+' || c == '-') {
            res += sign * num;
            num = 0;
            sign = (c == '+') ? 1 : -1;
        } else if (c == '(') {
            stack[++top] = res;
            stack[++top] = sign;
            res = 0;
            sign = 1;
        } else if (c == ')') {
            res += sign * num;
            num = 0;
            int prevSign = stack[top--];
            int prevRes = stack[top--];
            res = prevRes + prevSign * res;
        }
    }

    if (num) res += sign * num;
    return res;
}
```