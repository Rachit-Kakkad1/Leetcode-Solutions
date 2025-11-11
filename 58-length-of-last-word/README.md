# 🚀 LeetCode 58: Length of Last Word

![Difficulty: Easy](https://img.shields.io/badge/Difficulty-Easy-brightgreen)
![String](https://img.shields.io/badge/Topic-String-blue)
![Status: ✅ Solved](https://img.shields.io/badge/Status-Solved-brightgreen)

## 📋 Problem Statement

Given a string `s` consisting of words and spaces, return the length of the **last word** in the string.

A **word** is defined as a maximal substring consisting of non-space characters.

---

## 📌 Quick Summary

| | |
|---|---|
| **Problem #** | 58 |
| **Difficulty** | Easy |
| **Topics** | String |
| **Companies** | Google |
| **Similar Problems** | [Length of Last Word II](./) |

---

## 🎯 Example Test Cases

### ✅ Example 1:
```
Input: s = "Hello World"
Output: 5
Explanation: The last word is "World" with length 5.
```

### ✅ Example 2:
```
Input: s = "   fly me   to   the moon  "
Output: 4
Explanation: The last word is "moon" with length 4.
```

### ✅ Example 3:
```
Input: s = "single"
Output: 6
```

---

## ⚠️ Constraints

- 1 ≤ s.length ≤ 10⁴
- s consists of letters and spaces
- At least one word in s

---

## 💡 Solution Approaches

### 🔹 Approach 1: Single Pass from End (Optimal) ✅ RECOMMENDED

**Intuition:** Traverse from the end, skip trailing spaces, then count characters.

| | |
|---|---|
| **Time** | O(n) |
| **Space** | O(1) |
| **Runtime** | 3ms ✅ |

**Step-by-Step:**
1. Start from the end of the string
2. Skip all trailing spaces
3. Count characters until next space or start of string

**Why it works:**
- Single pass from the end
- No extra data structures

---

### 🔹 Approach 2: Split by Space (Alternative)

Use split() method.

| | |
|---|---|
| **Time** | O(n) |
| **Space** | O(n) for split result |

---

## 📝 Detailed Implementation

### Python ⭐
```python
def lengthOfLastWord(s):
    length = 0
    i = len(s) - 1
    
    while s[i] == ' ':
        i -= 1
    
    while i >= 0 and s[i] != ' ':
        length += 1
        i -= 1
    
    return length
```

**Key Points:**
- Handles trailing spaces
- Single pass from end
- Runtime: 3ms, Memory: 12.6MB

---

## 🎯 Complexity Analysis

| Approach | Time | Space | Status |
|----------|------|-------|--------|
| **Single Pass from End** | **O(n)** | **O(1)** | ✅ Accepted |
| Split by Space | O(n) | O(n) | ✅ Accepted |

**Why O(n)?**
- In worst case, traverse entire string

**Why O(1) space?**
- Only uses counter variable

---

## 🔥 All Accepted Solutions

| File Name | Language | Runtime | Memory |
|----------|---------|---------|--------|
| 2025-11-11 18.30.30 - Accepted - runtime 3ms - memory 12.6MB.py | **Python** 🐍 | **3ms 🟢** | **12.6MB** |

---

## 🎓 Key Takeaways

### ✅ Best Practices
1. **Traverse from end** for simplicity
2. **Handle trailing spaces** correctly
3. **Edge case:** single word

### ❌ Common Mistakes
1. Not handling trailing spaces
2. Not handling leading spaces
3. Counting spaces as part of word

### 💡 Follow-up Questions
- How to handle multiple delimiters?
- How to handle punctuation?

---

## 📈 Success Metrics

![Python](https://img.shields.io/badge/Python-3776AB?style=flat&logo=python&logoColor=white)

**Total Submissions:** 1️⃣ **Accepted:** 1️⃣ **Acceptance Rate:** 100% ✅

---

*Made with ❤️ | Last Updated: 2026-04-13*