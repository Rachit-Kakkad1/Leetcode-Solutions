# 🚀 LeetCode 21: Merge Two Sorted Lists

![Difficulty: Easy](https://img.shields.io/badge/Difficulty-Easy-brightgreen)
![Linked List](https://img.shields.io/badge/Topic-Linked_List-blue)
![Recursion](https://img.shields.io/badge/Topic-Recursion-blue)
![Status: ✅ Solved](https://img.shields.io/badge/Status-Solved-brightgreen)

## 📋 Problem Statement

You are given the heads of two sorted linked lists `list1` and `list2`. Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.

The list should be made by splicing together the nodes of the first two lists.

---

## 📌 Quick Summary

| | |
|---|---|
| **Problem #** | 21 |
| **Difficulty** | Easy |
| **Topics** | Linked List, Recursion |
| **Companies** | Amazon, Apple, Google |
| **Similar Problems** | [Merge K Sorted Lists](./), [Merge In Between](./) |

---

## 🎯 Example Test Cases

### ✅ Example 1:
```
Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]
```

### ✅ Example 2:
```
Input: list1 = [], list2 = []
Output: []
```

### ✅ Example 3:
```
Input: list1 = [], list2 = [0]
Output: [0]
```

---

## ⚠️ Constraints

- The number of nodes in both lists is in range [0, 50]
- -100 ≤ Node.val ≤ 100
- Both list1 and list2 are sorted in non-decreasing order

---

## 💡 Solution Approaches

### 🔹 Approach 1: Iterative with Dummy Node (Optimal) ✅ RECOMMENDED

**Intuition:** Use dummy node to simplify edge cases and pointer manipulation.

| | |
|---|---|
| **Time** | O(m + n) |
| **Space** | O(1) |
| **Runtime** | 0ms ✅ |

**Step-by-Step:**
1. Create dummy node
2. Compare nodes from both lists
3. Attach smaller node to result
4. Continue until one list exhausted
5. Attach remaining list

**Why it works:**
- Each node is visited once
- In-place merging

---

### 🔹 Approach 2: Recursive

Use recursion to merge lists.

| | |
|---|---|
| **Time** | O(m + n) |
| **Space** | O(m + n) |

---

## 📝 Detailed Implementation

### JavaScript ⭐
```javascript
function ListNode(val, next = null) {
    this.val = val;
    this.next = next;
}

var mergeTwoLists = function(list1, list2) {
    let dummy = new ListNode(0);
    let tail = dummy;

    while (list1 && list2) {
        if (list1.val <= list2.val) {
            tail.next = list1;
            list1 = list1.next;
        } else {
            tail.next = list2;
            list2 = list2.next;
        }
        tail = tail.next;
    }

    tail.next = list1 ? list1 : list2;

    return dummy.next;
};
```

**Key Points:**
- Uses dummy node pattern
- In-place merging
- Runtime: 0ms, Memory: 58.1MB

---

## 🎯 Complexity Analysis

| Approach | Time | Space | Status |
|----------|------|-------|--------|
| **Iterative + Dummy** | **O(m + n)** | **O(1)** | ✅ Accepted |
| Recursive | O(m + n) | O(m + n) | ✅ Accepted |

**Why O(m + n)?**
- Visit each node once

---

## 🔥 All Accepted Solutions

| File Name | Language | Runtime | Memory |
|----------|---------|---------|--------|
| 2026-02-08 17.19.37 - Accepted - runtime 0ms - memory 58.1MB.js | **JavaScript** | **0ms 🟢** | **58.1MB** |

---

## 🎓 Key Takeaways

### ✅ Best Practices
1. Use dummy node to simplify
2. Handle empty list cases
3. Move pointers forward

### ❌ Common Mistakes
1. Not handling empty lists
2. Forgetting to advance pointers
3. Memory leaks in recursion

---

## 📈 Success Metrics

![JavaScript](https://img.shields.io/badge/JavaScript-F7DF1E?style=flat&logo=javascript&logoColor=black)

**Total Submissions:** 1️⃣ **Accepted:** 1️⃣ **Acceptance Rate:** 100% ✅

---

*Made with ❤️ | Last Updated: 2026-04-13*