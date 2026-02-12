# 131 - Palindrome Partitioning

**Difficulty:** Medium

**Link:** [Palindrome Partitioning - LeetCode](https://leetcode.com/problems/palindrome-partitioning/)

## Problem Description

Given a string `s`, partition `s` such that every substring of the partition is a **palindrome**. Return *all possible palindrome partitioning of* `s`.

## Example Test Cases

### Example 1:
```
Input: s = "aab"
Output: [["a","a","b"],["aa","b"]]
```

### Example 2:
```
Input: s = "a"
Output: [["a"]]
```

## Constraints

- `1 <= s.length <= 16`
- `s` contains only lowercase English letters.

## Solution Approach

### Algorithm Explanation

Use **backtracking** to generate all possible palindrome partitions:

1. For each starting position, try all possible ending positions
2. Check if substring is a palindrome
3. If palindrome, add to current path and recurse for remaining string
4. Backtrack after exploring

### Step-by-Step Logic

1. Initialize empty result and path arrays
2. Call backtrack function starting from index 0
3. In backtrack:
   - If start equals string length, add copy of path to result
   - For each end from start to length-1:
     - If substring(start, end+1) is palindrome:
       - Add substring to path
       - Recurse with end+1
       - Remove last element (backtrack)
4. Helper function checks palindrome using two pointers

### Why It Works

- All possible partitions are explored through recursion
- Palindrome check ensures each partition is valid
- Backtracking correctly explores all combinations

## Complexity Analysis

- **Time Complexity:** O(n * 2^n) - Generating all partitions in worst case
- **Space Complexity:** O(n) - Recursion stack and path storage

## Accepted Solutions

| File Name | Language | Runtime | Memory |
|-----------|----------|---------|--------|
| 2026-02-12 06.01.33 - Accepted - runtime 21ms - memory 80.4MB.js | JavaScript | 21ms | 80.4MB |

## Code Example (Best Solution - JavaScript)

```javascript
/**
 * @param {string} s
 * @return {string[][]}
 */
function partition(s) {
    const result = [];
    const path = [];

    function backtrack(start) {
        if (start === s.length) {
            result.push([...path]);
            return;
        }

        for (let end = start; end < s.length; end++) {
            if (isPalindrome(s, start, end)) {
                path.push(s.substring(start, end + 1));
                backtrack(end + 1);
                path.pop(); 
            }
        }
    }

    backtrack(0);
    return result;
}

function isPalindrome(str, left, right) {
    while (left < right) {
        if (str[left] !== str[right]) return false;
        left++;
        right--;
    }
    return true;
}
```

**Runtime:** 21ms | **Memory:** 80.4MB