# 🚀 LeetCode 70: Climbing Stairs

![Difficulty: Easy](https://img.shields.io/badge/Difficulty-Easy-brightgreen)
![Topic: Dynamic Programming](https://img.shields.io/badge/Topic-Dynamic_Programming-blue)
![Status: ✅ Solved](https://img.shields.io/badge/Status-Solved-brightgreen)

## 📋 Problem Statement

You are climbing a staircase. It takes `n` steps to reach the top.

Each time you can either climb `1` or `2` steps. In how many distinct ways can you climb to the top?

---

## 📌 Quick Summary

| | |
|---|---|
| **Problem #** | 70 |
| **Difficulty** | Easy |
| **Topics** | Dynamic Programming |
| **Companies** | Amazon, Apple |
| **Similar Problems** | [Climbing Stairs II](./70-climbing-stairs) |

---

## 🎯 Example Test Cases

### ✅ Example 1:
```
Input: n = 2
Output: 2
Explanation: There are two ways to climb to the top:
1. 1 step + 1 step
2. 2 steps
```

### ✅ Example 2:
```
Input: n = 3
Output: 3
Explanation: There are three ways to climb to the top:
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step
```

---

## ⚠️ Constraints

```
1 ≤ n ≤ 45
```

---

## 💡 Solution Approaches

### 🔹 Approach 1: Dynamic Programming (Optimal) ✅ RECOMMENDED

**Intuition:** This is essentially a Fibonacci sequence. To reach step n, you must come from either step n-1 or n-2.

| | |
|---|---|
| **Time** | O(n) |
| **Space** | O(1) |
| **Runtime** | 0ms ✅ |

**Step-by-Step:**
1. If n ≤ 2, return n directly
2. Use two variables to track previous two states
3. Iterate from 3 to n, computing current = prev1 + prev2
4. Shift variables for next iteration

**Why it works:**
- Each state depends only on the previous two states
- Fibonacci pattern: ways(n) = ways(n-1) + ways(n-2)
- O(1) space optimization using two variables

---

## 📝 Detailed Implementation

### C++ ⭐
```cpp
class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2) return n;
        
        int prev1 = 1, prev2 = 2;
        
        for (int i = 3; i <= n; i++) {
            int cur = prev1 + prev2;
            prev1 = prev2;
            prev2 = cur;
        }
        
        return prev2;
    }
};
```

**Key Points:**
- Uses O(1) space optimization
- Fibonacci sequence pattern
- Runtime: 0ms, Memory: 8.6MB

---

## 🎯 Complexity Analysis

| Approach | Time | Space | Status |
|----------|------|-------|--------|
| **DP (O(1) space)** | **O(n)** | **O(1)** | ✅ Accepted |
| DP (O(n) space) | O(n) | O(n) | ✅ Accepted |
| Recursion | O(2^n) | O(n) | ❌ TLE |

**Why O(n)?**
- Single iteration from 3 to n
- Constant work per iteration

**Why O(1) space?**
- Only stores two previous values

---

## 🔥 All Accepted Solutions

| File Name | Language | Runtime | Memory |
|----------|---------|---------|--------|
| 2026-04-06 15.02.10 - Accepted | **C++** | **0ms 🟢** | **8.6MB** |

---

## 🎓 Key Takeaways

### ✅ Best Practices
1. **Recognize Fibonacci pattern** in DP problems
2. **Optimize space** to O(1) when possible
3. **Handle base cases** explicitly

### ❌ Common Mistakes
1. Using recursion (causes TLE for large n)
2. Not handling n=1 correctly
3. Using extra space when not needed

### 💡 Follow-up Questions
- How would you extend to 1, 2, or 3 steps?
- How to handle very large n with matrix exponentiation?

---

## 🔗 Related Problems

| # | Problem | Difficulty | Status |
|---|---------|-----------|--------|
| 746 | Min Cost Climbing Stairs | Easy | 📝 |
| 91 | Decode Ways | Medium | 📝 |
| 509 | Fibonacci Number | Easy | 📝 |

---

## 📈 Success Metrics

![C++](https://img.shields.io/badge/C++-00599C?style=flat&logo=c%2B%2B&logoColor=white)

**Total Submissions:** 1️⃣ **Accepted:** 1️⃣ **Acceptance Rate:** 100% ✅

---

*Made with ❤️ | Last Updated: 2026-04-13*
