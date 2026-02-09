# 🚀 LeetCode 268: Missing Number

![Difficulty: Easy](https://img.shields.io/badge/Difficulty-Easy-brightgreen)
![Topic: Array](https://img.shields.io/badge/Topic-Array-blue)
![Hash Table](https://img.shields.io/badge/Topic-Hash_Table-blue)
![Math](https://img.shields.io/badge/Topic-Math-blue)
![Bit Manipulation](https://img.shields.io/badge/Topic-Bit_Manipulation-blue)
![Status: ✅ Solved](https://img.shields.io/badge/Status-Solved-brightgreen)

## 📋 Problem Statement

Given an array `nums` containing `n` distinct numbers in the range `[0, n]`, return the one number that is missing from the array.

---

## 📌 Quick Summary

| | |
|---|---|
| **Problem #** | 268 |
| **Difficulty** | Easy |
| **Topics** | Array, Hash Table, Math, Bit Manipulation |
| **Companies** | Amazon, Apple, Microsoft |
| **Similar Problems** | [First Missing Positive](./41-first-missing-positive) |

---

## 🎯 Example Test Cases

### ✅ Example 1:
```
Input: nums = [3,0,1]
Output: 2
Explanation: n = 3, numbers are in range [0,3], missing number is 2.
```

### ✅ Example 2:
```
Input: nums = [0,1]
Output: 2
Explanation: n = 2, numbers are in range [0,2], missing number is 2.
```

### ✅ Example 3:
```
Input: nums = [9,6,4,2,3,5,7,0,1]
Output: 8
```

---

## ⚠️ Constraints

```
1 ≤ nums.length ≤ 10^4
All numbers are unique and in range [0, n]
```

---

## 💡 Solution Approaches

### 🔹 Approach 1: Sum Formula (Optimal) ✅ RECOMMENDED

**Intuition:** Use the mathematical formula for sum of first n numbers.

| | |
|---|---|
| **Time** | O(n) |
| **Space** | O(1) |
| **Runtime** | 2ms ✅ |

**Step-by-Step:**
1. Calculate expected sum: n * (n + 1) / 2
2. Calculate actual sum of array elements
3. Return expected - actual

**Why it works:**
- Sum of [0, n] = n * (n + 1) / 2
- Missing number = expected sum - actual sum

---

### 🔹 Approach 2: XOR (Alternative)

Use XOR of all indices and values.

| | |
|---|---|
| **Time** | O(n) |
| **Space** | O(1) |

---

## 📝 Detailed Implementation

### JavaScript ⭐
```javascript
var missingNumber = function(nums) {
    let n = nums.length;
    let expected = n * (n + 1) / 2;
    let actual = 0;
    for (let num of nums) {
        actual += num;
    }
    return expected - actual;
};
```

**Key Points:**
- Sum formula approach
- O(n) time, O(1) space
- Runtime: 2ms, Memory: 56.6MB

---

## 🎯 Complexity Analysis

| Approach | Time | Space | Status |
|----------|------|-------|--------|
| **Sum Formula** | **O(n)** | **O(1)** | ✅ Accepted |
| XOR | O(n) | O(1) | ✅ Accepted |
| Hash Set | O(n) | O(n) | ✅ Accepted |

**Why O(n)?**
- Single pass to sum all elements

**Why O(1) space?**
- Only uses a few variables

---

## 🔥 All Accepted Solutions

| File Name | Language | Runtime | Memory |
|----------|---------|---------|--------|
| 2026-02-09 09.30.04 - Accepted | **JavaScript** | **2ms 🟢** | **56.6MB** |

---

## 🎓 Key Takeaways

### ✅ Best Practices
1. **Use sum formula** for simplest solution
2. **Handle overflow** in other languages (use long)
3. **XOR alternative** avoids overflow

### ❌ Common Mistakes
1. Not handling large n (overflow in calculation)
2. Using extra space when O(1) is possible
3. Not understanding the range [0, n]

### 💡 Follow-up Questions
- How to handle unsorted array with duplicates?
- How to find missing number in O(1) extra space without modification?

---

## 🔗 Related Problems

| # | Problem | Difficulty | Status |
|---|---------|-----------|--------|
| 41 | First Missing Positive | Hard | 📝 |
| 268 | Missing Number | Easy | 📝 |
| 287 | Find the Duplicate Number | Medium | 📝 |

---

## 📈 Success Metrics

![JavaScript](https://img.shields.io/badge/JavaScript-F7DF1E?style=flat&logo=javascript&logoColor=black)

**Total Submissions:** 1️⃣ **Accepted:** 1️⃣ **Acceptance Rate:** 100% ✅

---

*Made with ❤️ | Last Updated: 2026-04-13*
