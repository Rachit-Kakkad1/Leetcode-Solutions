# 🚀 LeetCode 342: Power of Four

![Difficulty: Easy](https://img.shields.io/badge/Difficulty-Easy-brightgreen)
![Topic: Math](https://img.shields.io/badge/Topic-Math-blue)
![Bit Manipulation](https://img.shields.io/badge/Topic-Bit_Manipulation-blue)
![Status: ✅ Solved](https://img.shields.io/badge/Status-Solved-brightgreen)

## 📋 Problem Statement

Given an integer `n`, return `true` if it is a power of four. Otherwise, return `false`.

An integer `n` is a power of four if there exists an integer `x` such that `n == 4^x`.

---

## 📌 Quick Summary

| | |
|---|---|
| **Problem #** | 342 |
| **Difficulty** | Easy |
| **Topics** | Math, Bit Manipulation |
| **Companies** | Amazon, Apple, Google |
| **Similar Problems** | [Power of Two](./231-power-of-two) |

---

## 🎯 Example Test Cases

### ✅ Example 1:
```
Input: n = 16
Output: true
Explanation: 4^2 = 16
```

### ✅ Example 2:
```
Input: n = 5
Output: false
```

### ✅ Example 3:
```
Input: n = 1
Output: true
Explanation: 4^0 = 1
```

---

## ⚠️ Constraints

```
-2^31 ≤ n ≤ 2^31 - 1
```

---

## 💡 Solution Approaches

### 🔹 Approach 1: Bit Manipulation (Optimal) ✅ RECOMMENDED

**Intuition:** Use two bit checks - one for single bit and one for proper position.

| | |
|---|---|
| **Time** | O(1) |
| **Space** | O(1) |
| **Runtime** | 0ms ✅ |

**Step-by-Step:**
1. Check if n > 0
2. Check if (n & (n - 1)) === 0 (only one bit set)
3. Check if (n & 0x55555555) !== 0 (bit is in odd position)

**Why it works:**
- Powers of 4 have exactly one bit set
- That bit must be in an "odd" position (0x55555555 = 101010101...)

---

## 📝 Detailed Implementation

### JavaScript ⭐
```javascript
function isPowerOfFour(n) {
    return n > 0 && (n & (n - 1)) === 0 && (n & 0x55555555) !== 0;
}
```

**Key Points:**
- Bit manipulation trick
- O(1) time and space
- Runtime: 0ms, Memory: 57.9MB

---

## 🎯 Complexity Analysis

| Approach | Time | Space | Status |
|----------|------|-------|--------|
| **Bit Manipulation** | **O(1)** | **O(1)** | ✅ Accepted |
| Loop Division | O(log₄ n) | O(1) | ✅ Accepted |

**Why O(1)?**
- Single bitwise operations

**Why O(1) space?**
- Only uses a few variables

---

## 🔥 All Accepted Solutions

| File Name | Language | Runtime | Memory |
|----------|---------|---------|--------|
| 2026-02-10 22.59.12 - Accepted | JavaScript | 0ms 🟢 | 57.9MB |
| 2026-02-10 22.59.47 - Accepted | JavaScript | 1ms 🟢 | 57.2MB |
| 2026-02-10 22.59.56 - Accepted | JavaScript | 0ms 🟢 | 55.9MB |

---

## 🎓 Key Takeaways

### ✅ Best Practices
1. **Use bit manipulation** for O(1) solution
2. **Check position** of the single bit
3. **Handle edge cases** (n ≤ 0)

### ❌ Common Mistakes
1. Not checking negative numbers
2. Forgetting that 1 is a power of 4
3. Not checking bit position correctly

### 💡 Follow-up Questions
- How to implement without magic numbers?
- How to use while loop instead?

---

## 🔗 Related Problems

| # | Problem | Difficulty | Status |
|---|---------|-----------|--------|
| 231 | Power of Two | Easy | 📝 |
| 326 | Power of Three | Easy | 📝 |
| 191 | Number of 1 Bits | Easy | 📝 |

---

## 📈 Success Metrics

![JavaScript](https://img.shields.io/badge/JavaScript-F7DF1E?style=flat&logo=javascript&logoColor=black)

**Total Submissions:** 3️⃣ **Accepted:** 3️⃣ **Acceptance Rate:** 100% ✅

---

*Made with ❤️ | Last Updated: 2026-04-13*
