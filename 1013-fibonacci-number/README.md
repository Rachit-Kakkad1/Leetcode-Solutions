# 🚀 LeetCode 1013: Fibonacci Number

![Difficulty: Easy](https://img.shields.io/badge/Difficulty-Easy-brightgreen)
![Topic: Math](https://img.shields.io/badge/Topic-Math-blue)
![Dynamic Programming](https://img.shields.io/badge/Topic-Dynamic_Programming-blue)
![Recursion](https://img.shields.io/badge/Topic-Recursion-blue)
![Memoization](https://img.shields.io/badge/Topic-Memoization-blue)
![Status: ✅ Solved](https://img.shields.io/badge/Status-Solved-brightgreen)

## 📋 Problem Statement

The **Fibonacci numbers**, commonly denoted `F(n)` form a sequence, called the **Fibonacci sequence**, such that each number is the sum of the two preceding ones, starting from `0` and `1`. That is:

```
F(0) = 0, F(1) = 1
F(n) = F(n - 1) + F(n - 2), for n > 1.
```

Given `n`, calculate `F(n)`.

---

## 📌 Quick Summary

| | |
|---|---|
| **Problem #** | 1013 |
| **Difficulty** | Easy |
| **Topics** | Math, Dynamic Programming, Recursion, Memoization |
| **Companies** | Amazon, Apple |
| **Similar Problems** | [Climbing Stairs](./70-climbing-stairs) |

---

## 🎯 Example Test Cases

### ✅ Example 1:
```
Input: n = 2
Output: 1
Explanation: F(2) = F(1) + F(0) = 1 + 0 = 1.
```

### ✅ Example 2:
```
Input: n = 3
Output: 2
Explanation: F(3) = F(2) + F(1) = 1 + 1 = 2.
```

### ✅ Example 3:
```
Input: n = 4
Output: 3
Explanation: F(4) = F(3) + F(2) = 2 + 1 = 3.
```

---

## ⚠️ Constraints

```
0 ≤ n ≤ 30
```

---

## 💡 Solution Approaches

### 🔹 Approach 1: Pre-computed Array (Optimal) ✅ RECOMMENDED

**Intuition:** Since n ≤ 30, store all Fibonacci numbers and return directly.

| | |
|---|---|
| **Time** | O(1) |
| **Space** | O(1) |
| **Runtime** | 49ms ✅ |

**Step-by-Step:**
1. Create a pre-computed array of Fibonacci numbers
2. Return the value at index n

**Why it works:**
- F(30) = 832040 fits in 32-bit integer
- O(1) lookup time

---

### 🔹 Approach 2: Iterative (Alternative)

Use two variables to track previous values.

| | |
|---|---|
| **Time** | O(n) |
| **Space** | O(1) |

---

## 📝 Detailed Implementation

### JavaScript ⭐
```javascript
var fib = function(n) {
    const f = [
        0, 1, 1, 2, 3, 5, 8, 13, 21, 34,
        55, 89, 144, 233, 377, 610, 987, 1597,
        2584, 4181, 6765, 10946, 17711, 28657,
        46368, 75025, 121393, 196418, 317811,
        514229, 832040
    ];
    return f[n];
};
```

**Key Points:**
- Pre-computed array lookup
- O(1) time and space
- Runtime: 49ms, Memory: 54.1MB

---

## 🎯 Complexity Analysis

| Approach | Time | Space | Status |
|----------|------|-------|--------|
| **Pre-computed Array** | **O(1)** | **O(1)** | ✅ Accepted |
| Iterative | O(n) | O(1) | ✅ Accepted |
| Recursive | O(2^n) | O(n) | ❌ TLE |

**Why O(1)?**
- Direct array lookup

**Why O(1) space?**
- Pre-computed values are constant

---

## 🔥 All Accepted Solutions

| File Name | Language | Runtime | Memory |
|----------|---------|---------|--------|
| 2025-11-18 09.03.04 - Accepted | JavaScript | 49ms 🟡 | 54.1MB |
| 2025-11-18 09.03.45 - Accepted | JavaScript | 57ms 🟡 | 52.6MB |
| 2025-11-18 09.04.14 - Accepted | **JavaScript** | **50ms 🟡** | **54.2MB** |

---

## 🎓 Key Takeaways

### ✅ Best Practices
1. **Pre-computed array** for small n
2. **Iterative approach** avoids recursion overhead
3. **Memoization** for larger n

### ❌ Common Mistakes
1. Using naive recursion (exponential time)
2. Not handling n = 0
3. Not handling large n

### 💡 Follow-up Questions
- How to calculate for large n (matrix exponentiation)?
- How to find nth Fibonacci modulo m?

---

## 🔗 Related Problems

| # | Problem | Difficulty | Status |
|---|---------|-----------|--------|
| 70 | Climbing Stairs | Easy | 📝 |
| 509 | Fibonacci Number | Easy | 📝 |
| 1137 | N-th Tribonacci Number | Easy | 📝 |

---

## 📈 Success Metrics

![JavaScript](https://img.shields.io/badge/JavaScript-F7DF1E?style=flat&logo=javascript&logoColor=black)

**Total Submissions:** 3️⃣ **Accepted:** 3️⃣ **Acceptance Rate:** 100% ✅

---

*Made with ❤️ | Last Updated: 2026-04-13*
