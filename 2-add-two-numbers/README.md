# 🚀 LeetCode 2: Add Two Numbers

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-yellow)
![Topic: Linked List](https://img.shields.io/badge/Topic-Linked_List-blue)
![Math](https://img.shields.io/badge/Topic-Math-blue)
![Status: ✅ Solved](https://img.shields.io/badge/Status-Solved-brightgreen)

## 📋 Problem Statement

You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each node contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume that each input would have **exactly one solution**, and you may not use the **same element twice**.

You can return the answer in any order.

---

## 📌 Quick Summary

| | |
|---|---|
| **Problem #** | 2 |
| **Difficulty** | Medium |
| **Topics** | Linked List, Math |
| **Companies** | Amazon, Apple, Microsoft |
| **Similar Problems** | [Add Two Numbers II](./445-add-two-numbers-ii), [Multiply Strings](./43-multiply-strings) |

---

## 🎯 Example Test Cases

### ✅ Example 1:
```
Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.
```

### ✅ Example 2:
```
Input: l1 = [0], l2 = [0]
Output: [0]
```

### ✅ Example 3:
```
Input: l1 = [9,9,9,9,9,9,9], l2 = [1,1,1,1,1,1,1]
Output: [0,1,1,1,1,1,1,1]
Explanation: 9999999 + 1111111 = 11111110
```

---

## ⚠️ Constraints

- The number of nodes in each list is in the range [1, 100].
- Each node's value is a digit 0-9.
- The lists are stored in reverse order.
- 0 ≤ each linked list value ≤ 9

---

## 💡 Solution Approaches

### 🔹 Approach 1: Iterative Addition (Optimal) ✅ RECOMMENDED

**Intuition:** Iterate through both lists simultaneously, adding corresponding digits plus carry.

| | |
|---|---|
| **Time** | O(max(m, n)) |
| **Space** | O(max(m, n)) |
| **Runtime** | 0ms ✅ |

**Step-by-Step:**
1. Create a dummy head for the result list
2. Initialize carry = 0
3. Iterate while any list has nodes or carry exists:
   - Get digit from l1 (or 0 if null)
   - Get digit from l2 (or 0 if null)
   - Sum = digit1 + digit2 + carry
   - New digit = sum % 10
   - Carry = sum / 10
   - Create new node with digit
4. Return dummy.next

**Why it works:**
- Single pass through both lists
- Handles different length lists
- Properly manages carry propagation

---

### 🔹 Approach 2: Recursive (Alternative)

```
def addTwoNumbersRecursive(l1, l2, carry):
    if not l1 and not l2 and carry == 0:
        return None
    
    val = (l1.val if l1 else 0) + (l2.val if l2 else 0) + carry
    carry = val // 10
    val = val % 10
    
    node = ListNode(val)
    node.next = addTwoNumbersRecursive(
        l1.next if l1 else None,
        l2.next if l2 else None,
        carry
    )
    return node
```

| | |
|---|---|
| **Time** | O(max(m, n)) |
| **Space** | O(max(m, n)) |

---

## 📝 Detailed Implementation

### C (Best Performance) ⭐
```c
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *head = NULL, *tail = NULL;
    int carry = 0;

    while (l1 != NULL || l2 != NULL || carry != 0) {
        int x = (l1 != NULL) ? l1->val : 0;
        int y = (l2 != NULL) ? l2->val : 0;
        int sum = x + y + carry;

        carry = sum / 10;
        int digit = sum % 10;

        struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
        newNode->val = digit;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }

        if (l1 != NULL) l1 = l1->next;
        if (l2 != NULL) l2 = l2->next;
    }

    return head;
}
```

**Key Points:**
- Uses dummy head pattern
- Early termination when both lists exhausted
- Memory management with malloc

---

## 🎯 Complexity Analysis

| Approach | Time | Space | Status |
|----------|------|-------|--------|
| **Iterative** | **O(max(m, n))** | **O(max(m, n))** | ✅ Accepted |
| Recursive | O(max(m, n)) | O(max(m, n)) | ✅ Accepted |

**Why O(max(m, n))?**
- We iterate through the longer of the two lists
- Each iteration does constant work

**Why O(max(m, n)) space?**
- Result list has max(m, n) + 1 nodes (for carry)

---

## 🔥 All Accepted Solutions

| File Name | Language | Runtime | Memory |
|----------|---------|---------|--------|
| 2025-11-09 10.54.31 - Accepted - runtime 2ms - memory 12.6MB.c | C | 2ms 🟡 | 12.6MB |
| 2025-11-09 10.56.13 - Accepted - runtime 0ms - memory 12.5MB.c | **C++** | **0ms 🟢** | **12.5MB** |

---

## 🎓 Key Takeaways

### ✅ Best Practices
1. **Use dummy head** for building the result list
2. **Handle carry propagation** properly
3. **Handle different length lists** by treating missing nodes as 0

### ❌ Common Mistakes
1. Forgetting to handle carry after the final iteration
2. Not initializing the result list properly
3. Memory leaks in C (forgetting to free)

### 💡 Follow-up Questions
- What if the lists are in forward order?
- How would you handle very large numbers?

---

## 🔗 Related Problems

| # | Problem | Difficulty | Status |
|---|---------|-----------|--------|
| 445 | Add Two Numbers II | Medium | 📝 |
| 43 | Multiply Strings | Medium | 📝 |
| 67 | Add Binary | Easy | 📝 |

---

## 📈 Success Metrics

![C](https://img.shields.io/badge/C-A8B9CC?style=flat&logo=c&logoColor=white)

**Total Submissions:** 2️⃣ **Accepted:** 2️⃣ **Acceptance Rate:** 100% ✅

---

*Made with ❤️ | Last Updated: 2026-04-13*