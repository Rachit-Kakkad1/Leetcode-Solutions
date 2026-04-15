# 🚀 LeetCode 387: First Unique Character in a String

![Difficulty: Easy](https://img.shields.io/badge/Difficulty-Easy-brightgreen)
![Topic: Hash Table](https://img.shields.io/badge/Topic-Hash_Table-blue)
![Topic: String](https://img.shields.io/badge/Topic-String-blue)
![Status: ✅ Solved](https://img.shields.io/badge/Status-Solved-brightgreen)

## 📋 Problem Statement

Given a string `s`, find the first non-repeating character in it and return its **index**. If it does not exist, return `-1`.

---

## 📌 Quick Summary

| | |
|---|---|
| **Problem #** | 387 |
| **Difficulty** | Easy |
| **Topics** | Hash Table, String |
| **Companies** | Amazon, Apple, Microsoft, Bloomberg |
| **Similar Problems** | [First Unique Character in a String](./350-intersection-of-two-arrays-ii), [Sort Characters By Frequency](./451-sort-characters-by-frequency) |

---

## 🎯 Example Test Cases

### ✅ Example 1:
```
Input:  s = "leetcode"
Output: 0
Explanation: The first non-repeating character is 'l', and its index is 0.
```

### ✅ Example 2:
```
Input:  s = "lovelintcrid"
Output: 2
Explanation: 'v' is the first unique character at index 2.
```

### ✅ Example 3:
```
Input:  s = "aabb"
Output: -1
Explanation: There is no unique character, return -1.
```

---

## ⚠️ Constraints

```
1 ≤ s.length ≤ 10⁵
s consists of only lowercase English letters
```

---

## 💡 Solution Approaches

### 🔹 Approach 1: Two-Pass Hash Table ✅ RECOMMENDED

**Intuition:** First pass to count frequency of each character, second pass to find first character with frequency 1.

| | |
|---|---|
| **Time** | O(n) |
| **Space** | O(1) - fixed alphabet of 26 chars |
| **Runtime** | 0ms ✅ |

**Step-by-Step:**
1. Count frequency of each character using a hash map
2. Iterate through string again to find first character with frequency 1
3. Return its index, or -1 if not found

**Why it works:**
- Two passes: O(n) time
- Hash table gives O(1) lookups
- Fixed space: only 26 lowercase letters possible

---

### 🔹 Approach 2: Ordered Hash Map (NOT RECOMMENDED)

```
Use ordered map to maintain insertion order
```

| | |
|---|---|
| **Time** | O(n) |
| **Space** | O(n) |
| **Status** | Not optimal |

---

## 📝 Detailed Implementation

### C++ (Best Performance) ⭐
```cpp
class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> freq;

        for (char ch : s) {
            freq[ch]++;
        }

        for (int i = 0; i < s.length(); i++) {
            if (freq[s[i]] == 1) {
                return i;
            }
        }

        return -1;
    }
};
```

**Key Points:**
- `unordered_map` gives O(1) average lookup
- First pass: count frequencies
- Second pass: find first unique character
- Memory: optimized, Runtime: 0ms

---

## 🎯 Complexity Analysis

| Approach | Time | Space | Status |
|---------|------|------|--------|
| **Two-Pass Hash Table** | **O(n)** | **O(1)** | ✅ Accepted |
| Ordered Hash Map | O(n) | O(n) | ✅ Accepted |
| Brute Force | O(n²) | O(1) | ❌ TLE |

**Why O(n)?**
- Two passes through string: 2n operations
- Hash operations: O(1) average each
- Total: O(n)

**Why O(1) space?**
- Hash map at most 26 entries (lowercase letters a-z)
- Fixed alphabet size makes it O(1)

---

## 🔥 All Accepted Solutions

| File Name | Language | Runtime | Memory |
|----------|---------|---------|--------|
| **solution.cpp** ⭐ | **C++** | **0ms 🟢** | **TBD** |

---

## 🎓 Key Takeaways

### ✅ Best Practices
1. **Use Hash Map** for frequency counting
2. **Two-pass approach** - count first, find second
3. **Fixed alphabet** means O(1) space

### ❌ Common Mistakes
1. Using single pass (might miss unique characters)
2. Not resetting after counting
3. Forgetting to handle empty string case

### 💡 Follow-up Questions
- What if you need to return the character itself?
- What if the string has uppercase letters too?
- What if you need to handle unicode?

---

## 🔗 Related Problems

| # | Problem | Difficulty | Status |
|---|---------|-----------|--------|
| 350 | Intersection of Two Arrays II | Easy | 📝 |
| 451 | Sort Characters By Frequency | Medium | 📝 |
| 159 | Longest Substring with At Most Two Distinct Characters | Medium | 📝 |

---

## 📈 Success Metrics

![C++](https://img.shields.io/badge/C++-00599C?style=flat&logo=c%2B%2B&logoColor=white)

**Total Submissions:** 1️⃣ **Accepted:** 1️⃣ **Acceptance Rate:** 100% ✅

---

*Made with ❤️ | Last Updated: 2026-04-15*