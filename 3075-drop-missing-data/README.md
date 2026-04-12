# 🚀 LeetCode 3075: Drop Missing Data

![Difficulty: Easy](https://img.shields.io/badge/Difficulty-Easy-brightgreen)
![Topic: Pandas](https://img.shields.io/badge/Topic-Pandas-blue)
![Status: ✅ Solved](https://img.shields.io/badge/Status-Solved-brightgreen)

## 📋 Problem Statement

Remove rows with missing values in the `name` column.

---

## 📌 Quick Summary

| | |
|---|---|
| **Problem #** | 3075 |
| **Difficulty** | Easy |
| **Topics** | Pandas |
| **Similar Problems** | [3070. Fill Missing Data](./3070-fill-missing-data) |

---

## 🎯 Example Test Cases

### ✅ Example 1:
```
Input:
students:
+------+----+
| name |age |
+------+----+
| Alice| 25 |
| None | 30 |
| Bob  | 28 |
+------+----+

Output:
+------+----+
| name |age |
+------+----+
| Alice| 25 |
| Bob  | 28 |
+------+----+
```

---

## ⚠️ Constraints

```
- name column may contain missing values (NaN)
- At least one row in the DataFrame
```

---

## 💡 Solution Approaches

### 🔹 Approach 1: pandas dropna() ✅ RECOMMENDED

**Intuition:** Use pandas dropna() with subset parameter.

| | |
|---|---|
| **Time** | O(n) |
| **Space** | O(n) |

**Step-by-Step:**
1. Use dropna(subset=["name"]) to remove rows with missing name

---

## 📝 Detailed Implementation

### Python ⭐
```python
import pandas as pd

def dropMissingData(students):
    return students.dropna(subset=["name"])
```

---

## 🎯 Complexity Analysis

| Approach | Time | Space | Status |
|----------|------|-------|--------|
| pandas dropna() | O(n) | O(n) | ✅ |

---

## 🔥 All Accepted Solutions

| File Name | Language | Runtime | Memory |
|----------|---------|---------|--------|
| 2026-04-12 19.15.11 - Accepted - runtime 272ms - memory 66.7MB.pd.py | Python | 272ms | 66.7MB |
| 2026-04-12 19.29.16 - Accepted - runtime 295ms - memory 67MB.pd.py | Python | 295ms | 67MB |

---

## 🎓 Key Takeaways

### ✅ Best Practices
1. Use dropna() with subset for column-specific missing value removal

### ❌ Common Mistakes
1. None for this simple problem

---

## 🔗 Related Problems

| # | Problem | Difficulty |
|---|---------|-----------|
| 3070 | Fill Missing Data | Easy |

---

*Made with ❤️ | Last Updated: 2026-04-13*
