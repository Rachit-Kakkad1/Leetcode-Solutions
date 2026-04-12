# 🚀 LeetCode 3074: Select Data

![Difficulty: Easy](https://img.shields.io/badge/Difficulty-Easy-brightgreen)
![Topic: Pandas](https://img.shields.io/badge/Topic-Pandas-blue)
![Status: ✅ Solved](https://img.shields.io/badge/Status-Solved-brightgreen)

## 📋 Problem Statement

Select name and age of the student with student_id = 101.

---

## 📌 Quick Summary

| | |
|---|---|
| **Problem #** | 3074 |
| **Difficulty** | Easy |
| **Topics** | Pandas |
| **Similar Problems** | [3076. Get the Size of a DataFrame](./3076-get-the-size-of-a-dataframe) |

---

## 🎯 Example Test Cases

### ✅ Example 1:
```
Input:
students:
+-----------+------+------+
| student_id| name | age |
+-----------+------+------+
| 101       | Alice| 20  |
| 102       | Bob  | 21  |
+-----------+------+------+

Output:
+------+------+
| name | age  |
+------+------+
| Alice| 20  |
+------+------+
```

---

## ⚠️ Constraints

```
- DataFrame has student_id column
- At least one row in the DataFrame
```

---

## 💡 Solution Approaches

### 🔹 Approach 1: Filter and Select ✅ RECOMMENDED

**Intuition:** Filter and select specific columns.

| | |
|---|---|
| **Time** | O(n) |
| **Space** | O(1) |

**Step-by-Step:**
1. Filter by student_id == 101
2. Select only name and age columns

---

## 📝 Detailed Implementation

### Python ⭐
```python
import pandas as pd

def selectData(students):
    return students[students["student_id"] == 101][["name", "age"]]
```

---

## 🎯 Complexity Analysis

| Approach | Time | Space | Status |
|----------|------|-------|--------|
| Filter + Select | O(n) | O(1) | ✅ |

---

## 🔥 All Accepted Solutions

| File Name | Language | Runtime | Memory |
|----------|---------|---------|--------|
| 2026-04-12 19.11.44 - Accepted - runtime 271ms - memory 66.9MB.pd.py | Python | 271ms | 66.9MB |
| 2026-04-12 19.29.04 - Accepted - runtime 279ms - memory 67MB.pd.py | Python | 279ms | 67MB |

---

## 🎓 Key Takeaways

### ✅ Best Practices
1. Use boolean indexing for filtering
2. Use double brackets for selecting multiple columns

### ❌ Common Mistakes
1. None for this simple problem

---

## 🔗 Related Problems

| # | Problem | Difficulty |
|---|---------|-----------|
| 3076 | Get the Size of a DataFrame | Easy |

---

*Made with ❤️ | Last Updated: 2026-04-13*
