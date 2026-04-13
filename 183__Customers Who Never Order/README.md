# 🚀 LeetCode 183: Customers Who Never Order

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)
![Database](https://img.shields.io/badge/Database-SQL-orange)
![Acceptance](https://img.shields.io/badge/Acceptance-73.1%25-brightgreen)

---

## ⚡ The Problem

Given two tables:

**Customers**: `id`, `name`  
**Orders**: `id`, `customerId`

Find all customers who **never ordered anything**.

Return: `Customers` (aliased column name)

---

## 💡 The Solution (Pandas - Python)

```python
import pandas as pd

def find_customers(customers: pd.DataFrame, orders: pd.DataFrame) -> pd.DataFrame:
    return customers[~customers["id"].isin(orders["customerId"])][["name"]].rename(columns={"name": "Customers"})
```

### 🔥 How It Works

| Step | Operation |
|------|-----------|
| 1 | `orders["customerId"]` - Get all customer IDs who ordered |
| 2 | `~customers["id"].isin(...)` - Filter customers NOT in orders |
| 3 | `[["name"]]` - Select name column |
| 4 | `rename(columns=...)` - Rename to "Customers" |

**Time Complexity**: O(n + m)  
**Space Complexity**: O(n)

---

## 🎯 SQL Equivalent

```sql
SELECT name AS Customers
FROM Customers
WHERE id NOT IN (
    SELECT DISTINCT customerId
    FROM Orders
);
```

### Alternative: LEFT JOIN
```sql
SELECT c.name AS Customers
FROM Customers c
LEFT JOIN Orders o ON c.id = o.customerId
WHERE o.id IS NULL;
```

---

## 📊 Example

```
Customers:          Orders:
| id | name        | id | customerId |
|----|-------------|---|-------------|
| 1  | Joe         | 1 | 3          |
| 2  | Henry       | 2 | 3          |
| 3  | Sam         |---|-------------|
| 4  | Max         |   |             |

Result:
| Customers |
|-----------|
| Sam |
| Max |

Sam (id=3) and Max (id=4) never ordered!
```

---

## 🏆 Stats

| Metric | Value |
|--------|-------|
| Runtime | 56ms |
| Rank | Top 92% |

---

> *"Some customers just window shop!"* 🛒