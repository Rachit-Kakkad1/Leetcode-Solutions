# 2575 - Minimum Cuts to Divide a Circle

**Difficulty:** Easy  
**Problem Link:** [minimum-cuts-to-divide-a-circle](https://leetcode.com/problems/minimum-cuts-to-divide-a-circle/)

## Problem Description

A valid cut in a circle can be:
- A cut passing through the center and two points on the edge (diameter)
- A cut passing through center and one edge point (radius)

Given integer n, return minimum number of cuts to divide a circle into n equal slices.

## Solution Approach

**Mathematical Logic:**
- If n = 1: No cuts needed (circle is already 1 slice)
- If n is even: n/2 cuts (using diameters)
- If n is odd: n cuts (diameters won't work evenly)

## Complexity Analysis

- **Time Complexity:** O(1)
- **Space Complexity:** O(1)

## Accepted Solutions

| File | Runtime | Memory | Language |
|------|---------|--------|----------|
| 2026-03-07 15.48.55 - Accepted - runtime 0ms - memory 54.3MB.js | 0ms | 54.3MB | JavaScript |

## Best Code Example

```javascript
function numberOfCuts(n) {
    if (n === 1) return 0;
    if (n % 2 === 0) return n / 2;
    return n;
}
```