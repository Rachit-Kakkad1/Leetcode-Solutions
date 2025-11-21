# 🚀 LeetCode 217: Contains Duplicate

![Difficulty: Easy](https://img.shields.io/badge/Difficulty-Easy-brightgreen)
![Topic: Array](https://img.shields.io/badge/Topic-Array-blue)
![Hash Table](https://img.shields.io/badge/Topic-Hash_Table-blue)
![Sorting](https://img.shields.io/badge/Topic-Sorting-blue)
![Status: ✅ Solved](https://img.shields.io/badge/Status-Solved-brightgreen)

## 📋 Problem Statement

Given an integer array `nums`, return `true` if any value appears at least twice in the array, and return `false` if every element is distinct.

---

## 📌 Quick Summary

| | |
|---|---|
| **Problem #** | 217 |
| **Difficulty** | Easy |
| **Topics** | Array, Hash Table, Sorting |
| **Companies** | Amazon, Apple, Google |
| **Similar Problems** | [Contains Duplicate II](./219-contains-duplicate-ii) |

---

## 🎯 Example Test Cases

### ✅ Example 1:
```
Input: nums = [1,2,3,1]
Output: true
```

### ✅ Example 2:
```
Input: nums = [1,2,3,4]
Output: false
```

### ✅ Example 3:
```
Input: nums = [1,1,1,3,3,4,3,2,4,2]
Output: true
```

---

## ⚠️ Constraints

```
1 ≤ nums.length ≤ 10^5
-10^9 ≤ nums[i] ≤ 10^9
```

---

## 💡 Solution Approaches

### 🔹 Approach 1: Hash Set (Optimal) ✅ RECOMMENDED

**Intuition:** If the size of the set is less than the array size, there must be duplicates.

| | |
|---|---|
| **Time** | O(n) |
| **Space** | O(n) |
| **Runtime** | 3ms ✅ |

**Step-by-Step:**
1. Create a Hash Set
2. For each element in the array:
   - If element already in set, return true
   - Otherwise, add element to set
3. Return false (no duplicates found)

**Why it works:**
- Set stores unique elements only
- If we find an element already in the set, we have a duplicate

---

### 🔹 Approach 2: Sorting (Alternative)

Sort the array and check adjacent elements for duplicates.

| | |
|---|---|
| **Time** | O(n log n) |
| **Space** | O(n) or O(1) (in-place) |

---

## 📝 Detailed Implementation

### Python ⭐
```python
class Solution(object):
    def containsDuplicate(self, nums):
        return len(nums) > len(set(nums))
```

**Key Points:**
- Simple one-liner using set
- Runtime: 3ms, Memory: 26MB

---

### Python (Loop Version)
```python
class Solution(object):
    def containsDuplicate(self, nums):
        seen = set()
        for num in nums:
            if num in seen:
                return True
            seen.add(num)
        return False
```

---

## 🎯 Complexity Analysis

| Approach | Time | Space | Status |
|----------|------|-------|--------|
| **Hash Set** | **O(n)** | **O(n)** | ✅ Accepted |
| Sorting | O(n log n) | O(n) | ✅ Accepted |
| Brute Force | O(n²) | O(1) | ❌ TLE |

**Why O(n)?**
- Single pass through the array

**Why O(n) space?**
- Set stores up to n elements

---

## 🔥 All Accepted Solutions

| File Name | Language | Runtime | Memory |
|----------|---------|---------|--------|
| 2025-11-21 22.18.11 - Accepted | **Python** 🐍 | **3ms 🟢** | **26MB** |
| 2025-11-21 22.17.12 - Accepted | Python 🐍 | 12ms 🟢 | 25.9MB |
| 2025-11-21 22.15.43 - Accepted | Python 🐍 | 8ms 🟢 | 26MB |
| 2025-11-21 22.15.11 - Accepted | Python 🐍 | 25ms 🟡 | 26.6MB |
| 2025-11-21 22.14.14 - Accepted | Python 🐍 | 20ms 🟡 | 26MB |

---

## 🎓 Key Takeaways

### ✅ Best Practices
1. **Use Hash Set** for O(1) lookup
2. **One-liner solution** with set comparison
3. **Handle edge cases** (empty array, single element)

### ❌ Common Mistakes
1. Not handling large input efficiently
2. Using brute force (causes TLE)
3. Not understanding set properties

### 💡 Follow-up Questions
- How to find duplicates with index constraints?
- How to solve with O(1) extra space?

---

## 🔗 Related Problems

| # | Problem | Difficulty | Status |
|---|---------|-----------|--------|
| 219 | Contains Duplicate II | Easy | 📝 |
| 220 | Contains Duplicate III | Medium | 📝 |
| 442 | Find All Duplicates in an Array | Medium | 📝 |

---

## 📈 Success Metrics

![Python](https://img.shields.io/badge/Python-3776AB?style=flat&logo=python&logoColor=white)

**Total Submissions:** 5️⃣ **Accepted:** 5️⃣ **Acceptance Rate:** 100% ✅

---

*Made with ❤️ | Last Updated: 2026-04-13*
