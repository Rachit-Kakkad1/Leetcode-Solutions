# 🚀 LeetCode 175: Combine Two Tables

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)
![Database](https://img.shields.io/badge/Database-SQL-orange)
![Acceptance](https://img.shields.io/badge/Acceptance-65.2%25-yellow)

---

## ⚡ The Problem

Given two tables:

**Person**: `personId`, `firstName`, `lastName`  
**Address**: `personId`, `city`, `state`

Return the **firstName**, **lastName**, **city**, **state** of all persons:
- Include even those without an address
- Use `LEFT JOIN`

---

## 💡 The Solution (Pandas - Python)

```python
import pandas as pd

def combine_two_tables(person, address):
    return person.merge(address, on="personId", how="left")[["firstName", "lastName", "city", "state"]]
```

### 🔥 Key Concepts

| Concept | Explanation |
|---------|-------------|
| `merge()` | SQL JOIN equivalent |
| `how="left"` | Include all from Person |
| `on="personId"` | Join column |
| `[[columns]]` | Select specific columns |

**Time Complexity**: O(m + n)  
**Space Complexity**: O(m + n)

---

## 🎯 SQL Equivalent

```sql
SELECT p.firstName, p.lastName, a.city, a.state
FROM Person p
LEFT JOIN Address a ON p.personId = a.personId;
```

Both produce **identical results**!

---

## 📊 Example

| Person | Address |
|--------|---------|
| {1, "Elon", "Musk"} | {1, "Austin", "TX"} |
| {2, "Bill", "Gates"} | null |

**Result**:
| firstName | lastName | city | state |
|-----------|---------|------|-------|
| Elon | Musk | Austin | TX |
| Bill | Gates | null | null |

---

## 🏆 Stats

| Metric | Value |
|--------|-------|
| Runtime | 56ms |
| Rank | Top 90% |

---

> *"Left join = no person left behind!"* 🤝