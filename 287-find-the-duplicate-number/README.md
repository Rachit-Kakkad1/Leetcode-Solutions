# 🚀 LeetCode 287: Find the Duplicate Number

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-yellow)
![Topic: Array](https://img.shields.io/badge/Topic-Array-blue)
![Hash Table](https://img.shields.io/badge/Topic-Hash_Table-blue)
![Two Pointers](https://img.shields.io/badge/Topic-Two_Pointers-blue)
![Binary Search](https://img.shields.io/badge/Topic-Binary_Search-blue)
![Status: ✅ Solved](https://img.shields.io/badge/Status-Solved-brightgreen)

## 📋 Problem Statement

Given an array `nums` containing `n + 1` integers where each integer is between `1` and `n` (inclusive), there is only one repeated number.

Find the duplicate number.

You must solve the problem **without** modifying the array `nums` and using only constant extra space.

---

## 📌 Quick Summary

| | |
|---|---|
| **Problem #** | 287 |
| **Difficulty** | Medium |
| **Topics** | Array, Hash Table, Two Pointers, Binary Search |
| **Companies** | Amazon, Apple, Google, Microsoft |
| **Similar Problems** | [Linked List Cycle II](./142-linked-list-cycle-ii) |

---

## 🎯 Example Test Cases

### ✅ Example 1:
```
Input: nums = [1,3,4,2,2]
Output: 2
```

### ✅ Example 2:
```
Input: nums = [3,1,3,4,2]
Output: 3
```

### ✅ Example 3:
```
Input: nums = [2,2,2,2,2]
Output: 2
```

---

## ⚠️ Constraints

```
2 ≤ n ≤ 10^5
nums.length == n + 1
1 ≤ nums[i] ≤ n
Duplicate number can be repeated
```

---

## 💡 Solution Approaches

### 🔹 Approach 1: Floyd's Tortoise and Hare (Optimal) ✅ RECOMMENDED

**Intuition:** Treat the array as a linked list where index i points to nums[i]. The duplicate creates a cycle.

| | |
|---|---|
| **Time** | O(n) |
| **Space** | O(1) |
| **Runtime** | 0ms ✅ |

**Step-by-Step:**
1. Phase 1: Find intersection point
   - slow = nums[slow], fast = nums[nums[fast]]
   - Continue until they meet
2. Phase 2: Find entrance to cycle (duplicate)
   - Reset slow to nums[0]
   - Move both at same speed
   - They meet at the duplicate number

**Why it works:**
- Array indices 1 to n form a linked list
- Duplicate number creates a cycle (two indices point to same location)
- Floyd's algorithm finds the cycle entrance

---

### 🔹 Approach 2: Binary Search (Alternative)

Count how many numbers are ≤ mid to find the duplicate.

| | |
|---|---|
| **Time** | O(n log n) |
| **Space** | O(1) |

---

### 🔹 Approach 3: Negative Marking (NOT RECOMMENDED - modifies array)

Use the sign of numbers to mark visited.

---

## 📝 Detailed Implementation

### C++ ⭐
```cpp
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[0];

        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);

        slow = nums[0];
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }
};
```

**Key Points:**
- Floyd's Tortoise and Hare algorithm
- O(n) time, O(1) space
- Runtime: 0ms, Memory: 65.1MB

---

## 🎯 Complexity Analysis

| Approach | Time | Space | Status |
|----------|------|-------|--------|
| **Floyd's Algorithm** | **O(n)** | **O(1)** | ✅ Accepted |
| Binary Search | O(n log n) | O(1) | ✅ Accepted |
| Hash Set | O(n) | O(n) | ⚠️ Not allowed |
| Negative Marking | O(n) | O(1) | ⚠️ Modifies array |

**Why O(n)?**
- Phase 1: O(n) to find intersection
- Phase 2: O(n) to find duplicate

**Why O(1) space?**
- Only two pointer variables used

---

## 🔥 All Accepted Solutions

| File Name | Language | Runtime | Memory |
|----------|---------|---------|--------|
| 2026-04-06 09.37.06 - Accepted | **C++** | **0ms 🟢** | **65.1MB** |

---

## 🎓 Key Takeaways

### ✅ Best Practices
1. **Use Floyd's algorithm** for O(1) space solution
2. **Treat array as linked list** concept
3. **Two-phase detection** finds cycle entrance

### ❌ Common Mistakes
1. Modifying the array (not allowed)
2. Using extra space (not allowed)
3. Not understanding cycle detection

### 💡 Follow-up Questions
- How to find all duplicate numbers?
- How to solve with O(n) time and O(1) space without modifying?

---

## 🔗 Related Problems

| # | Problem | Difficulty | Status |
|---|---------|-----------|--------|
| 142 | Linked List Cycle II | Medium | 📝 |
| 141 | Linked List Cycle | Easy | 📝 |
| 268 | Missing Number | Easy | 📝 |

---

## 📈 Success Metrics

![C++](https://img.shields.io/badge/C++-00599C?style=flat&logo=c%2B%2B&logoColor=white)

**Total Submissions:** 1️⃣ **Accepted:** 1️⃣ **Acceptance Rate:** 100% ✅

---

*Made with ❤️ | Last Updated: 2026-04-13*
