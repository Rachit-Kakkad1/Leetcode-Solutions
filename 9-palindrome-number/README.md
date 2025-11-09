# 🚀 LeetCode 9: Palindrome Number

![Difficulty: Easy](https://img.shields.io/badge/Difficulty-Easy-brightgreen)
![Math](https://img.shields.io/badge/Topic-Math-blue)
![Status: ✅ Solved](https://img.shields.io/badge/Status-Solved-brightgreen)

## 📋 Problem Statement

Given an integer `x`, return `true` if `x` is a palindrome, and `false` otherwise.

An integer is a palindrome when it reads the same backward as forward.

For example, `121` is a palindrome while `123` is not.

---

## 📌 Quick Summary

| | |
|---|---|
| **Problem #** | 9 |
| **Difficulty** | Easy |
| **Topics** | Math |
| **Companies** | Amazon, Microsoft |
| **Similar Problems** | [Palindrome String](./125-valid-palindrome) |

---

## 🎯 Example Test Cases

### ✅ Example 1:
```
Input: x = 121
Output: true
Explanation: 121 reads as 121 from left to right and from right to left.
```

### ✅ Example 2:
```
Input: x = -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
```

### ✅ Example 3:
```
Input: x = 10
Output: false
Explanation: Reads "01" from right to left. Therefore it is not a palindrome.
```

---

## ⚠️ Constraints

- -2³¹ ≤ x ≤ 2³¹ - 1

---

## 💡 Solution Approaches

### 🔹 Approach 1: Reverse Half (Optimal) ✅ RECOMMENDED

**Intuition:** Reverse only half the number and compare. Avoids overflow by reversing digit by digit.

| | |
|---|---|
| **Time** | O(log₁₀(n)) |
| **Space** | O(1) |
| **Runtime** | 3ms ✅ |

**Step-by-Step:**
1. Handle edge cases (negative, ends with 0 but not 0)
2. Reverse the second half of the number
3. Compare original first half with reversed second half

**Why it works:**
- Only need half the digits to determine palindrome
- Avoids integer overflow
- O(log₁₀(n)) time - processes about half the digits

---

### 🔹 Approach 2: String Conversion (Alternative)

Convert to string and compare with reverse.

| | |
|---|---|
| **Time** | O(log₁₀(n)) |
| **Space** | O(log₁₀(n)) |

---

### 🔹 Approach 3: Full Reverse (NOT RECOMMENDED)

Reverse the entire number - can cause overflow.

| | |
|---|---|
| **Time** | O(log₁₀(n)) |
| **Space** | O(1) |

---

## 📝 Detailed Implementation

### Python ⭐
```python
class Solution(object):
    def isPalindrome(self, x):
        if x < 0 or (x % 10 == 0 and x != 0):
            return False

        reversed_half = 0
        while x > reversed_half:
            reversed_half = reversed_half * 10 + x % 10
            x //= 10
            
        return x == reversed_half or x == reversed_half // 10
```

**Key Points:**
- Handles negative numbers immediately
- Numbers ending in 0 (except 0) are not palindromes
- Runtime: 3ms, Memory: 12.4MB

---

## 🎯 Complexity Analysis

| Approach | Time | Space | Status |
|----------|------|-------|--------|
| **Reverse Half** | **O(log₁₀(n))** | **O(1)** | ✅ Accepted |
| String Conversion | O(log₁₀(n)) | O(log₁₀(n)) | ✅ Accepted |
| Full Reverse | O(log₁₀(n)) | O(1) | ⚠️ Overflow |

**Why O(log₁₀(n))?**
- Number of digits processed
- Each iteration removes one digit

**Why O(1) space?**
- Only uses a few integer variables

---

## 🔥 All Accepted Solutions

| File Name | Language | Runtime | Memory |
|----------|---------|---------|--------|
| 2025-11-09 11.20.03 - Accepted - runtime 3ms - memory 12.4MB.py | **Python** 🐍 | **3ms 🟢** | **12.4MB** |

---

## 🎓 Key Takeaways

### ✅ Best Practices
1. **Handle negative** numbers as non-palindromes
2. **Numbers ending in 0** (except 0) are not palindromes
3. **Reverse only half** to avoid overflow

### ❌ Common Mistakes
1. Not handling negative numbers
2. Not handling numbers ending in 0
3. Causing integer overflow with full reverse

### 💡 Follow-up Questions
- How to check palindrome for strings?
- How to handle very large numbers?

---

## 🔗 Related Problems

| # | Problem | Difficulty | Status |
|---|---------|-----------|--------|
| 125 | Valid Palindrome | Easy | 📝 |
| 906 | Super Palindromes | Easy | 📝 |

---

## 📈 Success Metrics

![Python](https://img.shields.io/badge/Python-3776AB?style=flat&logo=python&logoColor=white)

**Total Submissions:** 1️⃣ **Accepted:** 1️⃣ **Acceptance Rate:** 100% ✅

---

*Made with ❤️ | Last Updated: 2026-04-13*