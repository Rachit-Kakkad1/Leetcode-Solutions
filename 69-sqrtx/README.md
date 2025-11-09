# 🚀 LeetCode 69: Sqrt(x)

![Difficulty: Easy](https://img.shields.io/badge/Difficulty-Easy-brightgreen)
![Topic: Math](https://img.shields.io/badge/Topic-Math-blue)
![Binary Search](https://img.shields.io/badge/Topic-Binary_Search-blue)
![Status: ✅ Solved](https://img.shields.io/badge/Status-Solved-brightgreen)

## 📋 Problem Statement

Given a non-negative integer `x`, return the floor of its square root.

The floor of the square root is the largest integer `r` such that `r² ≤ x`.

---

## 📌 Quick Summary

| | |
|---|---|
| **Problem #** | 69 |
| **Difficulty** | Easy |
| **Topics** | Math, Binary Search |
| **Companies** | Amazon, Apple, Google, Microsoft |
| **Similar Problems** | [Square Root](./) |

---

## 🎯 Example Test Cases

### ✅ Example 1:
```
Input: x = 4
Output: 2
Explanation: sqrt(4) = 2
```

### ✅ Example 2:
```
Input: x = 8
Output: 2
Explanation: sqrt(8) ≈ 2.828, floor is 2
```

### ✅ Example 3:
```
Input: x = 0
Output: 0
```

---

## ⚠️ Constraints

```
0 ≤ x ≤ 2^31 - 1
```

---

## 💡 Solution Approaches

### 🔹 Approach 1: Binary Search (Optimal) ✅ RECOMMENDED

**Intuition:** Use binary search to find the largest mid where mid² ≤ x.

| | |
|---|---|
| **Time** | O(log x) |
| **Space** | O(1) |
| **Runtime** | 0ms ✅ |

**Step-by-Step:**
1. Handle edge cases: x = 0 or 1
2. Binary search in range [1, x]
3. Find the largest mid where mid² ≤ x
4. Return the answer

**Why it works:**
- Binary search reduces search space by half each iteration
- Keeps track of largest valid answer

---

## 📝 Detailed Implementation

### C ⭐
```c
int mySqrt(int x) {
    if (x == 0 || x == 1)
        return x;
    int left = 1, right = x, ans = 0;
    
    while (left <= right) {
        long mid = left + (right - left) / 2;
        long sq = mid * mid;
        
        if (sq == x)
            return mid;
        else if (sq < x) {
            ans = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    return ans;
}
```

**Key Points:**
- Binary search algorithm
- Uses long to prevent overflow
- Runtime: 0ms, Memory: 8.5MB

---

## 🎯 Complexity Analysis

| Approach | Time | Space | Status |
|----------|------|-------|--------|
| **Binary Search** | **O(log x)** | **O(1)** | ✅ Accepted |
| Newton's Method | O(log x) | O(1) | ✅ Accepted |

**Why O(log x)?**
- Binary search halves the search space each iteration

**Why O(1) space?**
- Only uses a few variables

---

## 🔥 All Accepted Solutions

| File Name | Language | Runtime | Memory |
|----------|---------|---------|--------|
| 2025-11-09 11.00.15 - Accepted | **C** | **0ms 🟢** | **8.5MB** |

---

## 🎓 Key Takeaways

### ✅ Best Practices
1. **Use binary search** for efficient sqrt
2. **Use long** to prevent overflow
3. **Handle edge cases** (0 and 1)

### ❌ Common Mistakes
1. Not checking for overflow
2. Using int for intermediate calculation
3. Wrong comparison in binary search

### 💡 Follow-up Questions
- How to find exact sqrt?
- How to handle floating point sqrt?

---

## 🔗 Related Problems

| # | Problem | Difficulty | Status |
|---|---------|-----------|--------|
| 367 | Valid Perfect Square | Easy | 📝 |
| 441 | Arranging Coins | Easy | 📝 |

---

## 📈 Success Metrics

![C](https://img.shields.io/badge/C-A8B9CC?style=flat&logo=c&logoColor=white)

**Total Submissions:** 1️⃣ **Accepted:** 1️⃣ **Acceptance Rate:** 100% ✅

---

*Made with ❤️ | Last Updated: 2026-04-13*
