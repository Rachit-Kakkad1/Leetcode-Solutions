# 🚀 LeetCode 3076: Get the Size of a DataFrame

![Difficulty: Easy](https://img.shields.io/badge/Difficulty-Easy-brightgreen)
![Topic: Pandas](https://img.shields.io/badge/Topic-Pandas-blue)
![Status: ✅ Solved](https://img.shields.io/badge/Status-Solved-brightgreen)

## 📋 Problem Statement

Calculate and return the number of rows and columns of a DataFrame as [rows, cols].

---

## 📌 Quick Summary

| | |
|---|---|
| **Problem #** | 3076 |
| **Difficulty** | Easy |
| **Topics** | Pandas |
| **Similar Problems** | [3074. Select Data](./3074-select-data) |

---

## 🎯 Example Test Cases

### ✅ Example 1:
```
Input:
players:
+------+----+
| name |age |
+------+----+
| Alice| 25 |
| Bob  | 30 |
+------+----+

Output: [2, 2]
```

---

## ⚠️ Constraints

```
- At least one row in the DataFrame
```

---

## 💡 Solution Approaches

### 🔹 Approach 1: len() ✅ RECOMMENDED

**Intuition:** Use len() for rows and len(columns) for columns.

| | |
|---|---|
| **Time** | O(1) |
| **Space** | O(1) |

**Step-by-Step:**
1. Get row count using len(DataFrame)
2. Get column count using len(DataFrame.columns)
3. Return as list [rows, cols]

---

## 📝 Detailed Implementation

### Python ⭐
```python
import pandas as pd

def getDataframeSize(players):
    rows = len(players)
    cols = len(players.columns)
    return [rows, cols]
```

---

## 🎯 Complexity Analysis

| Approach | Time | Space | Status |
|----------|------|-------|--------|
| len() | O(1) | O(1) | ✅ |

---

## 🔥 All Accepted Solutions

| File Name | Language | Runtime | Memory |
|----------|---------|---------|--------|
| 2026-04-12 19.10.01 - Accepted - runtime 267ms - memory 66.5MB.pd.py | Python | 267ms | 66.5MB |
| 2026-04-12 19.28.46 - Accepted - runtime 265ms - memory 66.3MB.pd.py | Python | 265ms | 66.3MB |

---

## 🎓 Key Takeaways

### ✅ Best Practices
1. Use len() for row count and len(.columns) for column count

### ❌ Common Mistakes
1. None for this simple problem

---

## 🔗 Related Problems

| # | Problem | Difficulty |
|---|---------|-----------|
| 3074 | Select Data | Easy |

---

*Made with ❤️ | Last Updated: 2026-04-13*
