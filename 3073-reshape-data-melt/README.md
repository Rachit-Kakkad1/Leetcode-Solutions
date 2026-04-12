# 🚀 LeetCode 3073: Reshape Data - Melt

![Difficulty: Easy](https://img.shields.io/badge/Difficulty-Easy-brightgreen)
![Topic: Pandas](https://img.shields.io/badge/Topic-Pandas-blue)
![Status: ✅ Solved](https://img.shields.io/badge/Status-Solved-brightgreen)

## 📋 Problem Statement

Reshape data from wide to long format: transform columns quarter_1, quarter_2, quarter_3, quarter_4 into rows with columns product, quarter, sales.

---

## 📌 Quick Summary

| | |
|---|---|
| **Problem #** | 3073 |
| **Difficulty** | Easy |
| **Topics** | Pandas |
| **Similar Problems** | [3072. Reshape Data: Pivot](./3072-reshape-data-pivot) |

---

## 🎯 Example Test Cases

### ✅ Example 1:
```
Input:
report:
+--------+----------+----------+----------+----------+
| product| quarter_1| quarter_2| quarter_3| quarter_4|
+--------+----------+----------+----------+----------+
| Laptop | 1000     | 1500     | 1200     | 1300     |
+--------+----------+----------+----------+----------+

Output:
+--------+----------+----------+-------+
| product| quarter  | sales    |       |
+--------+----------+----------+-------+
| Laptop | quarter_1| 1000     |       |
| Laptop | quarter_2| 1500     |       |
| Laptop | quarter_3| 1200     |       |
| Laptop | quarter_4| 1300     |       |
+--------+----------+----------+-------+
```

---

## ⚠️ Constraints

```
- DataFrame has product column and quarter columns
- At least one row in the DataFrame
```

---

## 💡 Solution Approaches

### 🔹 Approach 1: pandas melt() ✅ RECOMMENDED

**Intuition:** Use pandas melt() function to transform wide to long format.

| | |
|---|---|
| **Time** | O(n) |
| **Space** | O(n) |

**Step-by-Step:**
1. Use melt() with id_vars for identifier columns

---

## 📝 Detailed Implementation

### Python ⭐
```python
import pandas as pd

def meltTable(report):
    return report.melt(id_vars="product", var_name="quarter", value_name="sales")
```

---

## 🎯 Complexity Analysis

| Approach | Time | Space | Status |
|----------|------|-------|--------|
| pandas melt() | O(n) | O(n) | ✅ |

---

## 🔥 All Accepted Solutions

| File Name | Language | Runtime | Memory |
|----------|---------|---------|--------|
| 2026-04-12 19.22.31 - Accepted - runtime 292ms - memory 66.5MB.pd.py | Python | 292ms | 66.5MB |
| 2026-04-12 19.30.14 - Accepted - runtime 298ms - memory 66.7MB.pd.py | Python | 298ms | 66.7MB |

---

## 🎓 Key Takeaways

### ✅ Best Practices
1. Use melt() for wide to long transformation

### ❌ Common Mistakes
1. None for this simple problem

---

## 🔗 Related Problems

| # | Problem | Difficulty |
|---|---------|-----------|
| 3072 | Reshape Data: Pivot | Easy |

---

*Made with ❤️ | Last Updated: 2026-04-13*
