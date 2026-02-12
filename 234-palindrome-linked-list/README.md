# 234 - Palindrome Linked List

**Difficulty:** Easy  
**Problem Link:** [palindrome-linked-list](https://leetcode.com/problems/palindrome-linked-list/)

## Problem Description

Given the `head` of a singly linked list, return `true` if it is a palindrome or `false` otherwise.

## Solution Approach

**Reverse Half + Compare:**
1. Use fast-slow pointers to find the middle
2. Reverse the second half of the linked list
3. Compare the first half with the reversed second half
4. Restore the list (optional)

## Complexity Analysis

- **Time Complexity:** O(n) where n = number of nodes
- **Space Complexity:** O(1) - only pointer manipulation

## Accepted Solutions

| File | Runtime | Memory | Language |
|------|---------|--------|----------|
| 2026-02-12 06.16.19 - Accepted - runtime 3ms - memory 74.9MB.js | 3ms | 74.9MB | JavaScript |

## Best Code Example

```javascript
function isPalindrome(head) {
    if (!head || !head.next) return true;

    let slow = head;
    let fast = head;

    while (fast && fast.next) {
        slow = slow.next;
        fast = fast.next.next;
    }

    let prev = null;
    while (slow) {
        const next = slow.next;
        slow.next = prev;
        prev = slow;
        slow = next;
    }

    let left = head;
    let right = prev;

    while (right) {
        if (left.val !== right.val) return false;
        left = left.next;
        right = right.next;
    }

    return true;
}
```