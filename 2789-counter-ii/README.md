# 2789 - Counter II

**Difficulty:** Easy  
**Problem Link:** [counter-ii](https://leetcode.com/problems/counter-ii/)

## Problem Description

Write a function `createCounter` that accepts an initial integer `init` and returns an object with three functions:
- `increment()` - increases current value by 1 and returns it
- `decrement()` - reduces current value by 1 and returns it
- `reset()` - sets current value to `init` and returns it

## Solution Approach

**Closure-based Object:**
1. Use closure to capture initial value and current value
2. Return an object with three methods
3. Each method modifies and returns the value appropriately

## Complexity Analysis

- **Time Complexity:** O(1) per call
- **Space Complexity:** O(1)

## Accepted Solutions

| File | Runtime | Memory | Language |
|------|---------|--------|----------|
| 2026-04-12 20.10.05 - Accepted - runtime 49ms - memory 56.4MB.js | 49ms | 56.4MB | JavaScript |

## Best Code Example

```javascript
var createCounter = function(init) {
    let value = init;

    return {
        increment: function() {
            value++;
            return value;
        },
        decrement: function() {
            value--;
            return value;
        },
        reset: function() {
            value = init;
            return value;
        }
    };
};
```