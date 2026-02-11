# 🚀 LeetCode 326: Power of Three

![Difficulty: Easy](https://img.shields.io/badge/Difficulty-Easy-brightgreen)
![Topic: Math](https://img.shields.io/badge/Topic-Math-blue)
![Recursion](https://img.shields.io/badge/Topic-Recursion-blue)
![Status: ✅ Solved](https://img.shields.io/badge/Status-Solved-brightgreen)

## 📋 Problem Statement

Given an integer `n`, return `true` if it is a power of three. Otherwise, return `false`.

An integer `n` is a power of three if there exists an integer `x` such that `n == 3^x`.

---

## 📌 Quick Summary

| | |
|---|---|
| **Problem #** | 326 |
| **Difficulty** | Easy |
| **Topics** | Math, Recursion |
| **Companies** | Amazon, Apple |
| **Similar Problems** | [Power of Two](./231-power-of-two) |

---

## 🎯 Example Test Cases

### ✅ Example 1:
```
Input: n = 27
Output: true
Explanation: 3^3 = 27
```

### ✅ Example 2:
```
Input: n = 0
Output: false
```

### ✅ Example 3:
```
Input: n = 45
Output: false
Explanation: 3^3 = 27, 3^4 = 81
```

---

## ⚠️ Constraints

```
-2^31 ≤ n ≤ 2^31 - 1
```

---

## 💡 Solution Approaches

### 🔹 Approach 1: Recursive Division (Optimal) ✅ RECOMMENDED

**Intuition:** Repeatedly divide by 3 until n becomes 1.

| | |
|---|---|
| **Time** | O(log₃ n) |
| **Space** | O(1) |
| **Runtime** | 7ms ✅ |

**Step-by-Step:**
1. If n ≤ 0, return false
2. While n is divisible by 3, divide by 3
3. Return true if result is 1

**Why it works:**
- If n is a power of 3, repeated division will eventually yield 1
- Non-powers of 3 will result in a value ≠ 1

---

## 📝 Detailed Implementation

### JavaScript ⭐
```javascript
function isPowerOfThree(n) {
    if (n <= 0) return false;

    while (n % 3 === 0) {
        n = n / 3;
    }

    return n === 1;
}
```

**Key Points:**
- Iterative division approach
- O(log₃ n) time, O(1) space
- Runtime: 7ms, Memory: 65.8MB

---

## 🎯 Complexity Analysis

| Approach | Time | Space | Status |
|----------|------|-------|--------|
| **Recursive Division** | **O(log₃ n)** | **O(1)** | ✅ Accepted |
| Math trick | O(1) | O(1) | ✅ Accepted |

**Why O(log₃ n)?**
- Each division reduces n by factor of 3

**Why O(1) space?**
- Only uses one variable

---

## 🔥 All Accepted Solutions

| File Name | Language | Runtime | Memory |
|----------|---------|---------|--------|
| 2026-02-11 10.42.44 - Accepted | JavaScript | 8ms 🟢 | 65.3MB |
| 2026-02-11 10.43.13 - Accepted | **JavaScript** | **7ms 🟢** | **65.8MB** |

---

## 🎓 Key Takeaways

### ✅ Best Practices
1. **Use division** to check for power of 3
2. **Handle n ≤ 0** correctly
3. **Edge case**: 1 is a power of 3

### ❌ Common Mistakes
1. Not checking negative numbers
2. Forgetting that 1 is a power of 3
3. Using loops when not needed

### 💡 Follow-up Questions
- How to check power of 4?
- How to optimize using math?

---

## 🔗 Related Problems

| # | Problem | Difficulty | Status |
|---|---------|-----------|--------|
| 231 | Power of Two | Easy | 📝 |
| 342 | Power of Four | Easy | 📝 |

---

## 📈 Success Metrics

![JavaScript](https://img.shields.io/badge/JavaScript-F7DF1E?style=flat&logo=javascript&logoColor=black)

**Total Submissions:** 2️⃣ **Accepted:** 2️⃣ **Acceptance Rate:** 100% ✅

---

*Made with ❤️ | Last Updated: 2026-04-13*
