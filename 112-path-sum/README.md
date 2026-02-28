# 112 - Path Sum

**Difficulty:** Easy

**Link:** [Path Sum - LeetCode](https://leetcode.com/problems/path-sum/)

## Problem Description

Given the `root` of a binary tree and an integer `targetSum`, return `true` if the tree has a **root-to-leaf** path such that adding up all the values along the path equals `targetSum`.

A **leaf** is a node with no children.

## Example Test Cases

### Example 1:
```
Input: root = [5,4,8,11,null,13,4,7,2,null,null,null,1], targetSum = 22
Output: true
Explanation: The root-to-leaf path with the target sum is shown.
```

### Example 2:
```
Input: root = [1,2,3], targetSum = 5
Output: false
Explanation: There are two root-to-leaf paths in the tree:
(1 -> 2): The sum is 3.
(1 -> 3): The sum is 4.
There is no root-to-leaf path with sum = 5.
```

### Example 3:
```
Input: root = [], targetSum = 0
Output: false
```

## Constraints

- The number of nodes in the tree is in the range `[0, 5000]`.
- `-1000 <= Node.val <= 1000`
- `-1000 <= targetSum <= 1000`

## Solution Approach

### Algorithm Explanation

Use **recursion** (DFS) to traverse from root to leaves:

1. For each node, subtract its value from targetSum
2. When reaching a leaf node, check if remaining targetSum equals leaf value
3. Recursively check both left and right subtrees

### Step-by-Step Logic

1. If root is null, return false
2. If leaf node (no left and right children):
   - Return true if targetSum == root.val
   - Otherwise return false
3. Recurse on left subtree with targetSum - root.val
4. Recurse on right subtree with targetSum - root.val
5. Return true if either path returns true

### Why It Works

- Each path from root to leaf is explored
- Subtracting node values along the path tracks remaining sum needed
- Base case at leaf correctly identifies valid paths

## Complexity Analysis

- **Time Complexity:** O(n) - Visit each node at most once
- **Space Complexity:** O(H) - Recursion stack depth equals tree height

## Accepted Solutions

| File Name | Language | Runtime | Memory |
|-----------|----------|---------|--------|
| 2026-02-28 10.34.05 - Accepted - runtime 0ms - memory 58.9MB.js | JavaScript | 0ms | 58.9MB |
| 2026-02-28 10.45.08 - Accepted - runtime 0ms - memory 21.6MB.cpp | C++ | 0ms | 21.6MB |

## Code Example (Best Solution - C++)

```cpp
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {

        if (root == NULL) {
            return false;
        }

        
        if (root->left == NULL && root->right == NULL) {
            if (targetSum == root->val) {
                return true;
            } else {
                return false;
            }
        }


        bool left = hasPathSum(root->left, targetSum - root->val);


        bool right = hasPathSum(root->right, targetSum - root->val);

        if (left == true || right == true) {
            return true;
        } else {
            return false;
        }
    }
};
```

**Runtime:** 0ms | **Memory:** 21.6MB