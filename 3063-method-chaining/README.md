# 3063 - Method Chaining

**Difficulty:** Easy  
**Problem Link:** [method-chaining](https://leetcode.com/problems/method-chaining/)

## Problem Description

Given a DataFrame `animals` with columns name, species, age, weight, list names of animals weighing strictly more than 100kg, sorted by weight in descending order. Use method chaining (one line).

## Solution Approach

**Method Chaining:**
1. Filter with condition: weight > 100
2. Sort by weight descending
3. Select name column

## Complexity Analysis

- **Time Complexity:** O(n log n)
- **Space Complexity:** O(n)

## Accepted Solutions

| File | Runtime | Memory | Language |
|------|---------|--------|----------|
| 2026-04-12 19.23.34 - Accepted - runtime 286ms - memory 67MB.pd.py | 286ms | 67MB | Python (Pandas) |
| 2026-04-12 19.30.04 - Accepted - runtime 291ms - memory 67MB.pd.py | 291ms | 67MB | Python (Pandas) |

## Best Code Example

```python
import pandas as pd

def findHeavyAnimals(animals):
    return animals[animals["weight"] > 100].sort_values(by="weight", ascending=False)[["name"]]
```