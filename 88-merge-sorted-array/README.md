# 🚀 LeetCode 88: Merge Sorted Array

![Difficulty: Easy](https://img.shields.io/badge/Difficulty-Easy-brightgreen)
![Topic: Array](https://img.shields.io/badge/Topic-Array-blue)
![Two Pointers](https://img.shields.io/badge/Topic-Two_Pointers-blue)
![Sorting](https://img.shields.io/badge/Topic-Sorting-blue)
![Status: ✅ Solved](https://img.shields.io/badge/Status-Solved-brightgreen)

## 📋 Problem Statement

You are given two integer arrays `nums1` and `nums2`, sorted in **non-decreasing order**, and two integers `m` and `n`, representing the number of elements in `nums1` and `nums2` respectively.

**Merge** `nums1` and `nums2` into a single array sorted in **non-decreasing order**.

The final sorted array should be stored inside the array `nums1`. nums1 has a length of `m + n`, where the first `m` elements denote the elements that should be merged, and the last `n` elements are set to `0` and should be ignored.

---

## 📌 Quick Summary

| | |
|---|---|
| **Problem #** | 88 |
| **Difficulty** | Easy |
| **Topics** | Array, Two Pointers, Sorting |
| **Companies** | Amazon, Apple, Google, Microsoft |
| **Similar Problems** | [Merge Two Sorted Lists](./21-merge-two-sorted-lists) |

---

## 🎯 Example Test Cases

### ✅ Example 1:
```
Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
Output: [1,2,2,3,5,6]
Explanation: The arrays we are merging are [1,2,3] and [2,5,6].
```

### ✅ Example 2:
```
Input: nums1 = [1], m = 1, nums2 = [], n = 0
Output: [1]
```

### ✅ Example 3:
```
Input: nums1 = [0], m = 0, nums2 = [1], n = 1
Output: [1]
```

---

## ⚠️ Constraints

```
nums1.length == m + n
nums2.length == n
0 ≤ m, n ≤ 200
1 ≤ m + n ≤ 200
-10^9 ≤ nums1[i], nums2[j] ≤ 10^9
```

---

## 💡 Solution Approaches

### 🔹 Approach 1: Three Pointers (Optimal) ✅ RECOMMENDED

**Intuition:** Use three pointers working backwards from the end to avoid overwriting unprocessed elements.

| | |
|---|---|
| **Time** | O(m + n) |
| **Space** | O(1) |
| **Runtime** | 0ms ✅ |

**Step-by-Step:**
1. Initialize pointers: `p1 = m - 1`, `p2 = n - 1`, `p = m + n - 1`
2. While `p2 >= 0`:
   - If `p1 >= 0` and `nums1[p1] > nums2[p2]`:
     - Place `nums1[p1]` at position `p`
     - Decrement `p1`
   - Else:
     - Place `nums2[p2]` at position `p`
     - Decrement `p2`
   - Decrement `p`
3. Done - all elements from nums2 have been merged

**Why it works:**
- Working backwards prevents overwriting unprocessed elements
- Each element is processed exactly once

---

## 📝 Detailed Implementation

### JavaScript ⭐
```javascript
var merge = function(nums1, m, nums2, n) {
    let p1 = m - 1;
    let p2 = n - 1;
    let p = m + n - 1;

    while (p2 >= 0) {
        if (p1 >= 0 && nums1[p1] > nums2[p2]) {
            nums1[p] = nums1[p1];
            p1--;
        } else {
            nums1[p] = nums2[p2];
            p2--;
        }
        p--;
    }
};
```

**Key Points:**
- Three pointers working backwards
- O(m+n) time, O(1) space
- Runtime: 0ms, Memory: 52.6MB

---

## 🎯 Complexity Analysis

| Approach | Time | Space | Status |
|----------|------|-------|--------|
| **Three Pointers** | **O(m + n)** | **O(1)** | ✅ Accepted |
| Merge to nums2 | O(m + n) | O(m + n) | ✅ Accepted |

**Why O(m + n)?**
- Each element is moved at most once

**Why O(1) space?**
- Only uses three pointer variables

---

## 🔥 All Accepted Solutions

| File Name | Language | Runtime | Memory |
|----------|---------|---------|--------|
| 2026-01-10 17.23.21 - Accepted | **JavaScript** | **0ms 🟢** | **52.6MB** |

---

## 🎓 Key Takeaways

### ✅ Best Practices
1. **Work backwards** to avoid overwriting
2. **Three pointers** for efficient merging
3. **Handle edge cases** (empty arrays)

### ❌ Common Mistakes
1. Not working backwards (causes data loss)
2. Using extra space when O(1) is possible
3. Not handling when nums1 or nums2 is empty

### 💡 Follow-up Questions
- How to merge more than two sorted arrays?
- How to handle descending order?

---

## 🔗 Related Problems

| # | Problem | Difficulty | Status |
|---|---------|-----------|--------|
| 21 | Merge Two Sorted Lists | Easy | 📝 |
| 2785 | Sort Vowels in a Given String | Medium | 📝 |

---

## 📈 Success Metrics

![JavaScript](https://img.shields.io/badge/JavaScript-F7DF1E?style=flat&logo=javascript&logoColor=black)

**Total Submissions:** 1️⃣ **Accepted:** 1️⃣ **Acceptance Rate:** 100% ✅

---

*Made with ❤️ | Last Updated: 2026-04-13*
