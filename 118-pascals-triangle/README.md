# 118 - Pascal's Triangle

**Difficulty:** Easy

**Link:** [Pascal's Triangle - LeetCode](https://leetcode.com/problems/pascals-triangle/)

## Problem Description

Given an integer `numRows`, return the first numRows of **Pascal's triangle**.

In **Pascal's triangle**, each number is the sum of the two numbers directly above it as shown.

## Example Test Cases

### Example 1:
```
Input: numRows = 5
Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
```

### Example 2:
```
Input: numRows = 1
Output: [[1]]
```

## Constraints

- `1 <= numRows <= 30`

## Solution Approach

### Algorithm Explanation

Build the triangle row by row using the property that each element is the sum of two elements above it:

1. Start with first row containing just [1]
2. For each subsequent row:
   - First element is always 1
   - Each interior element = triangle[i-1][j-1] + triangle[i-1][j]
   - Last element is always 1

### Step-by-Step Logic

1. Initialize empty triangle array
2. Loop i from 0 to numRows-1:
   - Create row of size i+1, filled with 1
   - Loop j from 1 to i-1:
     - row[j] = triangle[i-1][j-1] + triangle[i-1][j]
   - Add row to triangle
3. Return triangle

### Why It Works

- Pascal's triangle property is mathematically correct
- Each row depends only on the previous row
- O(n²) total elements for n rows

## Complexity Analysis

- **Time Complexity:** O(n²) - Creating n rows with total n(n+1)/2 elements
- **Space Complexity:** O(n²) - Storing the entire triangle

## Accepted Solutions

| File Name | Language | Runtime | Memory |
|-----------|----------|---------|--------|
| 2026-02-17 13.41.50 - Accepted - runtime 0ms - memory 54.2MB.js | JavaScript | 0ms | 54.2MB |

## Code Example (Best Solution - JavaScript)

```javascript
/**
 * @param {number} numRows
 * @return {number[][]}
 */
function generate(numRows) {
    const triangle = [];

    for (let i = 0; i < numRows; i++) {
        const row = new Array(i + 1).fill(1);

        for (let j = 1; j < i; j++) {
            row[j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
        }

        triangle.push(row);
    }

    return triangle;
}
```

**Runtime:** 0ms | **Memory:** 54.2MB