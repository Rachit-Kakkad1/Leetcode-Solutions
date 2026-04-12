# 2809 - Create Hello World Function

**Difficulty:** Easy

**Link:** [Create Hello World Function - LeetCode](https://leetcode.com/problems/create-hello-world-function/)

## Problem Description

Write a function `createHelloWorld`. It should return a new function that always returns `"Hello World"`.

## Example Test Cases

### Example 1:
```
Input: args = []
Output: "Hello World"
Explanation:
const f = createHelloWorld();
f(); // "Hello World"

The function returned by createHelloWorld should always return "Hello World".
```

### Example 2:
```
Input: args = [{},null,42]
Output: "Hello World"
Explanation:
const f = createHelloWorld();
f({}, null, 42); // "Hello World"

Any arguments could be passed to the function but it should still always return "Hello World".
```

## Constraints

- `0 <= args.length <= 10`

## Solution Approach

### Algorithm Explanation

Return a closure that ignores its arguments and returns a constant string:

1. createHelloWorld returns an anonymous function
2. The returned function uses rest parameters (...) to accept any arguments
3. Always returns "Hello World" regardless of input

### Step-by-Step Logic

1. createHelloWorld returns a function
2. Returned function takes any number of arguments using spread/rest
3. Return "Hello World"

### Why It Works

- JavaScript closures capture the surrounding scope
- Rest parameters allow any arguments to be passed
- The returned function always returns the constant string

## Complexity Analysis

- **Time Complexity:** O(1) - Constant time
- **Space Complexity:** O(1) - Only stores constant string

## Accepted Solutions

| File Name | Language | Runtime | Memory |
|-----------|----------|---------|--------|
| 2026-04-12 18.58.50 - Accepted - runtime 35ms - memory 53.7MB.js | JavaScript | 35ms | 53.7MB |

## Code Example (Best Solution - JavaScript)

```javascript
/**
 * @return {Function}
 */
var createHelloWorld = function() {
    
    return function(...args) {
        return "Hello World"
    }
};

/**
 * const f = createHelloWorld();
 * f(); // "Hello World"
 */
```

**Runtime:** 35ms | **Memory:** 53.7MB