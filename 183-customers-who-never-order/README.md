# 183 - Customers Who Never Order

**Difficulty:** Easy  
**Problem Link:** [customers-who-never-order](https://leetcode.com/problems/customers-who-never-order/)

## Problem Description

Table: `Customers`

| Column Name | Type    |
|-------------|---------|
| id          | int     |
| name        | varchar |

- `id` is the primary key.
- Each row indicates the ID and name of a customer.

Table: `Orders`

| Column Name | Type |
|-------------|------|
| id          | int  |
| customerId  | int  |

- `id` is the primary key.
- `customerId` is a foreign key referencing the `Customers` table.

Write a solution to find all customers who never order anything.

## Solution Approach

Using pandas DataFrame operations:
1. Filter customers whose ID is NOT in the orders' customerId column
2. Select and rename the result

## Complexity Analysis

- **Time Complexity:** O(n + m) where n = customers count, m = orders count
- **Space Complexity:** O(m) for storing customer IDs from orders

## Accepted Solutions

| File | Runtime | Memory | Language |
|------|---------|--------|----------|
| 2026-04-11 14.54.08 - Accepted - runtime 273ms - memory 67.3MB.pd.py | 273ms | 67.3MB | Python (Pandas) |

## Best Code Example

```python
import pandas as pd

def find_customers(customers: pd.DataFrame, orders: pd.DataFrame) -> pd.DataFrame:
    return customers[~customers["id"].isin(orders["customerId"])][["name"]].rename(columns={"name": "Customers"})
```