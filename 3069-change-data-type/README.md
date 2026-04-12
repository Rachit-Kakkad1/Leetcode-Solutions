# 🚀 LeetCode 3069: Change Data Type

![Difficulty: Easy](https://img.shields.io/badge/Difficulty-Easy-brightgreen)
![Topic: Pandas](https://img.shields.io/badge/Topic-Pandas-blue)
![Status: ✅ Solved](https://img.shields.io/badge/Status-Solved-brightgreen)

## 📋 Problem Statement

Convert the `grade` column from float to integer.

---

## 📌 Quick Summary

| | |
|---|---|
| **Problem #** | 3069 |
| **Difficulty** | Easy |
| **Topics** | Pandas |
| **Similar Problems** | [3068. Rename Columns](./3068-rename-columns) |

---

## 🎯 Example Test Cases

### ✅ Example 1:
```
Input:
students:
+-------+-------+
| name  | grade |
+-------+-------+
| Alice | 95.5  |
| Bob   | 87.3  |
+-------+-------+

Output:
+-------+-------+
| name  | grade |
+-------+-------+
| Alice | 95    |
| Bob   | 87    |
+-------+-------+
```

---

## ⚠️ Constraints

```
- grade column contains float values
- At least one row in the DataFrame
```

---

## 💡 Solution Approaches

### 🔹 Approach 1: pandas astype() ✅ RECOMMENDED

**Intuition:** Use pandas astype() method to convert data type.

| | |
|---|---|
| **Time** | O(n) |
| **Space** | O(n) |

**Step-by-Step:**
1. Use astype(int) on the grade column

---

## 📝 Detailed Implementation

### Python ⭐
```python
import pandas as pd

def changeDatatype(students):
    students["grade"] = students["grade"].astype(int)
    return students
```

---

## 🎯 Complexity Analysis

| Approach | Time | Space | Status |
|----------|------|-------|--------|
| pandas astype() | O(n) | O(n) | ✅ |

---

## 🔥 All Accepted Solutions

| File Name | Language | Runtime | Memory |
|----------|---------|---------|--------|
| 2026-04-12 19.20.00 - Accepted - runtime 271ms - memory 66.5MB.pd.py | Python | 271ms | 66.5MB |
| 2026-04-12 19.31.15 - Accepted - runtime 278ms - memory 66.4MB.pd.py | Python | 278ms | 66.4MB |

---

## 🎓 Key Takeaways

### ✅ Best Practices
1. Use astype() for type conversion

### ❌ Common Mistakes
1. None for this simple problem

---

## 🔗 Related Problems

| # | Problem | Difficulty |
|---|---------|-----------|
| 3068 | Rename Columns | Easy |

---

*Made with ❤️ | Last Updated: 2026-04-13*
