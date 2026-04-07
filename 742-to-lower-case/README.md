# 🚀 LeetCode 742: To Lower Case

![Difficulty: Easy](https://img.shields.io/badge/Difficulty-Easy-brightgreen)
![Topic: String](https://img.shields.io/badge/Topic-String-blue)
![Status: ✅ Solved](https://img.shields.io/badge/Status-Solved-brightgreen)

## 📋 Problem Statement

Given a string `s`, return the string after replacing every uppercase letter with the same lowercase letter.

---

## 📌 Quick Summary

| | |
|---|---|
| **Problem #** | 742 |
| **Difficulty** | Easy |
| **Topics** | String |
| **Similar Problems** | [709. To Lower Case](./709-to-lower-case) |

---

## 🎯 Example Test Cases

### ✅ Example 1:
```
Input: s = "Hello"
Output: "hello"
```

### ✅ Example 2:
```
Input: s = "here"
Output: "here"
```

### ✅ Example 3:
```
Input: s = "LOVELY"
Output: "lovely"
```

---

## ⚠️ Constraints

```
- 0 <= s.length <= 100
- s consists of printable ASCII characters
```

---

## 💡 Solution Approaches

### 🔹 Approach 1: Built-in Method ✅ RECOMMENDED

**Intuition:** Use built-in toLowerCase() method.

| | |
|---|---|
| **Time** | O(n) |
| **Space** | O(n) |

**Step-by-Step:**
1. Call toLowerCase() method on the string

---

## 📝 Detailed Implementation

### JavaScript ⭐
```javascript
function toLowerCase(s) {
    return s.toLowerCase();
}
```

---

## 🎯 Complexity Analysis

| Approach | Time | Space | Status |
|----------|------|-------|--------|
| Built-in Method | O(n) | O(n) | ✅ |

---

## 🔥 All Accepted Solutions

| File Name | Language | Runtime | Memory |
|----------|---------|---------|--------|
| 2026-04-07 18.06.29 - Accepted - runtime 0ms - memory 53.1MB.js | JavaScript | 0ms | 53.1MB |

---

## 🎓 Key Takeaways

### ✅ Best Practices
1. Use built-in methods when available

### ❌ Common Mistakes
1. None for this simple problem

---

## 🔗 Related Problems

| # | Problem | Difficulty |
|---|---------|-----------|
| 709 | To Lower Case | Easy |

---

*Made with ❤️ | Last Updated: 2026-04-13*
