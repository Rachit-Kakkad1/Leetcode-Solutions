# 🚀 LeetCode 26: Remove Duplicates from Sorted Array

![Difficulty: Easy](https://img.shields.io/badge/Difficulty-Easy-brightgreen)
![Array](https://img.shields.io/badge/Topic-Array-blue)
![Two Pointers](https://img.shields.io/badge/Topic-Two_Pointers-blue)
![Status: ✅ Solved](https://img.shields.io/badge/Status-Solved-brightgreen)

## 📋 Problem Statement

Given an integer array `nums` sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears once. Return the new length.

The relative order of elements may be changed.

---

## 📌 Quick Summary

| | |
|---|---|
| **Problem #** | 26 |
| **Difficulty** | Easy |
| **Topics** | Array, Two Pointers |
| **Companies** | Amazon, Google, Microsoft |
| **Similar Problems** | [Remove Duplicates II](./80-remove-duplicates-from-sorted-array-ii) |

---

## 🎯 Example Test Cases

### ✅ Example 1:
```
Input: nums = [1,1,2]
Output: 2
Explanation: Your function should return length = 2, where the first two elements of nums are 1 and 2.
```

### ✅ Example 2:
```
Input: nums = [1,1,2,3,3,4,4,5]
Output: 5
Explanation: Your function should return length = 5.
```

---

## ⚠️ Constraints

- 1 ≤ nums.length ≤ 10⁴
- -100 ≤ nums[i] ≤ 100

---

## 💡 Solution Approaches

### 🔹 Approach 1: Two Pointers (Optimal) ✅ RECOMMENDED

**Intuition:** Use two pointers - one for iterating, one for placing unique elements.

| | |
|---|---|
| **Time** | O(n) |
| **Space** | O(1) |
| **Runtime** | 0ms ✅ |

**Step-by-Step:**
1. Use pointer k = 1 for next unique position
2. Iterate from index 1
3. If nums[i] != nums[i-1], place at nums[k]
4. Increment k

**Why it works:**
- Sorted array ensures duplicates are adjacent
- Single pass

---

## 📝 Detailed Implementation

### JavaScript ⭐
```javascript
var removeDuplicates = function(nums) {
    let k = 1;
    for (let i = 1; i < nums.length; i++) {
        if (nums[i] !== nums[i - 1]) {
            nums[k] = nums[i];
            k++;
        }
    }
    return k;
};
```

**Key Points:**
- In-place modification
- Single pass
- Runtime: 0-1ms, Memory: 57-58MB

---

## 🎯 Complexity Analysis

| Approach | Time | Space | Status |
|----------|------|-------|--------|
| **Two Pointers** | **O(n)** | **O(1)** | ✅ Accepted |
| Hash Set | O(n) | O(n) | ❌ |

---

## 🔥 All Accepted Solutions

| File Name | Language | Runtime | Memory |
|----------|---------|---------|--------|
| 2026-01-02 12.10.25 - Accepted | JavaScript | 0ms 🟢 | 57.2MB |
| 2026-01-02 12.12.57 - Accepted | JavaScript | 1ms 🟡 | 58.2MB |
| 2026-01-02 12.13.09 - Accepted | JavaScript | 0ms 🟢 | 58.6MB |

---

## 🎓 Key Takeaways

### ✅ Best Practices
1. In-place modification
2. Single pass with two pointers
3. Compare with previous

### ❌ Common Mistakes
1. Not advancing k correctly
2. Comparing wrong indices

---

## 📈 Success Metrics

![JavaScript](https://img.shields.io/badge/JavaScript-F7DF1E?style=flat&logo=javascript&logoColor=black)

**Total Submissions:** 4️⃣ **Accepted:** 3️⃣ **Acceptance Rate:** 75% ✅

---

*Made with ❤️ | Last Updated: 2026-04-13*