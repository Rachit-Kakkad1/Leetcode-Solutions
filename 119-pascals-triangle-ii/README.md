# 119 - Pascal's Triangle II

**Difficulty:** Easy

**Link:** [Pascal's Triangle II - LeetCode](https://leetcode.com/problems/pascals-triangle-ii/)

## Problem Description

Given an integer `rowIndex`, return the `rowIndex^th` (**0-indexed**) row of the **Pascal's triangle**.

In **Pascal's triangle**, each number is the sum of the two numbers directly above it as shown.

## Example Test Cases

### Example 1:
```
Input: rowIndex = 3
Output: [1,3,3,1]
```

### Example 2:
```
Input: rowIndex = 0
Output: [1]
```

### Example 3:
```
Input: rowIndex = 1
Output: [1,1]
```

## Constraints

- `0 <= rowIndex <= 33`

## Solution Approach

### Algorithm Explanation

Build the row iteratively using the previous row:

1. Start with row = [1]
2. For each level i from 1 to rowIndex:
   - Create new row with 1 at start and end
   - Calculate inner values as sum of adjacent elements from previous row

### Step-by-Step Logic

1. Initialize row = {1}
2. For i = 1 to rowIndex:
   - Create newRow of size i+1 with 1s
   - For j = 1 to i-1: newRow[j] = row[j-1] + row[j]
   - row = newRow
3. Return row

### Why It Works

- Pascal's triangle property: each element is sum of two above it
- Building row by row correctly computes all values
- Follow-up constraint: uses O(rowIndex) space by keeping only current row

## Complexity Analysis

- **Time Complexity:** O(rowIndex²) - Building each row takes O(i) for row i
- **Space Complexity:** O(rowIndex) - Only storing current row

## Accepted Solutions

| File Name | Language | Runtime | Memory |
|-----------|----------|---------|--------|
| 2026-04-10 22.58.40 - Accepted - runtime 0ms - memory 9.1MB.cpp | C++ | 0ms | 9.1MB |

## Code Example (Best Solution - C++)

```cpp
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> row = {1};

        for (int i = 1; i <= rowIndex; i++) {
            vector<int> newRow(i + 1, 1);

            for (int j = 1; j < i; j++) {
                newRow[j] = row[j - 1] + row[j];
            }

            row = newRow;
        }

        return row;
    }
};
```

**Runtime:** 0ms | **Memory:** 9.1MB