# 🚀 LeetCode 136: Single Number

![Difficulty: Easy](https://img.shields.io/badge/Difficulty-Easy-brightgreen)
![Topic: Array](https://img.shields.io/badge/Topic-Array-blue)
![Bit Manipulation](https://img.shields.io/badge/Topic-Bit_Manipulation-blue)
![Status: ✅ Solved](https://img.shields.io/badge/Status-Solved-brightgreen)

## 📋 Problem Statement

Given a **non-empty** array of integers `nums`, every element appears *twice* except for one. Find that single one.

You must implement a solution with a linear runtime complexity and use only constant extra space.

---

## 📌 Quick Summary

| | |
|---|---|
| **Problem #** | 136 |
| **Difficulty** | Easy |
| **Topics** | Array, Bit Manipulation |
| **Companies** | Amazon, Apple, Google |
| **Similar Problems** | [Single Number II](./137-single-number-ii) |

---

## 🎯 Example Test Cases

### ✅ Example 1:
```
Input: nums = [2,2,1]
Output: 1
```

### ✅ Example 2:
```
Input: nums = [4,1,2,1,2]
Output: 4
```

### ✅ Example 3:
```
Input: nums = [1]
Output: 1
```

---

## ⚠️ Constraints

```
1 ≤ nums.length ≤ 3 * 10^4
-3 * 10^4 ≤ nums[i] ≤ 3 * 10^4
Each element appears twice except one
```

---

## 💡 Solution Approaches

### 🔹 Approach 1: XOR (Optimal) ✅ RECOMMENDED

**Intuition:** Use XOR bitwise operation. XOR of a number with itself is 0, and XOR with 0 is the number itself.

| | |
|---|---|
| **Time** | O(n) |
| **Space** | O(1) |
| **Runtime** | 0ms ✅ |

**Step-by-Step:**
1. Initialize `result = 0`
2. Iterate through all numbers
3. Perform `result ^= num` for each number
4. Return result

**Why it works:**
- XOR of a number with itself is 0: `a ^ a = 0`
- XOR of a number with 0 is the number: `a ^ 0 = a`
- XOR is associative and commutative
- Duplicates cancel out, leaving the single element

---

## 📝 Detailed Implementation

### JavaScript ⭐
```javascript
function singleNumber(nums) {
    let result = 0;

    for (const num of nums) {
        result ^= num;
    }

    return result;
}
```

**Key Points:**
- XOR bitwise operation
- O(n) time, O(1) space
- Runtime: 0ms, Memory: 56.7MB

---

## 🎯 Complexity Analysis

| Approach | Time | Space | Status |
|----------|------|-------|--------|
| **XOR** | **O(n)** | **O(1)** | ✅ Accepted |
| Hash Set | O(n) | O(n) | ✅ Accepted |

**Why O(n)?**
- Single pass through the array

**Why O(1) space?**
- Only one variable used

---

## 🔥 All Accepted Solutions

| File Name | Language | Runtime | Memory |
|----------|---------|---------|--------|
| 2026-02-10 23.27.07 - Accepted | **JavaScript** | **0ms 🟢** | **56.7MB** |

---

## 🎓 Key Takeaways

### ✅ Best Practices
1. **Use XOR** for this specific pattern
2. **Constant space** is achievable
3. **Understand bitwise properties**

### ❌ Common Mistakes
1. Not understanding XOR properties
2. Using extra space when not needed
3. Forgetting to initialize result to 0

### 💡 Follow-up Questions
- How to handle Single Number II (appears 3 times)?
- How to handle multiple unique numbers?

---

## 🔗 Related Problems

| # | Problem | Difficulty | Status |
|---|---------|-----------|--------|
| 137 | Single Number II | Medium | 📝 |
| 260 | Single Number III | Medium | 📝 |
| 268 | Missing Number | Easy | 📝 |

---

## 📈 Success Metrics

![JavaScript](https://img.shields.io/badge/JavaScript-F7DF1E?style=flat&logo=javascript&logoColor=black)

**Total Submissions:** 1️⃣ **Accepted:** 1️⃣ **Acceptance Rate:** 100% ✅

---

*Made with ❤️ | Last Updated: 2026-04-13*
