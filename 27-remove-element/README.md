# 🚀 LeetCode 27: Remove Element

![Difficulty: Easy](https://img.shields.io/badge/Difficulty-Easy-brightgreen)
![Array](https://img.shields.io/badge/Topic-Array-blue)
![Two Pointers](https://img.shields.io/badge/Topic-Two_Pointers-blue)
![Status: ✅ Solved](https://img.shields.io/badge/Status-Solved-brightgreen)

## 📋 Problem Statement

Given an array `nums` and an integer `val`, remove all occurrences of `val` in-place. Return the new length.

The order of elements may be changed.

---

## 📌 Quick Summary

| | |
|---|---|
| **Problem #** | 27 |
| **Difficulty** | Easy |
| **Topics** | Array, Two Pointers |
| **Companies** | Amazon, Google |
| **Similar Problems** | [Remove Duplicates](./26-remove-duplicates-from-sorted-array) |

---

## 🎯 Example Test Cases

### ✅ Example 1:
```
Input: nums = [3,2,2,3], val = 3
Output: 2
Explanation: Your function should return length = 2.
```

### ✅ Example 2:
```
Input: nums = [0,1,2,2,3,0,4,2], val = 2
Output: 5
Explanation: Your function should return length = 5.
```

---

## ⚠️ Constraints

- 0 ≤ nums.length ≤ 100
- 0 ≤ val ≤ 50

---

## 💡 Solution Approaches

### 🔹 Approach 1: Two Pointers (Optimal) ✅ RECOMMENDED

**Intuition:** Use two pointers - one for next position, one for iterating.

| | |
|---|---|
| **Time** | O(n) |
| **Space** | O(1) |
| **Runtime** | 0ms ✅ |

---

## 📝 Detailed Implementation

### JavaScript ⭐
```javascript
var removeElement = function(nums, val) {
    let k = 0;
    for (let i = 0; i < nums.length; i++) {
        if (nums[i] !== val) {
            nums[k] = nums[i];
            k++;
        }
    }
    return k;
};
```

**Key Points:**
- In-place modification
- O(n) time, O(1) space

---

## 🎯 Complexity Analysis

| Approach | Time | Space | Status |
|----------|------|-------|--------|
| **Two Pointers** | **O(n)** | **O(1)** | ✅ Accepted |

---

## 🔥 All Accepted Solutions

| File Name | Language | Runtime | Memory |
|----------|---------|---------|--------|
| 2026-02-11 10.31.53 - Accepted - runtime 0ms - memory 53.3MB.js | **JavaScript** | **0ms 🟢** | **53.3MB** |

---

## 🎓 Key Takeaways

### ✅ Best Practices
1. In-place modification
2. Track position for next element

---

## 📈 Success Metrics

![JavaScript](https://img.shields.io/badge/JavaScript-F7DF1E?style=flat&logo=javascript&logoColor=black)

**Total Submissions:** 1️⃣ **Accepted:** 1️⃣ **Acceptance Rate:** 100% ✅

---

*Made with ❤️ | Last Updated: 2026-04-13*