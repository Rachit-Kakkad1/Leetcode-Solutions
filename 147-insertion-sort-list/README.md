# 147. Insertion Sort List

**Difficulty: Medium**

## Problem Description

Given the head of a singly linked list, sort the list using insertion sort algorithm.

**Example 1:**
```
Input: head = [4,2,1,3]
Output: [1,2,3,4]
```

**Example 2:**
```
Input: head = [-1,5,3,4,0]
Output: [-1,0,3,4,5]
```

**Constraints:**
* The number of nodes in the list is in the range [0, 5000].
* `-5000 <= Node.val <= 5000`

## Solution Approach

We use the **Insertion Sort** algorithm adapted for linked lists:
1. Create a dummy node to simplify edge cases.
2. Iterate through the original list.
3. For each node, find the correct position in the new sorted list.
4. Insert the node at that position.

Key insight: Using a dummy node simplifies insertion at the beginning of the list.

## Complexity Analysis

- **Time Complexity:** O(n²) in worst case, since for each of n nodes we may need to scan up to n positions.
- **Space Complexity:** O(1) - only pointer manipulations, no extra data structures.

## Accepted Solution Files

| File | Language | Runtime | Memory |
|------|----------|----------|--------|
| 2026-03-08 17.12.49 - Accepted - runtime 35ms - memory 58.7MB.js | JavaScript | 35ms | 58.7MB |

## Best Code Example

```javascript
function ListNode(val, next = null) {
    this.val = val;
    this.next = next;
}

var insertionSortList = function(head) {
    let dummy = new ListNode(0);
    let curr = head;

    while (curr) {
        let prev = dummy;
        let nextNode = curr.next;

        while (prev.next && prev.next.val < curr.val) {
            prev = prev.next;
        }

        curr.next = prev.next;
        prev.next = curr;

        curr = nextNode;
    }

    return dummy.next;
};
```