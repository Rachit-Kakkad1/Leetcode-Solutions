# 🚀 LeetCode 3066: Create a New Column

![Difficulty: Easy](https://img.shields.io/badge/Difficulty-Easy-brightgreen)
![Topic: Pandas](https://img.shields.io/badge/Topic-Pandas-blue)
![Status: ✅ Solved](https://img.shields.io/badge/Status-Solved-brightgreen)

## 📋 Problem Statement

Create a new column 'bonus' that contains doubled values of the 'salary' column.

---

## 📌 Quick Summary

| | |
|---|---|
| **Problem #** | 3066 |
| **Difficulty** | Easy |
| **Topics** | Pandas |
| **Similar Problems** | [3067. Modify Columns](./3067-modify-columns) |

---

## 🎯 Example Test Cases

### ✅ Example 1:
```
Input:
employees:
+------+--------+
| name | salary |
+------+--------+
| Alice| 100    |
| Bob  | 200    |
+------+--------+

Output:
+------+--------+-------+
| name | salary | bonus |
+------+--------+-------+
| Alice| 100    | 200   |
| Bob  | 200    | 400   |
+------+--------+-------+
```

---

## ⚠️ Constraints

```
- salary column contains numeric values
- At least one row in the DataFrame
```

---

## 💡 Solution Approaches

### 🔹 Approach 1: Direct Column Assignment ✅ RECOMMENDED

**Intuition:** Assign new column directly to the DataFrame by multiplying the salary column.

| | |
|---|---|
| **Time** | O(n) |
| **Space** | O(n) |

**Step-by-Step:**
1. Create new 'bonus' column by multiplying 'salary' column by 2

---

## 📝 Detailed Implementation

### Python ⭐
```python
import pandas as pd

def createBonusColumn(employees):
    employees["bonus"] = employees["salary"] * 2
    return employees
```

---

## 🎯 Complexity Analysis

| Approach | Time | Space | Status |
|----------|------|-------|--------|
| Direct Assignment | O(n) | O(n) | ✅ |

---

## 🔥 All Accepted Solutions

| File Name | Language | Runtime | Memory |
|----------|---------|---------|--------|
| 2026-04-12 19.12.25 - Accepted - runtime 301ms - memory 66.3MB.pd.py | Python | 301ms | 66.3MB |
| 2026-04-12 19.29.51 - Accepted - runtime 280ms - memory 66.3MB.pd.py | Python | 280ms | 66.3MB |

---

## 🎓 Key Takeaways

### ✅ Best Practices
1. Use direct column assignment for creating new columns

### ❌ Common Mistakes
1. None for this simple problem

---

## 🔗 Related Problems

| # | Problem | Difficulty |
|---|---------|-----------|
| 3067 | Modify Columns | Easy |

---

*Made with ❤️ | Last Updated: 2026-04-13*
