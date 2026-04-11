# 175. Combine Two Tables

**Difficulty: Easy**

## Problem Description

Write a solution to report the first name, last name, city, and state of each person in the Person table. If the address of a personId is not present in the Address table, report null instead.

**Person Table:**
| Column Name | Type |
|------------|------|
| personId | int |
| lastName | string |
| firstName | string |

**Address Table:**
| Column Name | Type |
|------------|------|
| addressId | int |
| personId | int |
| city | string |
| state | string |

**Example:**
```
Input:
Person: [[1, "Wang", "Allen"], [2, "Alice", "Bob"]]
Address: [[1, 2, "New York City", "New York"]]

Output:
[["Allen", "Wang", null, null], ["Bob", "Alice", "New York City", "New York"]]
```

## Solution Approach

We use a **LEFT JOIN** to combine the Person and Address tables:
1. Merge the Person table with the Address table on personId.
2. Use left join to include all persons, even those without addresses.
3. Select only the required columns in the correct order.

## Complexity Analysis

- **Time Complexity:** O(n + m) where n and m are the sizes of the tables.
- **Space Complexity:** O(n + m) for the result DataFrame.

## Accepted Solution Files

| File | Language | Runtime | Memory |
|------|----------|----------|--------|
| 2026-04-11 14.49.44 - Accepted - runtime 268ms - memory 68.4MB.pd.py | Python (Pandas) | 268ms | 68.4MB |

## Best Code Example

```python
import pandas as pd

def combine_two_tables(person, address):
    return person.merge(address, on="personId", how="left")[["firstName", "lastName", "city", "state"]]
```