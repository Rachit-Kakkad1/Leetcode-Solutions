# 2813 - To Be Or Not To Be

**Difficulty:** Easy  
**Problem Link:** [to-be-or-not-to-be](https://leetcode.com/problems/to-be-or-not-to-be/)

## Problem Description

Write a function `expect` that takes any value `val` and returns an object with two functions:
- `toBe(val)` - returns true if two values are === each other, throws "Not Equal" if not
- `notToBe(val)` - returns true if two values are !== each other, throws "Equal" if equal

## Solution Approach

**Closure-based Assertion:**
1. Use closure to capture the initial value
2. Return an object with two methods
3. Each method performs strict equality check and throws errors appropriately

## Complexity Analysis

- **Time Complexity:** O(1) per call
- **Space Complexity:** O(1)

## Accepted Solutions

| File | Runtime | Memory | Language |
|------|---------|--------|----------|
| 2026-04-12 20.09.29 - Accepted - runtime 39ms - memory 53.5MB.js | 39ms | 53.5MB | JavaScript |

## Best Code Example

```javascript
var expect = function(val) {
    return {
        toBe: function(other) {
            if (val === other) return true;
            else throw new Error("Not Equal");
        },
        notToBe: function(other) {
            if (val !== other) return true;
            else throw new Error("Equal");
        }
    };
};
```