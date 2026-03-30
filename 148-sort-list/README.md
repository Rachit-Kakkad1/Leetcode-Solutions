# 148. Sort List

**Difficulty: Medium**

## Problem Description

Sort a linked list in O(n log n) time using constant space.

**Example 1:**
```
Input: head = [4,2,1,3]
Output: [1,2,3,4]
```

**Constraints:**
* `0 <= n <= 5 * 10^4`
* `-10^5 <= Node.val <= 10^5`

## Solution Approach

We use **merge sort** (recursive):
1. Find the middle node using slow/fast pointers.
2. Recursively split into two sublists.
3. Merge the two sorted sublists.

## Complexity Analysis

- **Time Complexity:** O(n log n).
- **Space Complexity:** O(log n) - recursion stack.

## Accepted Solution Files

| File | Language | Runtime | Memory |
|------|----------|----------|--------|
| 2026-03-30 15.07.20 - Accepted - runtime 446ms - memory 50.7MB.py | Python | 446ms | 50.7MB |

## Best Code Example

```python
class Solution:
    def sortList(self, head):
        if not head or not head.next:
            return head

        slow, fast = head, head.next
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next

        mid = slow.next
        slow.next = None

        left = self.sortList(head)
        right = self.sortList(mid)

        return self.merge(left, right)

    def merge(self, l1, l2):
        dummy = ListNode(0)
        cur = dummy

        while l1 and l2:
            if l1.val < l2.val:
                cur.next = l1
                l1 = l1.next
            else:
                cur.next = l2
                l2 = l2.next
            cur = cur.next

        cur.next = l1 or l2
        return dummy.next
```