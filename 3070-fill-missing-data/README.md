# 🚀 LeetCode 3070: Fill Missing Data

![Difficulty: Easy](https://img.shields.io/badge/Difficulty-Easy-brightgreen)
![Topic: Pandas](https://img.shields.io/badge/Topic-Pandas-blue)
![Status: ✅ Solved](https://img.shields.io/badge/Status-Solved-brightgreen)

## 📋 Problem Statement

Fill missing values in the `quantity` column with 0.

---

## 📌 Quick Summary

| | |
|---|---|
| **Problem #** | 3070 |
| **Difficulty** | Easy |
| **Topics** | Pandas |
| **Similar Problems** | [3075. Drop Missing Data](./3075-drop-missing-data) |

---

## 🎯 Example Test Cases

### ✅ Example 1:
```
Input:
products:
+--------+----------+
| product| quantity |
+--------+----------+
| A      | 10       |
| B      | None     |
| C      | 5        |
+--------+----------+

Output:
+--------+----------+
| product| quantity |
+--------+----------+
| A      | 10       |
| B      | 0        |
| C      | 5        |
+--------+----------+
```

---

## ⚠️ Constraints

```
- quantity column may contain missing values (NaN)
- At least one row in the DataFrame
```

---

## 💡 Solution Approaches

### 🔹 Approach 1: pandas fillna() ✅ RECOMMENDED

**Intuition:** Use pandas fillna() method to fill missing values.

| | |
|---|---|
| **Time** | O(n) |
| **Space** | O(n) |

**Step-by-Step:**
1. Use fillna(0) on the quantity column

---

## 📝 Detailed Implementation

### Python ⭐
```python
import pandas as pd

def fillMissingValues(products):
    products["quantity"] = products["quantity"].fillna(0)
    return products
```

---

## 🎯 Complexity Analysis

| Approach | Time | Space | Status |
|----------|------|-------|--------|
| pandas fillna() | O(n) | O(n) | ✅ |

---

## 🔥 All Accepted Solutions

| File Name | Language | Runtime | Memory |
|----------|---------|---------|--------|
| 2026-04-12 19.20.34 - Accepted - runtime 343ms - memory 66.3MB.pd.py | Python | 343ms | 66.3MB |
| 2026-04-12 19.31.04 - Accepted - runtime 271ms - memory 66.2MB.pd.py | Python | 271ms | 66.2MB |

---

## 🎓 Key Takeaways

### ✅ Best Practices
1. Use fillna() for handling missing values

### ❌ Common Mistakes
1. None for this simple problem

---

## 🔗 Related Problems

| # | Problem | Difficulty |
|---|---------|-----------|
| 3075 | Drop Missing Data | Easy |

---

*Made with ❤️ | Last Updated: 2026-04-13*
