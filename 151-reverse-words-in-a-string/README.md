# 151. Reverse Words in a String

**Difficulty: Medium**

## Problem Description

Given an input string `s`, reverse the order of the words. A word is defined as a sequence of non-space characters. The words in `s` will be separated by at least one space. Return a string of the words in reverse order concatenated by a single space.

Note that `s` may contain leading or trailing spaces or multiple spaces between two words. The returned string should only have a single space separating the words. Do not include any extra spaces.

**Example 1:**
```
Input: s = "the sky is blue"
Output: "blue is sky the"
```

**Example 2:**
```
Input: s = " hello world "
Output: "world hello"
```

**Example 3:**
```
Input: s = "a good example"
Output: "example good a"
```

**Constraints:**
* `1 <= s.length <= 10^4`
* `s` contains English letters (upper-case and lower-case), digits, and spaces ' '.
* There is at least one word in `s`.

**Follow-up:** If the string data type is mutable in your language, can you solve it in-place with O(1) extra space?

## Solution Approach

This problem can be solved simply using built-in string methods:
1. **Trim** leading and trailing spaces from the string.
2. **Split** the string by one or more whitespace characters using regex.
3. **Reverse** the array of words.
4. **Join** the reversed words with a single space.

## Complexity Analysis

- **Time Complexity:** O(n) where n is the length of the string.
- **Space Complexity:** O(n) for storing the split words and result.

## Accepted Solution Files

| File | Language | Runtime | Memory |
|------|----------|----------|--------|
| 2026-01-31 14.58.56 - Accepted - runtime 1ms - memory 56.5MB.js | JavaScript | 1ms | 56.5MB |
| 2026-04-11 14.12.50 - Accepted - runtime 0ms - memory 10MB.cpp | C++ | 0ms | 10MB |

## Best Code Example

```javascript
var reverseWords = function(s) {
    return s
        .trim()
        .split(/\s+/)
        .reverse()
        .join(" ");
};
```

This elegant solution uses method chaining:
- `.trim()` removes leading/trailing spaces
- `.split(/\s+/)` splits on one or more whitespace characters
- `.reverse()` reverses the word order
- `.join(" ")` combines them with single spaces