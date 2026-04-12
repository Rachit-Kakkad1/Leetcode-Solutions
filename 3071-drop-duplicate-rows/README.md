# 🚀 LeetCode 3071: Drop Duplicate Rows

![Difficulty: Easy](https://img.shields.io/badge/Difficulty-Easy-brightgreen)
![Topic: Pandas](https://img.shields.io/badge/Topic-Pandas-blue)
![Status: ✅ Solved](https://img.shields.io/badge/Status-Solved-brightgreen)

## 📋 Problem Statement

Remove duplicate rows based on the `email` column, keeping only the first occurrence.

---

## 📌 Quick Summary

| | |
|---|---|
| **Problem #** | 3071 |
| **Difficulty** | Easy |
| **Topics** | Pandas |
| **Similar Problems** | [3075. Drop Missing Data](./3075-drop-missing-data) |

---

## 🎯 Example Test Cases

### ✅ Example 1:
```
Input:
customers:
+-------+-------+
| name  | email |
+-------+-------+
| Alice | a@b   |
| Bob   | c@d   |
| Alice | a@b   |
+-------+-------+

Output:
+-------+-------+
| name  | email |
+-------+-------+
| Alice | a@b   |
| Bob   | c@d   |
+-------+-------+
```

---

## ⚠️ Constraints

```
- email column contains string values
- At least one row in the DataFrame
```

---

## 💡 Solution Approaches

### 🔹 Approach 1: pandas drop_duplicates ✅ RECOMMENDED

**Intuition:** Use pandas drop_duplicates with subset parameter.

| | |
|---|---|
| **Time** | O(n) |
| **Space** | O(n) |

**Step-by-Step:**
1. Use drop_duplicates(subset="email", keep="first")

---

## 📝 Detailed Implementation

### Python ⭐
```python
import pandas as pd

def dropDuplicateEmails(customers):
    return customers.drop_duplicates(subset="email", keep="first")
```

---

## 🎯 Complexity Analysis

| Approach | Time | Space | Status |
|----------|------|-------|--------|
| pandas drop_duplicates | O(n) | O(n) | ✅ |

---

## 🔥 All Accepted Solutions

| File Name | Language | Runtime | Memory |
|----------|---------|---------|--------|
| 2026-04-12 19.14.33 - Accepted - runtime 285ms - memory 66.8MB.pd.py | Python | 285ms | 66.8MB |
| 2026-04-12 19.31.35 - Accepted - runtime 269ms - memory 66.6MB.pd.py | Python | 269ms | 66.6MB |

---

## 🎓 Key Takeaways

### ✅ Best Practices
1. Use drop_duplicates() with subset for column-specific deduplication

### ❌ Common Mistakes
1. None for this simple problem

---

## 🔗 Related Problems

| # | Problem | Difficulty |
|---|---------|-----------|
| 3075 | Drop Missing Data | Easy |

---

*Made with ❤️ | Last Updated: 2026-04-13*
