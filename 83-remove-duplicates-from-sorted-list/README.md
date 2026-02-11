# 83 - Remove Duplicates from Sorted List

**Difficulty:** Easy

**Link:** [Remove Duplicates from Sorted List - LeetCode](https://leetcode.com/problems/remove-duplicates-from-sorted-list/)

## Problem Description

Given the `head` of a sorted linked list, *delete all duplicates such that each element appears only once*. Return *the linked list **sorted** as well*.

## Example Test Cases

### Example 1:
```
Input: head = [1,1,2]
Output: [1,2]
```

### Example 2:
```
Input: head = [1,1,2,3,3]
Output: [1,2,3]
```

## Constraints

- The number of nodes in the list is in the range `[0, 300]`.
- `-100 <= Node.val <= 100`
- The list is guaranteed to be **sorted** in ascending order.

## Solution Approach

### Algorithm Explanation

Iterate through the linked list once, comparing each node with its next node:

1. If current node's value equals next node's value, skip the next node
2. Otherwise, move to the next node
3. Continue until end of list

### Step-by-Step Logic

1. Initialize `cur = head`
2. While `cur` and `cur.next` exist:
   - If `cur.val === cur.next.val`:
     - Set `cur.next = cur.next.next` (skip duplicate)
   - Else:
     - Move `cur = cur.next`
3. Return head

### Why It Works

- List is already sorted, so duplicates are adjacent
- We only need to check immediate neighbors
- Single pass through the list

## Complexity Analysis

- **Time Complexity:** O(n) - Single pass through list
- **Space Complexity:** O(1) - Only pointer manipulation

## Accepted Solutions

| File Name | Language | Runtime | Memory |
|-----------|----------|---------|--------|
| 2026-02-11 10.39.01 - Accepted - runtime 0ms - memory 58MB.js | JavaScript | 0ms | 58MB |

## Code Example (Best Solution - JavaScript)

```javascript
/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @return {ListNode}
 */
function deleteDuplicates(head) {
    let cur = head;

    while (cur && cur.next) {
        if (cur.val === cur.next.val) {
           
            cur.next = cur.next.next;
        } else {
            
            cur = cur.next;
        }
    }

    return head;
}
```

**Runtime:** 0ms | **Memory:** 58MB