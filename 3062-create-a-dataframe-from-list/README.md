# 3062 - Create a DataFrame from List

**Difficulty:** Easy  
**Problem Link:** [create-a-dataframe-from-list](https://leetcode.com/problems/create-a-dataframe-from-list/)

## Problem Description

Write a solution to create a DataFrame from a 2D list called `student_data` with columns `student_id` and `age`, maintaining the same order as the original list.

## Solution Approach

Use pandas DataFrame constructor with column names specified.

## Complexity Analysis

- **Time Complexity:** O(n)
- **Space Complexity:** O(n)

## Accepted Solutions

| File | Runtime | Memory | Language |
|------|---------|--------|----------|
| 2026-04-12 18.57.19 - Accepted - runtime 273ms - memory 66.6MB.pd.py | 273ms | 66.6MB | Python (Pandas) |
| 2026-04-12 19.28.00 - Accepted - runtime 245ms - memory 65.6MB.pd.py | 245ms | 65.6MB | Python (Pandas) |

## Best Code Example

```python
import pandas as pd

def createDataframe(student_data):
    df = pd.DataFrame(student_data, columns=["student_id", "age"])
    return df
```