# 345 - Reverse Vowels of a String

**Difficulty:** Easy

**Link:** [Reverse Vowels of a String - LeetCode](https://leetcode.com/problems/reverse-vowels-of-a-string/)

## Problem Description

Given a string `s`, reverse only all the vowels in the string and return it.

The vowels are `'a'`, `'e'`, `'i'`, `'o'`, and `'u'`, and they can appear in both lower and upper cases, more than once.

## Example Test Cases

### Example 1:
```
Input: s = "IceCreAm"
Output: "AceCreIm"
Explanation: The vowels in s are ['I', 'e', 'e', 'A']. On reversing the vowels, s becomes "AceCreIm".
```

### Example 2:
```
Input: s = "leetcode"
Output: "leotcede"
```

## Constraints

- `1 <= s.length <= 3 * 10^5`
- `s` consist of printable ASCII characters.

## Solution Approach

### Algorithm Explanation

Two-pointer approach similar to string reversal:

1. Use pointers at both ends of the string
2. Move left pointer until a vowel is found
3. Move right pointer until a vowel is found
4. Swap the vowels
5. Continue until pointers meet

### Step-by-Step Logic

1. Initialize `i = 0`, `j = s.size() - 1`
2. While `i < j`:
   - Move `i` forward while `s[i]` is not a vowel
   - Move `j` backward while `s[j]` is not a vowel
   - Swap `s[i]` and `s[j]`
   - Increment `i`, decrement `j`
3. Return the modified string

### Why It Works

- Only vowels need to be swapped; consonants remain in place
- The two-pointer approach ensures each character is visited at most once
- Case-insensitive vowel checking handles both uppercase and lowercase

## Complexity Analysis

- **Time Complexity:** O(n) - Single pass through string
- **Space Complexity:** O(1) - In-place modification

## Accepted Solutions

| File Name | Language | Runtime | Memory |
|-----------|----------|---------|--------|
| 2026-01-31 15.00.49 - Accepted - runtime 1ms - memory 58.9MB.js | JavaScript | 1ms | 58.9MB |
| 2026-04-09 11.31.05 - Accepted - runtime 4ms - memory 10.4MB.cpp | C++ | 4ms | 10.4MB |
| 2026-04-09 11.31.52 - Accepted - runtime 3ms - memory 10.1MB.cpp | C++ | 3ms | 10.1MB |

## Code Example (Best Solution - C++)

```cpp
class Solution {
public:
    bool isVowel(char c) {
        c = tolower(c);
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

    string reverseVowels(string s) {
        int i = 0, j = s.size() - 1;

        while (i < j) {
            while (i < j && !isVowel(s[i])) i++;
            while (i < j && !isVowel(s[j])) j--;

            swap(s[i], s[j]);
            i++;
            j--;
        }

        return s;
    }
};
```

**Runtime:** 3ms | **Memory:** 10.1MB