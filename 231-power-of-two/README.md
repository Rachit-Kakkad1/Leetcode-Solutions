# 🚀 LeetCode 231: Power of Two

![Difficulty: Easy](https://img.shields.io/badge/Difficulty-Easy-brightgreen)
![Topic: Math](https://img.shields.io/badge/Topic-Math-blue)
![Bit Manipulation](https://img.shields.io/badge/Topic-Bit_Manipulation-blue)
![Recursion](https://img.shields.io/badge/Topic-Recursion-blue)
![Status: ✅ Solved](https://img.shields.io/badge/Status-Solved-brightgreen)

## 📋 Problem Statement

Given an integer `n`, return `true` if it is a power of two. Otherwise, return `false`.

An integer `n` is a power of two if there exists an integer `x` such that `n == 2^x`.

---

## 📌 Quick Summary

| | |
|---|---|
| **Problem #** | 231 |
| **Difficulty** | Easy |
| **Topics** | Math, Bit Manipulation, Recursion |
| **Companies** | Amazon, Apple, Google |
| **Similar Problems** | [Power of Three](./326-power-of-three) |

---

## 🎯 Example Test Cases

### ✅ Example 1:
```
Input: n = 1
Output: true
Explanation: 2^0 = 1
```

### ✅ Example 2:
```
Input: n = 16
Output: true
Explanation: 2^4 = 16
```

### ✅ Example 3:
```
Input: n = 3
Output: false
```

---

## ⚠️ Constraints

```
-2^31 ≤ n ≤ 2^31 - 1
```

---

## 💡 Solution Approaches

### 🔹 Approach 1: Bit Manipulation (Optimal) ✅ RECOMMENDED

**Intuition:** Powers of two have only one bit set in binary representation.

| | |
|---|---|
| **Time** | O(1) |
| **Space** | O(1) |
| **Runtime** | 0ms ✅ |

**Step-by-Step:**
1. Check if n > 0
2. Check if n & (n - 1) == 0 (only one bit set)

**Why it works:**
- Powers of two in binary: 1, 10, 100, 1000...
- n & (n - 1) clears the lowest set bit
- If result is 0, only one bit was set

---

### 🔹 Approach 2: Recursive Division (Alternative)

Repeatedly divide by 2 until n becomes 1.

| | |
|---|---|
| **Time** | O(log n) |
| **Space** | O(1) |

---

## 📝 Detailed Implementation

### JavaScript ⭐
```javascript
var isPowerOfTwo = function(n) {
    return n > 0 && (n & (n - 1)) === 0;
};
```

**Key Points:**
- Bit manipulation trick
- O(1) time and space
- Runtime: 0ms, Memory: 55.7MB

---

### C ⭐
```c
bool isPowerOfTwo(int n) {
    return n > 0 && (n & (n - 1)) == 0;
}
```

---

## 🎯 Complexity Analysis

| Approach | Time | Space | Status |
|----------|------|-------|--------|
| **Bit Manipulation** | **O(1)** | **O(1)** | ✅ Accepted |
| Recursive Division | O(log n) | O(1) | ✅ Accepted |

**Why O(1)?**
- Single bitwise operation

**Why O(1) space?**
- Only uses a few variables

---

## 🔥 All Accepted Solutions

| File Name | Language | Runtime | Memory |
|----------|---------|---------|--------|
| 2025-11-17 14.18.12 - Accepted | C | 3ms 🟢 | 7.8MB |
| 2025-11-17 14.19.17 - Accepted | C | 0ms 🟢 | 7.7MB |
| 2025-11-17 14.19.49 - Accepted | **JavaScript** | **0ms 🟢** | **55.7MB** |

---

## 🎓 Key Takeaways

### ✅ Best Practices
1. **Use bit manipulation** for O(1) solution
2. **Understand binary representation** of powers of 2
3. **Check n > 0** first

### ❌ Common Mistakes
1. Not checking negative numbers
2. Forgetting that 1 is a power of 2
3. Using loops when bitwise works

### 💡 Follow-up Questions
- How to check power of 3?
- How to find the exponent?

---

## 🔗 Related Problems

| # | Problem | Difficulty | Status |
|---|---------|-----------|--------|
| 326 | Power of Three | Easy | 📝 |
| 342 | Power of Four | Easy | 📝 |
| 191 | Number of 1 Bits | Easy | 📝 |

---

## 📈 Success Metrics

![C](https://img.shields.io/badge/C-A8B9CC?style=flat&logo=c&logoColor=white)
![JavaScript](https://img.shields.io/badge/JavaScript-F7DF1E?style=flat&logo=javascript&logoColor=black)

**Total Submissions:** 3️⃣ **Accepted:** 3️⃣ **Acceptance Rate:** 100% ✅

---

*Made with ❤️ | Last Updated: 2026-04-13*
