# 🚀 LeetCode 3064: Reshape Data - Concatenate

![Difficulty: Easy](https://img.shields.io/badge/Difficulty-Easy-brightgreen)
![Topic: Pandas](https://img.shields.io/badge/Topic-Pandas-blue)
![Status: ✅ Solved](https://img.shields.io/badge/Status-Solved-brightgreen)

## 📋 Problem Statement

Given two DataFrames with the same columns, concatenate them vertically into one DataFrame.

---

## 📌 Quick Summary

| | |
|---|---|
| **Problem #** | 3064 |
| **Difficulty** | Easy |
| **Topics** | Pandas |
| **Similar Problems** | [3065. Display the First Three Rows](./3065-display-the-first-three-rows) |

---

## 🎯 Example Test Cases

### ✅ Example 1:
```
Input:
df1:
+------+------+
| name | age  |
+------+------+
| Alice| 25   |
+------+------+

df2:
+------+------+
| name | age  |
+------+------+
| Bob  | 30   |
+------+------+

Output:
+------+------+
| name | age  |
+------+------+
| Alice| 25   |
| Bob  | 30   |
+------+------+
```

---

## ⚠️ Constraints

```
- Both DataFrames have the same columns
- At least one row in each DataFrame
```

---

## 💡 Solution Approaches

### 🔹 Approach 1: pandas concat ✅ RECOMMENDED

**Intuition:** Use pandas concat to combine DataFrames vertically.

| | |
|---|---|
| **Time** | O(n + m) |
| **Space** | O(n + m) |

**Step-by-Step:**
1. Use pd.concat([df1, df2]) to combine DataFrames

---

## 📝 Detailed Implementation

### Python ⭐
```python
import pandas as pd
def concatenateTables(df1, df2):
    return pd.concat([df1, df2])
```

---

## 🎯 Complexity Analysis

| Approach | Time | Space | Status |
|----------|------|-------|--------|
| pandas concat | O(n + m) | O(n + m) | ✅ |

---

## 🔥 All Accepted Solutions

| File Name | Language | Runtime | Memory |
|----------|---------|---------|--------|
| 2026-04-12 19.21.39 - Accepted - runtime 337ms - memory 66.8MB.pd.py | Python | 337ms | 66.8MB |
| 2026-04-12 19.30.51 - Accepted - runtime 302ms - memory 66.7MB.pd.py | Python | 302ms | 66.7MB |

---

## 🎓 Key Takeaways

### ✅ Best Practices
1. Use pd.concat() for combining DataFrames

### ❌ Common Mistakes
1. Forgetting to pass as list

---

## 🔗 Related Problems

| # | Problem | Difficulty |
|---|---------|-----------|
| 3065 | Display the First Three Rows | Easy |

---

*Made with ❤️ | Last Updated: 2026-04-13*
