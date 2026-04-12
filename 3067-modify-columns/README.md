# 🚀 LeetCode 3067: Modify Columns

![Difficulty: Easy](https://img.shields.io/badge/Difficulty-Easy-brightgreen)
![Topic: Pandas](https://img.shields.io/badge/Topic-Pandas-blue)
![Status: ✅ Solved](https://img.shields.io/badge/Status-Solved-brightgreen)

## 📋 Problem Statement

Modify the `salary` column by multiplying each salary by 2.

---

## 📌 Quick Summary

| | |
|---|---|
| **Problem #** | 3067 |
| **Difficulty** | Easy |
| **Topics** | Pandas |
| **Similar Problems** | [3066. Create a New Column](./3066-create-a-new-column) |

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
+------+--------+
| name | salary |
+------+--------+
| Alice| 200    |
| Bob  | 400    |
+------+--------+
```

---

## ⚠️ Constraints

```
- salary column contains numeric values
- At least one row in the DataFrame
```

---

## 💡 Solution Approaches

### 🔹 Approach 1: Direct Column Modification ✅ RECOMMENDED

**Intuition:** Directly modify the column by multiplication.

| | |
|---|---|
| **Time** | O(n) |
| **Space** | O(n) |

**Step-by-Step:**
1. Multiply salary column by 2 and assign back

---

## 📝 Detailed Implementation

### Python ⭐
```python
import pandas as pd

def modifySalaryColumn(employees):
    employees["salary"] = employees["salary"] * 2
    return employees
```

---

## 🎯 Complexity Analysis

| Approach | Time | Space | Status |
|----------|------|-------|--------|
| Direct Modification | O(n) | O(n) | ✅ |

---

## 🔥 All Accepted Solutions

| File Name | Language | Runtime | Memory |
|----------|---------|---------|--------|
| 2026-04-12 19.17.17 - Accepted - runtime 298ms - memory 66.1MB.pd.py | Python | 298ms | 66.1MB |
| 2026-04-12 19.31.44 - Accepted - runtime 287ms - memory 66.1MB.pd.py | Python | 287ms | 66.1MB |

---

## 🎓 Key Takeaways

### ✅ Best Practices
1. Use direct column assignment for modifying columns

### ❌ Common Mistakes
1. None for this simple problem

---

## 🔗 Related Problems

| # | Problem | Difficulty |
|---|---------|-----------|
| 3066 | Create a New Column | Easy |

---

*Made with ❤️ | Last Updated: 2026-04-13*
