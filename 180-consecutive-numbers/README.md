# 180. Consecutive Numbers

**Difficulty: Medium (SQL)**

## Problem Description

Find all numbers that appear at least three times consecutively in the Logs table.

**Logs Table:**
| Column Name | Type |
|-------------|------|
| id | int |
| num | varchar |

The id is an autoincrement column starting from 1.

**Example:**
```
Input: Logs table
+----+-----+
| id | num |
+----+-----+
| 1  | 1   |
| 2  | 1   |
| 3  | 1   |
| 4  | 2   |
| 5  | 1   |
| 6  | 2   |
| 7  | 2   |
+----+-----+

Output:
+-----------------+
| ConsecutiveNums |
+-----------------+
| 1               |
+-----------------+
```

## Solution Approach

We use self-join to compare consecutive rows:
1. Join the Logs table with itself twice to check for 3 consecutive rows.
2. Use conditions to ensure the numbers are the same and ids are consecutive.
3. Use DISTINCT to eliminate duplicates.

## Complexity Analysis

- **Time Complexity:** O(n) for the scan.
- **Space Complexity:** O(n) for result set.

## Accepted Solution Files

| File | Language | Runtime | Memory |
|------|----------|----------|--------|
| 2026-03-07 23.44.58 - Accepted - runtime 700ms - memory 0.0B.sql | SQL | 700ms | 0B |
| 2026-03-07 23.45.44 - Accepted - runtime 517ms - memory 0.0B.sql | SQL | 517ms | 0B |

## Best Code Example

```sql
SELECT DISTINCT l1.num as ConsecutiveNums
FROM Logs l1
JOIN Logs l2 ON l1.id = l2.id - 1
JOIN Logs l3 ON l2.id = l3.id - 1
WHERE l1.num = l2.num AND l2.num = l3.num;
```