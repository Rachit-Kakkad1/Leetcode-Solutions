# 🚀 LeetCode 182: Duplicate Emails

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)
![Database](https://img.shields.io/badge/Database-SQL-orange)
![Acceptance](https://img.shields.io/badge/Acceptance-63.9%25-yellow)

---

## ⚡ The Problem

Find all **duplicate email** addresses in the `Person` table.

A duplicate has the same email appearing **more than once**.

---

## 💡 The Solution (SQL)

```sql
SELECT email
FROM person 
GROUP BY email
HAVING COUNT(email) > 1;
```

### 🔥 How It Works

| Step | Operation |
|------|-----------|
| 1 | `GROUP BY email` - Group all rows by email |
| 2 | `COUNT(email)` - Count occurrences per group |
| 3 | `HAVING COUNT > 1` - Keep only duplicates |

**Time Complexity**: O(n log n)  
**Space Complexity**: O(n)

---

## 🎯 Alternative Approaches

### Using Subquery
```sql
SELECT DISTINCT email
FROM person
WHERE email IN (
    SELECT email
    FROM person
    GROUP BY email
    HAVING COUNT(*) > 1
);
```

### Using Self-Join
```sql
SELECT DISTINCT p1.email
FROM person p1
JOIN person p2 ON p1.email = p2.email
WHERE p1.id != p2.id;
```

---

## 📊 Execution Flow

```
Original Table:          After GROUP BY:
| id | email           | email      | COUNT |
|---|-----------------|-----------|-------|
| 1 | a@leetcode.com | a@leetcode| 2     |
| 2 | b@leetcode.com | b@leetcode| 1     |
| 3 | a@leetcode.com | c@leetcode| 3     |
| 4 | c@leetcode.com |           |
| 5 | c@leetcode.com |           |
| 6 | c@leetcode.com |           |

HAVING COUNT > 1:
| email |
|-------|
| a@leetcode.com |
| c@leetcode.com |
```

---

## 🏆 Stats

| Metric | Value |
|--------|-------|
| Runtime | 305ms |
| Rank | Top 95% |

---

> *"Group by, having, and you shall find duplicates!"* 🔍