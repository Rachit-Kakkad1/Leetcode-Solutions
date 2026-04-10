# 🚀 LeetCode 182: Duplicate Emails

![Difficulty: Easy](https://img.shields.io/badge/Difficulty-Easy-brightgreen)
![Topic: Database](https://img.shields.io/badge/Topic-Database-blue)
![Status: ✅ Solved](https://img.shields.io/badge/Status-Solved-brightgreen)

## 📋 Problem Statement

Write a SQL query to find all duplicate emails in the Person table.

---

## 📌 Quick Summary

| | |
|---|---|
| **Problem #** | 182 |
| **Difficulty** | Easy |
| **Topics** | Database |
| **Similar Problems** | [196. Delete Duplicate Emails](./196-delete-duplicate-emails) |

---

## 🎯 Example Test Cases

### ✅ Example 1:
```
Input:
+----+---------+
| Id | Email   |
+----+---------+
| 1  | a@b.com |
| 2  | c@d.com |
| 3  | a@b.com |
+----+---------+

Output:
+---------+
| Email   |
+---------+
| a@b.com |
+---------+
```

---

## ⚠️ Constraints

```
- The Person table may have duplicate emails
- At least one row with duplicate email exists
```

---

## 💡 Solution Approaches

### 🔹 Approach 1: GROUP BY with HAVING ✅ RECOMMENDED

**Intuition:** Group by email and count occurrences. Keep only groups with count > 1.

| | |
|---|---|
| **Time** | O(n) |
| **Space** | O(n) |

**Step-by-Step:**
1. Group the table by Email column
2. Use HAVING to filter groups with COUNT(Email) > 1

---

## 📝 Detailed Implementation

### SQL ⭐
```sql
SELECT email
FROM person 
GROUP BY email
HAVING COUNT(email) > 1;
```

---

## 🎯 Complexity Analysis

| Approach | Time | Space | Status |
|----------|------|-------|--------|
| GROUP BY + HAVING | O(n) | O(n) | ✅ |

---

## 🔥 All Accepted Solutions

| File Name | Language | Runtime | Memory |
|----------|---------|---------|--------|
| 2026-04-10 18.01.55 - Accepted - runtime 353ms - memory 0.0B.sql | SQL | 353ms | 0B |

---

## 🎓 Key Takeaways

### ✅ Best Practices
1. Use GROUP BY for aggregation
2. Use HAVING for filtered aggregation

### ❌ Common Mistakes
1. Using WHERE instead of HAVING (WHERE filters rows before grouping)

---

## 🔗 Related Problems

| # | Problem | Difficulty |
|---|---------|-----------|
| 196 | Delete Duplicate Emails | Easy |

---

*Made with ❤️ | Last Updated: 2026-04-13*
