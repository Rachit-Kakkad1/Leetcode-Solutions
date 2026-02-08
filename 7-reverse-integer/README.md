# 🚀 LeetCode 7: Reverse Integer

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-yellow)
![Topic: Math](https://img.shields.io/badge/Topic-Math-blue)
![Status: ✅ Solved](https://img.shields.io/badge/Status-Solved-brightgreen)

## 📋 Problem Statement

Given a signed 32-bit integer `x`, return `x` with its digits reversed. If reversing `x` causes the value to go outside the signed 32-bit integer range [-2^31, 2^31 - 1], then return 0.

---

## 📌 Quick Summary

| | |
|---|---|
| **Problem #** | 7 |
| **Difficulty** | Medium |
| **Topics** | Math |
| **Companies** | Amazon, Apple, Google, Microsoft |
| **Similar Problems** | [Palindrome Number](./9-palindrome-number) |

---

## 🎯 Example Test Cases

### ✅ Example 1:
```
Input: x = 123
Output: 321
```

### ✅ Example 2:
```
Input: x = -123
Output: -321
```

### ✅ Example 3:
```
Input: x = 120
Output: 21
```

---

## ⚠️ Constraints

```
-2^31 ≤ x ≤ 2^31 - 1
```

---

## 💡 Solution Approaches

### 🔹 Approach 1: Digit-by-Digit Reversal (Optimal) ✅ RECOMMENDED

**Intuition:** Extract digits one by one and build reversed number with overflow checks.

| | |
|---|---|
| **Time** | O(log₁₀(x)) |
| **Space** | O(1) |
| **Runtime** | 40ms ✅ |

**Step-by-Step:**
1. Extract each digit using modulo 10
2. Build reversed number by multiplying by 10 and adding digits
3. Before adding each digit, check for potential overflow:
   - Positive overflow: if rev > INT_MAX/10 or rev == INT_MAX/10 and digit > 7
   - Negative overflow: similar logic

**Why it works:**
- Processes each digit exactly once
- Overflow check before it happens prevents going out of bounds

---

## 📝 Detailed Implementation

### JavaScript ⭐
```javascript
function reverse(x) {
    const INT_MIN = -2147483648;
    const INT_MAX = 2147483647;

    let rev = 0;

    while (x !== 0) {
        let digit = x % 10;
        x = (x / 10) | 0;

        if (rev > Math.floor(INT_MAX / 10) || 
           (rev === Math.floor(INT_MAX / 10) && digit > 7)) return 0;

        if (rev < Math.ceil(INT_MIN / 10) || 
           (rev === Math.ceil(INT_MIN / 10) && digit < -8)) return 0;

        rev = rev * 10 + digit;
    }

    return rev;
}
```

**Key Points:**
- Digit-by-digit reversal
- Overflow check before adding
- Runtime: 40ms, Memory: 55.5MB

---

## 🎯 Complexity Analysis

| Approach | Time | Space | Status |
|----------|------|-------|--------|
| **Digit-by-Digit** | **O(log₁₀(x))** | **O(1)** | ✅ Accepted |
| String Conversion | O(log₁₀(x)) | O(log₁₀(x)) | ✅ Accepted |

**Why O(log₁₀(x))?**
- Number of digits in x

**Why O(1) space?**
- Only a few variables used

---

## 🔥 All Accepted Solutions

| File Name | Language | Runtime | Memory |
|----------|---------|---------|--------|
| 2026-02-08 17.22.08 - Accepted | **JavaScript** | **40ms 🟡** | **55.5MB** |

---

## 🎓 Key Takeaways

### ✅ Best Practices
1. **Check overflow** before adding each digit
2. **Handle negative numbers** correctly
3. **Use integer division** in loop

### ❌ Common Mistakes
1. Not checking for overflow
2. Not handling negative numbers
3. Using string conversion (extra space)

### 💡 Follow-up Questions
- How to handle 64-bit integers?
- How to handle leading zeros?

---

## 🔗 Related Problems

| # | Problem | Difficulty | Status |
|---|---------|-----------|--------|
| 9 | Palindrome Number | Easy | 📝 |
| 190 | Reverse Bits | Easy | 📝 |

---

## 📈 Success Metrics

![JavaScript](https://img.shields.io/badge/JavaScript-F7DF1E?style=flat&logo=javascript&logoColor=black)

**Total Submissions:** 1️⃣ **Accepted:** 1️⃣ **Acceptance Rate:** 100% ✅

---

*Made with ❤️ | Last Updated: 2026-04-13*
