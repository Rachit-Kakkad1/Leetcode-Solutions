# 3072 - Reshape Data: Pivot

**Difficulty:** Easy

**Link:** [Reshape Data: Pivot - LeetCode](https://leetcode.com/problems/reshape-data-pivot/)

## Problem Description

DataFrame `weather`:
```
+-------------+--------+
| Column Name | Type   |
+-------------+--------+
| city        | object |
| month       | object |
| temperature | int    |
+-------------+--------+
```

Write a solution to **pivot** the data so that each row represents temperatures for a specific month, and each city is a separate column.

## Example Test Cases

### Example 1:
```
Input:
+--------------+----------+-------------+
| city         | month    | temperature |
+--------------+----------+-------------+
| Jacksonville | January  | 13          |
| Jacksonville | February | 23          |
| Jacksonville | March    | 38          |
| Jacksonville | April    | 5           |
| Jacksonville | May      | 34          |
| ElPaso       | January  | 20          |
| ElPaso       | February | 6           |
| ElPaso       | March    | 26          |
| ElPaso       | April    | 2           |
| ElPaso       | May      | 43          |
+--------------+----------+-------------+
Output:
+----------+--------+--------------+
| month    | ElPaso | Jacksonville |
+----------+--------+--------------+
| April    | 2      | 5            |
| February | 6      | 23           |
| January  | 20     | 13           |
| March    | 26     | 38           |
| May      | 43     | 34           |
+----------+--------+--------------+
Explanation: The table is pivoted, each column represents a city, and each row represents a specific month.
```

## Solution Approach

### Algorithm Explanation

Use Pandas pivot function to reshape data:

1. Use pivot() with index=month, columns=city, values=temperature
2. This transforms the long format to wide format

### Step-by-Step Logic

1. Call weather.pivot(index="month", columns="city", values="temperature")
2. Return the pivoted DataFrame

### Why It Works

- Pandas pivot automatically reorganizes data
- index parameter defines new row labels (month)
- columns parameter defines new column labels (city)
- values defines which data fills the cells (temperature)

## Complexity Analysis

- **Time Complexity:** O(n) - Pivot operation processes all rows
- **Space Complexity:** O(n) - New DataFrame storage

## Accepted Solutions

| File Name | Language | Runtime | Memory |
|-----------|----------|---------|--------|
| 2026-04-12 19.22.00 - Accepted - runtime 309ms - memory 67.5MB.pd.py | Python (Pandas) | 309ms | 67.5MB |
| 2026-04-12 19.30.24 - Accepted - runtime 310ms - memory 67.8MB.pd.py | Python (Pandas) | 310ms | 67.8MB |

## Code Example (Best Solution - Pandas)

```python
import pandas as pd

def pivotTable(weather):
    return weather.pivot(index="month", columns="city", values="temperature")
```

**Runtime:** 310ms | **Memory:** 67.8MB