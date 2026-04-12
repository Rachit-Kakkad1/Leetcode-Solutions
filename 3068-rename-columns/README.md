# 🚀 LeetCode 3068: Rename Columns

![Difficulty: Easy](https://img.shields.io/badge/Difficulty-Easy-brightgreen)
![Topic: Pandas](https://img.shields.io/badge/Topic-Pandas-blue)
![Status: ✅ Solved](https://img.shields.io/badge/Status-Solved-brightgreen)

## 📋 Problem Statement

Rename columns: id→student_id, first→first_name, last→last_name, age→age_in_years.

---

## 📌 Quick Summary

| | |
|---|---|
| **Problem #** | 3068 |
| **Difficulty** | Easy |
| **Topics** | Pandas |
| **Similar Problems** | [3069. Change Data Type](./3069-change-data-type) |

---

## 🎯 Example Test Cases

### ✅ Example 1:
```
Input:
students:
+----+-------+------+
| id | first | last |
+----+-------+------+
| 1  | John  | Doe  |
+----+-------+------+

Output:
+-----------+-----------+------------+
| student_id| first_name| last_name |
+-----------+-----------+------------+
| 1         | John      | Doe       |
+-----------+-----------+------------+
```

---

## ⚠️ Constraints

```
- DataFrame contains the specified columns
- At least one row in the DataFrame
```

---

## 💡 Solution Approaches

### 🔹 Approach 1: pandas rename ✅ RECOMMENDED

**Intuition:** Use pandas rename with columns dictionary.

| | |
|---|---|
| **Time** | O(n) |
| **Space** | O(n) |

**Step-by-Step:**
1. Use rename() with columns parameter mapping old names to new names

---

## 📝 Detailed Implementation

### Python ⭐
```python
import pandas as pd

def renameColumns(students):
    return students.rename(columns={
        "id": "student_id",
        "first": "first_name",
        "last": "last_name",
        "age": "age_in_years"
    })
```

---

## 🎯 Complexity Analysis

| Approach | Time | Space | Status |
|----------|------|-------|--------|
| pandas rename | O(n) | O(n) | ✅ |

---

## 🔥 All Accepted Solutions

| File Name | Language | Runtime | Memory |
|----------|---------|---------|--------|
| 2026-04-12 19.17.45 - Accepted - runtime 268ms - memory 66.7MB.pd.py | Python | 268ms | 66.7MB |
| 2026-04-12 19.31.54 - Accepted - runtime 304ms - memory 66.4MB.pd.py | Python | 304ms | 66.4MB |

---

## 🎓 Key Takeaways

### ✅ Best Practices
1. Use rename() with columns dictionary for renaming

### ❌ Common Mistakes
1. Confusing columns with index parameter

---

## 🔗 Related Problems

| # | Problem | Difficulty |
|---|---------|-----------|
| 3069 | Change Data Type | Easy |

---

*Made with ❤️ | Last Updated: 2026-04-13*
