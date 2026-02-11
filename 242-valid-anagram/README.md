# 🚀 LeetCode 242: Valid Anagram

![Difficulty: Easy](https://img.shields.io/badge/Difficulty-Easy-brightgreen)
![Topic: Hash Table](https://img.shields.io/badge/Topic-Hash_Table-blue)
![String](https://img.shields.io/badge/Topic-String-blue)
![Sorting](https://img.shields.io/badge/Topic-Sorting-blue)
![Status: ✅ Solved](https://img.shields.io/badge/Status-Solved-brightgreen)

## 📋 Problem Statement

Given two strings `s` and `t`, return `true` if `t` is an anagram of `s`, and `false` otherwise.

An **anagram** is a word formed by rearranging the letters of another word.

---

## 📌 Quick Summary

| | |
|---|---|
| **Problem #** | 242 |
| **Difficulty** | Easy |
| **Topics** | Hash Table, String, Sorting |
| **Companies** | Amazon, Apple, Google, Microsoft |
| **Similar Problems** | [Group Anagrams](./49-group-anagrams) |

---

## 🎯 Example Test Cases

### ✅ Example 1:
```
Input: s = "anagram", t = "nagaram"
Output: true
Explanation: Both strings contain the same characters with the same frequencies.
```

### ✅ Example 2:
```
Input: s = "rat", t = "car"
Output: false
Explanation: Characters do not match.
```

---

## ⚠️ Constraints

```
1 ≤ s.length, t.length ≤ 5 * 10^4
s and t consist of lowercase English letters
```

---

## 💡 Solution Approaches

### 🔹 Approach 1: Frequency Count (Optimal) ✅ RECOMMENDED

**Intuition:** Count the frequency of each character in both strings and compare.

| | |
|---|---|
| **Time** | O(n) |
| **Space** | O(1) (26 letters fixed) |
| **Runtime** | 5ms ✅ |

**Step-by-Step:**
1. If lengths differ, return false immediately
2. Create an array of size 26 for character counts
3. Increment count for string s, decrement for string t
4. If all counts are zero, return true

**Why it works:**
- Same characters with same frequencies = anagram
- Fixed alphabet size allows O(1) space

---

### 🔹 Approach 2: Sorting (Alternative)

Sort both strings and compare.

| | |
|---|---|
| **Time** | O(n log n) |
| **Space** | O(n) or O(1) |

---

## 📝 Detailed Implementation

### JavaScript ⭐
```javascript
function isAnagram(s, t) {
    if (s.length !== t.length) return false;

    const count = new Array(26).fill(0);
    const base = 'a'.charCodeAt(0);

    for (let i = 0; i < s.length; i++) {
        count[s.charCodeAt(i) - base]++;
        count[t.charCodeAt(i) - base]--;
    }

    return count.every(c => c === 0);
}
```

**Key Points:**
- Frequency count array
- O(n) time, O(1) space
- Runtime: 5ms, Memory: 55.2MB

---

### JavaScript (Alternative - Sorting)
```javascript
function isAnagram(s, t) {
    if (s.length !== t.length) return false;
    return s.split('').sort().join('') === t.split('').sort().join('');
}
```

---

## 🎯 Complexity Analysis

| Approach | Time | Space | Status |
|----------|------|-------|--------|
| **Frequency Count** | **O(n)** | **O(1)** | ✅ Accepted |
| Sorting | O(n log n) | O(n) | ✅ Accepted |

**Why O(n)?**
- Single pass through both strings

**Why O(1) space?**
- Fixed array of 26 elements (constant)

---

## 🔥 All Accepted Solutions

| File Name | Language | Runtime | Memory |
|----------|---------|---------|--------|
| 2026-02-11 10.41.27 - Accepted | JavaScript | 31ms 🟡 | 57.7MB |
| 2026-02-11 10.41.42 - Accepted | JavaScript | 5ms 🟢 | 55.2MB |
| 2026-02-11 10.41.49 - Accepted | JavaScript | 6ms 🟢 | 54.4MB |

---

## 🎓 Key Takeaways

### ✅ Best Practices
1. **Use frequency count** for O(n) solution
2. **Check length first** for early termination
3. **Fixed alphabet** allows O(1) space

### ❌ Common Mistakes
1. Not checking string lengths
2. Using extra space when not needed
3. Not handling Unicode (for extended problems)

### 💡 Follow-up Questions
- How to handle Unicode characters?
- How to find all anagram groups?

---

## 🔗 Related Problems

| # | Problem | Difficulty | Status |
|---|---------|-----------|--------|
| 49 | Group Anagrams | Medium | 📝 |
| 438 | Find All Anagrams in a String | Medium | 📝 |
| 266 | Palindrome Permutation | Easy | 📝 |

---

## 📈 Success Metrics

![JavaScript](https://img.shields.io/badge/JavaScript-F7DF1E?style=flat&logo=javascript&logoColor=black)

**Total Submissions:** 3️⃣ **Accepted:** 3️⃣ **Acceptance Rate:** 100% ✅

---

*Made with ❤️ | Last Updated: 2026-04-13*
