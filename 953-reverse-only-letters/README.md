# 953 - Reverse Only Letters

**Difficulty:** Easy

**Link:** [Reverse Only Letters - LeetCode](https://leetcode.com/problems/reverse-only-letters/)

## Problem Description

Given a string `s`, reverse the string according to the following rules:

- All the characters that are not English letters remain in the same position.
- All the English letters (lowercase or uppercase) should be reversed.

Return `s` *after reversing it*.

## Example Test Cases

### Example 1:
```
Input: s = "ab-cd"
Output: "dc-ba"
```

### Example 2:
```
Input: s = "a-bC-dEf-ghIj"
Output: "j-Ih-gfE-dCba"
```

### Example 3:
```
Input: s = "Test1ng-Leet=code-Q!"
Output: "Qedo1ct-eeLg=ntse-T!"
```

## Constraints

- `1 <= s.length <= 100`
- `s` consists of characters with ASCII values in the range `[33, 122]`.
- `s` does not contain `'"'` or `'\\'`.

## Solution Approach

### Algorithm Explanation

Two-pointer approach for in-place reversal:

1. Use two pointers from start and end
2. Skip non-letter characters
3. When both pointers point to letters, swap them
4. Continue until pointers meet

### Step-by-Step Logic

1. Initialize i = 0, j = s.length - 1
2. While i < j:
   - If s[i] is not a letter, increment i
   - Else if s[j] is not a letter, decrement j
   - Else swap s[i] and s[j], increment i, decrement j
3. Return modified string

### Why It Works

- Non-letter characters stay in place (swap is skipped)
- Only letters are swapped in reverse order
- Single pass through the string

## Complexity Analysis

- **Time Complexity:** O(n) - Single pass with two pointers
- **Space Complexity:** O(1) - In-place modification

## Accepted Solutions

| File Name | Language | Runtime | Memory |
|-----------|----------|---------|--------|
| 2026-04-09 12.14.00 - Accepted - runtime 0ms - memory 8.1MB.cpp | C++ | 0ms | 8.1MB |

## Code Example (Best Solution - C++)

```cpp
class Solution {
public:
    string reverseOnlyLetters(string s) {
        int i = 0;
        int j = s.size() - 1;

        while (i < j) {
            if (!((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))) {
                i++;
            }

            else if (!((s[j] >= 'a' && s[j] <= 'z') || (s[j] >= 'A' && s[j] <= 'Z'))) {
                j--;
            }

            else {
                swap(s[i], s[j]);
                i++;
                j--;
            }
        }

        return s;
    }
};
```

**Runtime:** 0ms | **Memory:** 8.1MB