# 🚀 LeetCode 206: Reverse Linked List

![Difficulty: Easy](https://img.shields.io/badge/Difficulty-Easy-brightgreen)
![Topic: Linked List](https://img.shields.io/badge/Topic-Linked_List-blue)
![Recursion](https://img.shields.io/badge/Topic-Recursion-blue)
![Status: ✅ Solved](https://img.shields.io/badge/Status-Solved-brightgreen)

## 📋 Problem Statement

Given the head of a singly linked list, reverse the list, and return the reversed list.

---

## 📌 Quick Summary

| | |
|---|---|
| **Problem #** | 206 |
| **Difficulty** | Easy |
| **Topics** | Linked List, Recursion |
| **Companies** | Amazon, Apple, Microsoft |
| **Similar Problems** | [Reverse Linked List II](./92-reverse-linked-list-ii) |

---

## 🎯 Example Test Cases

### ✅ Example 1:
```
Input: head = [1,2,3,4,5]
Output: [5,4,3,2,1]
```

### ✅ Example 2:
```
Input: head = [1,2]
Output: [2,1]
```

### ✅ Example 3:
```
Input: head = []
Output: []
```

---

## ⚠️ Constraints

```
0 ≤ The number of nodes in the list ≤ 5000
-5000 ≤ Node.val ≤ 5000
```

---

## 💡 Solution Approaches

### 🔹 Approach 1: Iterative (Optimal) ✅ RECOMMENDED

**Intuition:** Use three pointers to reverse the links one by one.

| | |
|---|---|
| **Time** | O(n) |
| **Space** | O(1) |
| **Runtime** | 0ms ✅ |

**Step-by-Step:**
1. Initialize `prev = null`, `curr = head`
2. While curr is not null:
   - Save next node
   - Reverse the pointer (curr.next = prev)
   - Move prev and curr forward
3. Return prev

**Why it works:**
- Each node's pointer is reversed in place
- Single pass through the list
- No extra memory needed

---

### 🔹 Approach 2: Recursive (Alternative)

```javascript
function reverseList(head) {
    if (!head || !head.next) return head;
    let newHead = reverseList(head.next);
    head.next.next = head;
    head.next = null;
    return newHead;
}
```

| | |
|---|---|
| **Time** | O(n) |
| **Space** | O(n) for recursion stack |

---

## 📝 Detailed Implementation

### JavaScript ⭐
```javascript
function ListNode(val, next = null) {
    this.val = val;
    this.next = next;
}

var reverseList = function(head) {
    let prev = null;
    let curr = head;

    while (curr) {
        let nextNode = curr.next;
        curr.next = prev;
        prev = curr;
        curr = nextNode;
    }

    return prev;
};
```

**Key Points:**
- Three pointer technique (prev, curr, nextNode)
- In-place reversal
- Runtime: 0ms, Memory: 56.9MB

---

## 🎯 Complexity Analysis

| Approach | Time | Space | Status |
|----------|------|-------|--------|
| **Iterative** | **O(n)** | **O(1)** | ✅ Accepted |
| Recursive | O(n) | O(n) | ✅ Accepted |

**Why O(n)?**
- Single pass through all n nodes
- Each node processed once

**Why O(1) space?**
- Only three pointer variables used

---

## 🔥 All Accepted Solutions

| File Name | Language | Runtime | Memory |
|----------|---------|---------|--------|
| 2026-03-08 17.43.38 - Accepted | **JavaScript** | **0ms 🟢** | **56.9MB** |

---

## 🎓 Key Takeaways

### ✅ Best Practices
1. **Use three pointers** for iterative reversal
2. **Save next node** before reversing the pointer
3. **Handle edge cases** (empty list, single node)

### ❌ Common Mistakes
1. Forgetting to save next node (losing the rest of list)
2. Not handling null/empty list
3. Not updating pointers correctly

### 💡 Follow-up Questions
- How to reverse a portion of the list?
- How to reverse in place recursively?

---

## 🔗 Related Problems

| # | Problem | Difficulty | Status |
|---|---------|-----------|--------|
| 92 | Reverse Linked List II | Medium | 📝 |
| 234 | Palindrome Linked List | Easy | 📝 |
| 21 | Merge Two Sorted Lists | Easy | 📝 |

---

## 📈 Success Metrics

![JavaScript](https://img.shields.io/badge/JavaScript-F7DF1E?style=flat&logo=javascript&logoColor=black)

**Total Submissions:** 1️⃣ **Accepted:** 1️⃣ **Acceptance Rate:** 100% ✅

---

*Made with ❤️ | Last Updated: 2026-04-13*
