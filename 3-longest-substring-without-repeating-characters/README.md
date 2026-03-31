# 🚀 LeetCode 3: Longest Substring Without Repeating Characters

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-yellow)
![Topic: Hash Table](https://img.shields.io/badge/Topic-Hash_Table-blue)
![String](https://img.shields.io/badge/Topic-String-blue)
![Sliding Window](https://img.shields.io/badge/Topic-Sliding_Window-blue)
![Status: ✅ Solved](https://img.shields.io/badge/Status-Solved-brightgreen)

## 📋 Problem Statement

Given a string `s`, find the length of the **longest substring** without duplicate characters.

---

## 📌 Quick Summary

| | |
|---|---|
| **Problem #** | 3 |
| **Difficulty** | Medium |
| **Topics** | Hash Table, String, Sliding Window |
| **Companies** | Amazon, Google, Goldman Sachs |
| **Similar Problems** | [Longest Repeating Character](./424-longest-repeating-character), [Minimum Window Substring](./76-minimum-window-substring) |

---

## 🎯 Example Test Cases

### ✅ Example 1:
```
Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
```

### ✅ Example 2:
```
Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
```

### ✅ Example 3:
```
Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3. Notice that "pwke" is a substring and not a subsequence.
```

---

## ⚠️ Constraints

- 0 ≤ s.length ≤ 5 × 10⁴
- s consists of English letters, digits, symbols and spaces

---

## 💡 Solution Approaches

### 🔹 Approach 1: Sliding Window with Hash Set (Optimal) ✅ RECOMMENDED

**Intuition:** Use two pointers to maintain a window without duplicates. When a duplicate is found, slide the left pointer.

| | |
|---|---|
| **Time** | O(n) |
| **Space** | O(min(m, n)) |
| **Runtime** | 15ms ✅ |

**Step-by-Step:**
1. Use two pointers: left and right
2. Use a hash set to track characters in current window
3. Expand right pointer, add character to set
4. If duplicate found, shrink left pointer until no duplicate
5. Track maximum length

**Why it works:**
- Each character is processed at most twice (enter + exit)
- O(n) time complexity achieved

---

### 🔹 Approach 2: Sliding Window with Hash Map (Alternative)

Use hash map to store last seen index. Jump left pointer directly to max of current left or last seen index + 1.

| | |
|---|---|
| **Time** | O(n) |
| **Space** | O(min(m, n)) |

---

### 🔹 Approach 3: Brute Force (NOT RECOMMENDED)

Check all substrings for duplicates.

| | |
|---|---|
| **Time** | O(n³) ❌ |
| **Space** | O(min(n, m)) |

---

## 📝 Detailed Implementation

### C++ ⭐
```cpp
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> st;
        int left = 0, maxLen = 0;

        for (int right = 0; right < s.length(); right++) {
            while (st.count(s[right])) {
                st.erase(s[left]);
                left++;
            }
            st.insert(s[right]);
            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};
```

**Key Points:**
- Uses unordered_set for O(1) lookup
- Sliding window technique
- Memory: 14.3MB, Runtime: 15ms

---

## 🎯 Complexity Analysis

| Approach | Time | Space | Status |
|----------|------|-------|--------|
| **Sliding Window + Set** | **O(n)** | **O(min(m,n))** | ✅ Accepted |
| Sliding Window + Map | O(n) | O(min(m,n)) | ✅ Accepted |
| Brute Force | O(n³) | O(min(n,m)) | ❌ TLE |

**Why O(n)?**
- Each character enters and leaves the set once
- At most 2n operations

**Why O(min(m,n)) space?**
- Set size bounded by character set size
- m = size of character set

---

## 🔥 All Accepted Solutions

| File Name | Language | Runtime | Memory |
|----------|---------|---------|--------|
| 2026-03-31 13.26.59 - Accepted - runtime 15ms - memory 14.3MB.cpp | **C++** | **15ms 🟡** | **14.3MB** |

---

## 🎓 Key Takeaways

### ✅ Best Practices
1. **Use sliding window** for O(n) solution
2. **Hash set/map** for O(1) lookups
3. **Track maximum** during iteration

### ❌ Common Mistakes
1. Not shrinking window when duplicate found
2. Using nested loops (causes TLE)
3. Not handling empty string

### 💡 Follow-up Questions
- What if you need to return the substring?
- How to handle Unicode characters?

---

## 🔗 Related Problems

| # | Problem | Difficulty | Status |
|---|---------|-----------|--------|
| 424 | Longest Repeating Character | Medium | 📝 |
| 76 | Minimum Window Substring | Hard | 📝 |
| 159 | Longest Substring with At Most Two Distinct | Medium | 📝 |

---

## 📈 Success Metrics

![C++](https://img.shields.io/badge/C++-00599C?style=flat&logo=c%2B%2B&logoColor=white)

**Total Submissions:** 1️⃣ **Accepted:** 1️⃣ **Acceptance Rate:** 100% ✅

---

*Made with ❤️ | Last Updated: 2026-04-13*