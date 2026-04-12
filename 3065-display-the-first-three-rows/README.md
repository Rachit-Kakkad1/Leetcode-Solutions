# 🚀 LeetCode 3065: Display the First Three Rows

![Difficulty: Easy](https://img.shields.io/badge/Difficulty-Easy-brightgreen)
![Topic: Pandas](https://img.shields.io/badge/Topic-Pandas-blue)
![Status: ✅ Solved](https://img.shields.io/badge/Status-Solved-brightgreen)

## 📋 Problem Statement

Given a DataFrame `employees`, display the first 3 rows.

---

## 📌 Quick Summary

| | |
|---|---|
| **Problem #** | 3065 |
| **Difficulty** | Easy |
| **Topics** | Pandas |
| **Similar Problems** | [3064. Reshape Data: Concatenate](./3064-reshape-data-concatenate) |

---

## 🎯 Example Test Cases

### ✅ Example 1:
```
Input:
employees:
+------+----+
| name |age |
+------+----+
| Alice| 25 |
| Bob  | 30 |
| Carol| 28 |
| Dave | 35 |
+------+----+

Output:
+------+----+
| name |age |
+------+----+
| Alice| 25 |
| Bob  | 30 |
| Carol| 28 |
+------+----+
```

---

## ⚠️ Constraints

```
- At least 3 rows in the DataFrame
```

---

## 💡 Solution Approaches

### 🔹 Approach 1: pandas head() ✅ RECOMMENDED

**Intuition:** Use pandas head() method to get first n rows.

| | |
|---|---|
| **Time** | O(1) |
| **Space** | O(1) |

**Step-by-Step:**
1. Call head(3) on the DataFrame

---

## 📝 Detailed Implementation

### Python ⭐
```python
import pandas as pd

def selectFirstRows(employees):
    return employees.head(3)
```

---

## 🎯 Complexity Analysis

| Approach | Time | Space | Status |
|----------|------|-------|--------|
| pandas head() | O(1) | O(1) | ✅ |

---

## 🔥 All Accepted Solutions

| File Name | Language | Runtime | Memory |
|----------|---------|---------|--------|
| 2026-04-12 19.10.35 - Accepted - runtime 255ms - memory 66.5MB.pd.py | Python | 255ms | 66.5MB |
| 2026-04-12 19.29.40 - Accepted - runtime 287ms - memory 66.1MB.pd.py | Python | 287ms | 66.1MB |

---

## 🎓 Key Takeaways

### ✅ Best Practices
1. Use head() method for getting first n rows

### ❌ Common Mistakes
1. None for this simple problem

---

## 🔗 Related Problems

| # | Problem | Difficulty |
|---|---------|-----------|
| 3064 | Reshape Data: Concatenate | Easy |

---

*Made with ❤️ | Last Updated: 2026-04-13*
