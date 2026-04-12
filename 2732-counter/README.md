# 🚀 LeetCode 2732: Counter

![Difficulty: Easy](https://img.shields.io/badge/Difficulty-Easy-brightgreen)
![Topic: Closure](https://img.shields.io/badge/Topic-Closure-blue)
![Status: ✅ Solved](https://img.shields.io/badge/Status-Solved-brightgreen)

## 📋 Problem Statement

Given an integer `n`, return a `counter` function. This counter function initially returns `n` and then returns 1 more than the previous value every subsequent time it is called.

---

## 📌 Quick Summary

| | |
|---|---|
| **Problem #** | 2732 |
| **Difficulty** | Easy |
| **Topics** | Closure |
| **Similar Problems** | [2622. Capsule State](./2622-capsule-state) |

---

## 🎯 Example Test Cases

### ✅ Example 1:
```
Input: n = 10
Output: [10, 11, 12, 13]
Explanation: 
counter() = 10 (returns n)
counter() = 11 (returns n+1)
counter() = 12 (returns n+2)
counter() = 13 (returns n+3)
```

---

## ⚠️ Constraints

```
- 0 ≤ n ≤ 10^6
- counter will be called at least once
```

---

## 💡 Solution Approaches

### 🔹 Approach 1: Closure ✅ RECOMMENDED

**Intuition:** Use closure to capture the initial value and return a function that increments and returns the value.

| | |
|---|---|
| **Time** | O(1) per call |
| **Space** | O(1) |

**Step-by-Step:**
1. Create a variable to capture the initial value
2. Return an inner function that returns the current value then increments

---

## 📝 Detailed Implementation

### JavaScript ⭐
```javascript
var createCounter = function(n) {
    let value = n;
    return function() {
        return value++;
    };
};
```

---

## 🎯 Complexity Analysis

| Approach | Time | Space | Status |
|----------|------|-------|--------|
| Closure | O(1) | O(1) | ✅ |

---

## 🔥 All Accepted Solutions

| File Name | Language | Runtime | Memory |
|----------|---------|---------|--------|
| 2026-04-12 20.08.46 - Accepted - runtime 41ms - memory 54.3MB.js | JavaScript | 41ms | 54.3MB |

---

## 🎓 Key Takeaways

### ✅ Best Practices
1. Use closure to maintain state
2. Use post-increment to return current value first

### ❌ Common Mistakes
1. Using pre-increment will return n+1 first

---

## 🔗 Related Problems

| # | Problem | Difficulty |
|---|---------|-----------|
| 2622 | Capsule State | Easy |

---

*Made with ❤️ | Last Updated: 2026-04-13*
