# 🚀 LeetCode 14: Longest Common Prefix

![Difficulty: Easy](https://img.shields.io/badge/Difficulty-Easy-brightgreen)
![Topic: String](https://img.shields.io/badge/Topic-String-blue)
![Status: ✅ Solved](https://img.shields.io/badge/Status-Solved-brightgreen)

## 📋 Problem Statement

Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string `""`.

---

## 📌 Quick Summary

| | |
|---|---|
| **Problem #** | 14 |
| **Difficulty** | Easy |
| **Topics** | String, Trie |
| **Companies** | Amazon, Google, Apple, Microsoft |
| **Similar Problems** | [Longest Common Substring](./), [Shortest Distance to a Character](./) |

---

## 🎯 Example Test Cases

### ✅ Example 1:
```
Input:  strs = ["flower","flow","flight"]
Output: "fl"
Explanation: The longest common prefix among all strings is "fl".
```

### ✅ Example 2:
```
Input:  strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among all input strings.
```

---

## ⚠️ Constraints

```
1 ≤ strs.length ≤ 100
0 ≤ strs[i].length ≤ 200
strs[i] consists of only lowercase English letters
All strings are non-empty if strs.length > 0
```

---

## 💡 Solution Approaches

### 🔹 Approach 1: Horizontal Scanning (Optimal) ✅ RECOMMENDED

**Intuition:** Compare characters at each position for all strings sequentially.

| | |
|---|---|
| **Time** | O(S) |
| **Space** | O(1) |

**Step-by-Step:**
1. Start with the first string as the prefix
2. For each subsequent string, find the longest common prefix with current prefix
3. Keep shortening the prefix until it matches the start of the current string
4. Return prefix when done or empty if no match

---

### 🔹 Approach 2: Vertical Scanning

**Intuition:** Compare characters column by column for all strings.

| | |
|---|---|
| **Time** | O(S) |
| **Space** | O(1) |

---

### 🔹 Approach 3: Sort and Compare First & Last

**Intuition:** After sorting, only compare first and last strings.

| | |
|---|---|
| **Time** | O(n log n + S) |
| **Space** | O(1) |

---

## 📝 Detailed Implementation

### C++ (Best Performance) ⭐
```cpp
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        
        string px = strs[0];
        for (int i = 1; i < strs.size(); i++) {
            while (strs[i].find(px) != 0) {
                px.pop_back();
                if (px.empty()) return "";
            }
        }
        return px;
    }
};
```

**Key Points:**
- Uses `find()` to check if prefix exists at start
- `pop_back()` removes last character to shorten prefix
- Early return when prefix becomes empty

---

### Python 3 ⭐
```python
class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        if not strs:
            return ""
        
        prefix = strs[0]
        for s in strs[1:]:
            while not s.startswith(prefix):
                prefix = prefix[:-1]
                if not prefix:
                    return ""
        
        return prefix
```

---

### JavaScript ⭐
```javascript
class Solution {
    longestCommonPrefix(strs) {
        if (!strs || strs.length === 0) return "";
        
        let prefix = strs[0];
        
        for (let i = 1; i < strs.length; i++) {
            while (strs[i].indexOf(prefix) !== 0) {
                prefix = prefix.slice(0, -1);
                if (!prefix) return "";
            }
        }
        
        return prefix;
    }
}
```

---

## 🎯 Complexity Analysis

| Approach | Time | Space | Status |
|---------|------|------|--------|
| **Horizontal** | **O(S)** | **O(1)** | ✅ Accepted |
| Vertical | O(S) | O(1) | ✅ Accepted |
| Sort + Compare | O(n log n + S) | O(1) | ✅ Accepted |

**Why O(S)?**
- S = sum of all characters in all strings
- In worst case, we compare each character once

**Why O(1)?**
- Only stores the prefix string
- No additional data structures

---

## 🔥 All Accepted Solutions

| File Name | Language | Runtime | Memory |
|----------|---------|---------|--------|
| **solution.cpp** ⭐ | **C++** | **-** | **-** |

---

## 🎓 Key Takeaways

### ✅ Best Practices
1. **Start with first string** as initial prefix
2. **Shorten progressively** until match found
3. **Handle empty case** early

### ❌ Common Mistakes
1. Not checking for empty input
2. Using `==` instead of `.starts_with()`
3. Forgetting to return empty string when no prefix

### 💡 Follow-up Questions
- What if strings can be empty?
- What if you need to find longest common suffix?
- How would you optimize for multiple queries?

---

## 🔗 Related Problems

| # | Problem | Difficulty | Status |
|---|---------|-----------|--------|
| 14 | Longest Common Prefix | Easy | 📝 |
| 58 | Length of Last Word | Easy | 📝 |
| 28 | Find the Index | Easy | 📝 |

---

## 📈 Success Metrics

![C++](https://img.shields.io/badge/C++-00599C?style=flat&logo=c%2B%2B&logoColor=white)

**Total Submissions:** 1️⃣ **Accepted:** 1️⃣ **Acceptance Rate:** 100% ✅

---

*Made with ❤️ | Last Updated: 2026-04-14*