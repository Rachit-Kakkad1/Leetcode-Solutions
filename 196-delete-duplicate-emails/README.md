# 196 - Delete Duplicate Emails

**Difficulty:** Easy

**Link:** [Delete Duplicate Emails - LeetCode](https://leetcode.com/problems/delete-duplicate-emails/)

## Problem Description

Table: `Person`

```
+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| id          | int     |
| email       | varchar |
+-------------+---------+
```

id is the primary key (column with unique values) for this table. Each row of this table contains an email. The emails will not contain uppercase letters.

Write a solution to **delete** all duplicate emails, keeping only one unique email with the smallest `id`.

## Example Test Cases

### Example 1:
```
Input: 
Person table:
+----+------------------+
| id | email            |
+----+------------------+
| 1  | john@example.com |
| 2  | bob@example.com  |
| 3  | john@example.com |
+----+------------------+
Output: 
+----+------------------+
| id | email            |
+----+------------------+
| 1  | john@example.com |
| 2  | bob@example.com  |
+----+------------------+
Explanation: john@example.com is repeated two times. We keep the row with smallest Id = 1.
```

## Solution Approach

### Algorithm Explanation

For Python/Pandas solution:

1. Sort the DataFrame by id (ascending) to keep smallest id first
2. Use drop_duplicates to keep first occurrence of each email
3. Modify in place

### Step-by-Step Logic

1. Sort person by "id" in ascending order
2. Drop duplicates based on "email" column, keeping first occurrence
3. The operation is done in-place as required

### Why It Works

- Sorting by id ensures smallest id is first for each email
- keep="first" keeps the first occurrence (smallest id after sort)
- In-place modification satisfies problem requirement

## Complexity Analysis

- **Time Complexity:** O(n log n) - Sorting dominates
- **Space Complexity:** O(n) - Pandas may use extra space for operations

## Accepted Solutions

| File Name | Language | Runtime | Memory |
|-----------|----------|---------|--------|
| 2026-04-11 15.01.13 - Accepted - runtime 269ms - memory 67.4MB.pd.py | Python (Pandas) | 269ms | 67.4MB |

## Code Example (Best Solution - Pandas)

```python
import pandas as pd

def delete_duplicate_emails(person: pd.DataFrame) -> None:
    person.sort_values(by="id", inplace=True)
    person.drop_duplicates(subset="email", keep="first", inplace=True)
```

**Runtime:** 269ms | **Memory:** 67.4MB