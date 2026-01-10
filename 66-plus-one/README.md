# 🚀 LeetCode 66: Plus One

![Difficulty: Easy](https://img.shields.io/badge/Difficulty-Easy-brightgreen)
![Topic: Array](https://img.shields.io/badge/Topic-Array-blue)
![Math](https://img.shields.io/badge/Topic-Math-blue)
![Status: ✅ Solved](https://img.shields.io/badge/Status-Solved-brightgreen)

## 📋 Problem Statement

You are given a large integer represented as an array of digits `digits`. Add one to the integer and return the resulting array of digits.

---

## 📌 Quick Summary

| | |
|---|---|
| **Problem #** | 66 |
| **Difficulty** | Easy |
| **Topics** | Array, Math |
| **Companies** | Amazon, Apple, Google |
| **Similar Problems** | [Add Binary](./67-add-binary) |

---

## 🎯 Example Test Cases

### ✅ Example 1:
```
Input: digits = [1,2,3]
Output: [1,2,4]
Explanation: 123 + 1 = 124
```

### ✅ Example 2:
```
Input: digits = [4,3,2,1]
Output: [4,3,2,2]
```

### ✅ Example 3:
```
Input: digits = [9]
Output: [1,0]
Explanation: 9 + 1 = 10
```

---

## ⚠️ Constraints

```
1 ≤ digits.length ≤ 100
0 ≤ digits[i] ≤ 9
```

---

## 💡 Solution Approaches

### 🔹 Approach 1: Single Pass from End (Optimal) ✅ RECOMMENDED

**Intuition:** Add 1 from the end, handle carry properly.

| | |
|---|---|
| **Time** | O(n) |
| **Space** | O(1) |
| **Runtime** | 0ms ✅ |

**Step-by-Step:**
1. Iterate backwards from the end
2. If digit < 9, add 1 and return
3. If digit = 9, set to 0 and continue (carry)
4. If all digits were 9, prepend 1

**Why it works:**
- Most significant digits are at the end
- Handles carry propagation efficiently

---

## 📝 Detailed Implementation

### JavaScript ⭐
```javascript
function plusOne(digits) {
    for (let i = digits.length - 1; i >= 0; i--) {
        if (digits[i] < 9) {
            digits[i]++;
            return digits;
        }
        digits[i] = 0;
    }
    return [1, ...digits];
}
```

**Key Points:**
- Single pass from end
- Early return on non-9 digit
- Runtime: 0ms, Memory: 53.9MB

---

## 🎯 Complexity Analysis

| Approach | Time | Space | Status |
|----------|------|-------|--------|
| **Single Pass** | **O(n)** | **O(1)** | ✅ Accepted |
| String Conversion | O(n) | O(n) | ✅ Accepted |

**Why O(n)?**
- In worst case, traverse entire array

**Why O(1) space?**
- Only modifies array in-place

---

## 🔥 All Accepted Solutions

| File Name | Language | Runtime | Memory |
|----------|---------|---------|--------|
| 2026-01-10 13.12.42 - Accepted | **JavaScript** | **0ms 🟢** | **53.9MB** |

---

## 🎓 Key Takeaways

### ✅ Best Practices
1. **Single pass** from end is optimal
2. **Early return** when no carry needed
3. **Handle all 9s** case (prepend 1)

### ❌ Common Mistakes
1. Not handling [9, 9, 9] case
2. Using extra space unnecessarily
3. Not checking for overflow

### 💡 Follow-up Questions
- How to add two large numbers?
- How to handle decimal plus one?

---

## 🔗 Related Problems

| # | Problem | Difficulty | Status |
|---|---------|-----------|--------|
| 67 | Add Binary | Easy | 📝 |
| 415 | Add Strings | Easy | 📝 |

---

## 📈 Success Metrics

![JavaScript](https://img.shields.io/badge/JavaScript-F7DF1E?style=flat&logo=javascript&logoColor=black)

**Total Submissions:** 1️⃣ **Accepted:** 1️⃣ **Acceptance Rate:** 100% ✅

---

*Made with ❤️ | Last Updated: 2026-04-13*
