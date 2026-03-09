# 4179 - Largest Even Number

**Difficulty:** Easy  
**Problem Link:** [largest-even-number](https://leetcode.com/problems/largest-even-number/)

## Problem Description

Given a string s of '1' and '2' characters, return the largest possible resultant string that represents an even integer. You may delete any number of characters without changing order. Return empty string if no such string exists.

## Solution Approach

**Find last '2':**
1. Find the rightmost '2' in the string
2. If no '2' exists, return empty string
3. Otherwise, return substring up to and including that '2'

## Complexity Analysis

- **Time Complexity:** O(n)
- **Space Complexity:** O(1)

## Accepted Solutions

| File | Runtime | Memory | Language |
|------|---------|--------|----------|
| 2026-03-09 11.10.29 - Accepted - runtime 0ms - memory 8.6MB.cpp | 0ms | 8.6MB | C++ |

## Best Code Example

```cpp
class Solution {
public:
    string largestEven(string r) {
        int lt = -1;

        for (int i = 0; i < r.size(); i++) {
            if (r[i] == '2')
                lt = i;
        }

        if (lt == -1)
            return "";

        return r.substr(0, lt + 1);
    }
};
```