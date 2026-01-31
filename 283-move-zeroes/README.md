# 🚀 LeetCode 283: Move Zeroes

![Difficulty: Easy](https://img.shields.io/badge/Difficulty-Easy-brightgreen)
![Topic: Array](https://img.shields.io/badge/Topic-Array-blue)
![Two Pointers](https://img.shields.io/badge/Topic-Two_Pointers-blue)
![Status: ✅ Solved](https://img.shields.io/badge/Status-Solved-brightgreen)

## 📋 Problem Statement

Given an integer array `nums`, move all `0`s to the end of the array while maintaining the relative order of the non-zero elements.

---

## 📌 Quick Summary

| | |
|---|---|
| **Problem #** | 283 |
| **Difficulty** | Easy |
| **Topics** | Array, Two Pointers |
| **Companies** | Amazon, Apple, Google |
| **Similar Problems** | [Remove Element](./27-remove-element) |

---

## 🎯 Example Test Cases

### ✅ Example 1:
```
Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]
```

### ✅ Example 2:
```
Input: nums = [0]
Output: [0]
```

---

## ⚠️ Constraints

```
1 ≤ nums.length ≤ 10^4
-2^31 ≤ nums[i] ≤ 2^31 - 1
```

---

## 💡 Solution Approaches

### 🔹 Approach 1: Two Pointers (Optimal) ✅ RECOMMENDED

**Intuition:** Use two pointers - one to track the position for next non-zero element, and iterate through the array.

| | |
|---|---|
| **Time** | O(n) |
| **Space** | O(1) |
| **Runtime** | 0ms ✅ |

**Step-by-Step:**
1. Initialize `k = 0` (position for next non-zero element)
2. First pass: For each element, if not zero, place it at position k and increment k
3. Second pass: Fill positions from k to end with zeros
4. Return the modified array

**Why it works:**
- Maintains relative order of non-zero elements
- Single pass for non-zero elements
- In-place modification

---

### 🔹 Approach 2: Swap Method (Alternative)

When encountering a non-zero element, swap it with the element at position k.

| | |
|---|---|
| **Time** | O(n) |
| **Space** | O(1) |

---

## 📝 Detailed Implementation

### Python ⭐
```python
class Solution:
    def moveZeroes(self, nums):
        k = 0
        for i in range(len(nums)):
            if nums[i] != 0:
                nums[k] = nums[i]
                k += 1

        for i in range(k, len(nums)):
            nums[i] = 0
```

**Key Points:**
- Two-pass approach
- O(n) time, O(1) space
- Runtime: 0ms, Memory: 13.6MB

---

### C++ ⭐
```cpp
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int k = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                nums[k++] = nums[i];
            }
        }
        while (k < nums.size()) {
            nums[k++] = 0;
        }
    }
};
```

---

## 🎯 Complexity Analysis

| Approach | Time | Space | Status |
|----------|------|-------|--------|
| **Two Pointers** | **O(n)** | **O(1)** | ✅ Accepted |
| Swap Method | O(n) | O(1) | ✅ Accepted |
| Brute Force | O(n²) | O(1) | ❌ TLE |

**Why O(n)?**
- Two passes through the array (total 2n operations)

**Why O(1) space?**
- Only uses pointer variable k

---

## 🔥 All Accepted Solutions

| File Name | Language | Runtime | Memory |
|----------|---------|---------|--------|
| 2026-01-31 13.46.04 - Accepted | Python 🐍 | 0ms 🟢 | 13.6MB |
| 2026-04-07 11.57.49 - Accepted | C++ | 0ms 🟢 | 24MB |
| 2026-04-07 12.07.24 - Accepted | C++ | 3ms 🟢 | 23.7MB |

---

## 🎓 Key Takeaways

### ✅ Best Practices
1. **Use two pointers** for in-place operations
2. **Two-pass approach** is clear and efficient
3. **Preserve relative order** of non-zero elements

### ❌ Common Mistakes
1. Not filling remaining positions with zeros
2. Using extra space when not needed
3. Not maintaining relative order

### 💡 Follow-up Questions
- How to move all zeros to the beginning?
- How to handle multiple types of elements?

---

## 🔗 Related Problems

| # | Problem | Difficulty | Status |
|---|---------|-----------|--------|
| 27 | Remove Element | Easy | 📝 |
| 26 | Remove Duplicates from Sorted Array | Easy | 📝 |
| 88 | Merge Sorted Array | Easy | 📝 |

---

## 📈 Success Metrics

![Python](https://img.shields.io/badge/Python-3776AB?style=flat&logo=python&logoColor=white)
![C++](https://img.shields.io/badge/C++-00599C?style=flat&logo=c%2B%2B&logoColor=white)

**Total Submissions:** 3️⃣ **Accepted:** 3️⃣ **Acceptance Rate:** 100% ✅

---

*Made with ❤️ | Last Updated: 2026-04-13*
