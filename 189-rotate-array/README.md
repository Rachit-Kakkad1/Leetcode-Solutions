# 🚀 LeetCode 189: Rotate Array

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-yellow)
![Topic: Array](https://img.shields.io/badge/Topic-Array-blue)
![Math](https://img.shields.io/badge/Topic-Math-blue)
![Two Pointers](https://img.shields.io/badge/Topic-Two_Pointers-blue)
![Status: ✅ Solved](https://img.shields.io/badge/Status-Solved-brightgreen)

## 📋 Problem Statement

Given an integer array `nums`, rotate the array to the right by `k` steps.

---

## 📌 Quick Summary

| | |
|---|---|
| **Problem #** | 189 |
| **Difficulty** | Medium |
| **Topics** | Array, Math, Two Pointers |
| **Companies** | Amazon, Apple, Microsoft |
| **Similar Problems** | [Rotate List](./61-rotate-list) |

---

## 🎯 Example Test Cases

### ✅ Example 1:
```
Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
Explanation: rotate 1 step: [7,1,2,3,4,5,6]
              rotate 2 steps: [6,7,1,2,3,4,5]
              rotate 3 steps: [5,6,7,1,2,3,4]
```

### ✅ Example 2:
```
Input: nums = [-1,-100,3,99], k = 2
Output: [3,99,-1,-100]
```

---

## ⚠️ Constraints

```
1 ≤ nums.length ≤ 10^5
-2^31 ≤ nums[i] ≤ 2^31 - 1
0 ≤ k ≤ 10^5
```

---

## 💡 Solution Approaches

### 🔹 Approach 1: Reverse (Optimal) ✅ RECOMMENDED

**Intuition:** Three reversals achieve the rotation.

| | |
|---|---|
| **Time** | O(n) |
| **Space** | O(1) |
| **Runtime** | 11ms ✅ |

**Step-by-Step:**
1. Handle k greater than array length with modulo
2. Reverse the entire array
3. Reverse the first k elements
4. Reverse the remaining n-k elements

**Why it works:**
- Reverse brings the last k elements to front
- Two more reversals properly position them

---

## 📝 Detailed Implementation

### Python ⭐
```python
def rotate(nums, k):
    k = k % len(nums)
    
    def reverse(start, end):
        while start < end:
            nums[start], nums[end] = nums[end], nums[start]
            start += 1
            end -= 1
    
    reverse(0, len(nums) - 1)
    reverse(0, k - 1)
    reverse(k, len(nums) - 1)
```

**Key Points:**
- Three reversal technique
- O(n) time, O(1) space
- Runtime: 11ms, Memory: 22.3MB

---

## 🎯 Complexity Analysis

| Approach | Time | Space | Status |
|----------|------|-------|--------|
| **Reverse** | **O(n)** | **O(1)** | ✅ Accepted |
| Brute Force | O(n*k) | O(1) | ❌ TLE |
| Extra Array | O(n) | O(n) | ✅ Accepted |

**Why O(n)?**
- Three reversals each O(n)

**Why O(1) space?**
- In-place transformation

---

## 🔥 All Accepted Solutions

| File Name | Language | Runtime | Memory |
|----------|---------|---------|--------|
| 2026-03-08 17.50.54 - Accepted | **Python** 🐍 | **11ms 🟡** | **22.3MB** |

---

## 🎓 Key Takeaways

### ✅ Best Practices
1. **Use modulo** for large k values
2. **Three reversals** is the optimal approach
3. **In-place** transformation

### ❌ Common Mistakes
1. Not handling k > n
2. Using brute force (causes TLE)
3. Not reversing correctly

### 💡 Follow-up Questions
- How to rotate left instead of right?
- How to handle in linked list?

---

## 🔗 Related Problems

| # | Problem | Difficulty | Status |
|---|---------|-----------|--------|
| 61 | Rotate List | Medium | 📝 |
| 396 | Rotate Function | Medium | 📝 |

---

## 📈 Success Metrics

![Python](https://img.shields.io/badge/Python-3776AB?style=flat&logo=python&logoColor=white)

**Total Submissions:** 1️⃣ **Accepted:** 1️⃣ **Acceptance Rate:** 100% ✅

---

*Made with ❤️ | Last Updated: 2026-04-13*
