# 🚀 LeetCode 28: Find the Index of the First Occurrence in a String

![Difficulty: Easy](https://img.shields.io/badge/Difficulty-Easy-brightgreen)
![Topic: String](https://img.shields.io/badge/Topic-String-blue)
![Two Pointers](https://img.shields.io/badge/Topic-Two_Pointers-blue)
![String Matching](https://img.shields.io/badge/Topic-String_Matching-blue)
![Status: ✅ Solved](https://img.shields.io/badge/Status-Solved-brightgreen)

## 📋 Problem Statement

Given two strings `needle` and `haystack`, return the index of the first occurrence of `needle` in `haystack`, or `-1` if `needle` is not part of `haystack`.

---

## 📌 Quick Summary

| | |
|---|---|
| **Problem #** | 28 |
| **Difficulty** | Easy |
| **Topics** | String, Two Pointers, String Matching |
| **Companies** | Amazon, Apple, Google, Microsoft |
| **Similar Problems** | [Implement strStr()](./) |

---

## 🎯 Example Test Cases

### ✅ Example 1:
```
Input: haystack = "sadbutsad", needle = "sad"
Output: 0
Explanation: "sad" occurs at index 0 and 6. First occurrence is at index 0.
```

### ✅ Example 2:
```
Input: haystack = "leetcode", needle = "leeto"
Output: -1
Explanation: "leeto" did not occur in "leetcode".
```

---

## ⚠️ Constraints

```
1 ≤ haystack.length, needle.length ≤ 10^4
haystack and needle consist of only lowercase English characters
```

---

## 💡 Solution Approaches

### 🔹 Approach 1: Sliding Window (Optimal) ✅ RECOMMENDED

**Intuition:** Try each possible starting position in haystack.

| | |
|---|---|
| **Time** | O(n * m) |
| **Space** | O(1) |
| **Runtime** | 0ms ✅ |

**Step-by-Step:**
1. Let `n = haystack.length`, `m = needle.length`
2. For `i` from 0 to `n - m`:
   - Compare each character of needle with haystack starting at position `i`
   - If all `m` characters match, return `i`
3. If no match found, return -1

**Why it works:**
- Check all possible starting positions where needle could fit
- Return immediately on first match

---

## 📝 Detailed Implementation

### JavaScript ⭐
```javascript
function strStr(haystack, needle) {
    const n = haystack.length;
    const m = needle.length;

    for (let i = 0; i <= n - m; i++) {
        let j = 0;

        while (j < m && haystack[i + j] === needle[j]) {
            j++;
        }

        if (j === m) return i;
    }

    return -1;
}
```

**Key Points:**
- Sliding window approach
- O(n*m) time, O(1) space
- Runtime: 0ms, Memory: 54.1MB

---

## 🎯 Complexity Analysis

| Approach | Time | Space | Status |
|----------|------|-------|--------|
| **Sliding Window** | **O(n * m)** | **O(1)** | ✅ Accepted |
| KMP Algorithm | O(n + m) | O(m) | ✅ Accepted |

**Why O(n * m)?**
- In worst case, check each position

**Why O(1) space?**
- No extra space needed

---

## 🔥 All Accepted Solutions

| File Name | Language | Runtime | Memory |
|----------|---------|---------|--------|
| 2026-02-12 05.58.36 - Accepted | JavaScript | 0ms 🟢 | 53.7MB |
| 2026-02-12 05.59.08 - Accepted | **JavaScript** | **0ms 🟢** | **54.1MB** |

---

## 🎓 Key Takeaways

### ✅ Best Practices
1. **Use sliding window** for simple implementation
2. **Early return** on match
3. **Handle edge cases** (empty strings)

### ❌ Common Mistakes
1. Not checking bounds properly
2. Not handling when needle is longer than haystack
3. Not using proper loop bounds

### 💡 Follow-up Questions
- How to implement KMP algorithm?
- How to find all occurrences?

---

## 🔗 Related Problems

| # | Problem | Difficulty | Status |
|---|---------|-----------|--------|
| 459 | Repeated Substring Pattern | Easy | 📝 |
| 214 | Shortest Palindrome | Hard | 📝 |

---

## 📈 Success Metrics

![JavaScript](https://img.shields.io/badge/JavaScript-F7DF1E?style=flat&logo=javascript&logoColor=black)

**Total Submissions:** 2️⃣ **Accepted:** 2️⃣ **Acceptance Rate:** 100% ✅

---

*Made with ❤️ | Last Updated: 2026-04-13*
