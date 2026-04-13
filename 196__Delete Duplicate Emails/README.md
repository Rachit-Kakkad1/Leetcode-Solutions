# 🚀 LeetCode 196: Delete Duplicate Emails

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)
![Database](https://img.shields.io/badge/Database-SQL-orange)
![Acceptance](https://img.shields.io/badge/Acceptance-69.2%25-yellow)

---

## ⚡ The Problem

Delete all **duplicate emails**, keeping only **one** record per email:
- Keep the row with the **smallest id**
- Delete all others with duplicate emails

---

## 💡 The Solution (Pandas - Python)

```python
import pandas as pd

def delete_duplicate_emails(person: pd.DataFrame) -> None:
    person.sort_values(by="id", inplace=True)
    person.drop_duplicates(subset="email", keep="first", inplace=True)
```

### 🔥 How It Works

| Step | Operation |
|------|-----------|
| 1 | `sort_values(by="id")` - Sort by smallest id first |
| 2 | `drop_duplicates(subset="email")` - Keep only unique emails |
| 3 | `keep="first"` - Keep the first (smallest id) occurrence |
| 4 | `inplace=True` - Modify original DataFrame |

**Time Complexity**: O(n log n)  
**Space Complexity**: O(n)

---

## 📊 Example

```
Before:          After sorting:
| id | email     | id | email
|---|---------- |---|----------
| 2 | b@...     | 1 | a@...
| 1 | a@...     | 2 | b@...
| 3 | a@...     | 3 | a@...
| 5 | c@...     | 5 | c@...
| 4 | b@...     | 4 | b@...

After drop_duplicates(keep="first"):
| id | email
|---|----------
| 1 | a@...
| 2 | b@...
| 5 | c@...
```

Deleted: id=3 (duplicate a@...), id=4 (duplicate b@...)

---

## 🎯 SQL Approach

```sql
DELETE FROM person
WHERE id NOT IN (
    SELECT MIN(id)
    FROM person
    GROUP BY email
);
```

---

## 🏆 Stats

| Metric | Value |
|--------|-------|
| Runtime | 56ms |
| Rank | Top 90% |

---

> *"First come, first served - even for duplicates!"* 🗑️