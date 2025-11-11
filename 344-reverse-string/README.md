# 🚀 LeetCode 344: Reverse String

![Difficulty: Easy](https://img.shields.io/badge/Difficulty-Easy-brightgreen)
![Topic: String](https://img.shields.io/badge/Topic-String-blue)
![Two Pointers](https://img.shields.io/badge/Topic-Two_Pointers-blue)
![Recursion](https://img.shields.io/badge/Topic-Recursion-blue)
![Status: ✅ Solved](https://img.shields.io/badge/Status-Solved-brightgreen)

## 📋 Problem Statement

Write a function that reverses a string. The input string is given as an array of characters `s`.

You must do this by modifying the input array **in-place** with `O(1)` extra memory.

---

## 📌 Quick Summary

| | |
|---|---|
| **Problem #** | 344 |
| **Difficulty** | Easy |
| **Topics** | String, Two Pointers, Recursion |
| **Companies** | Amazon, Apple, Microsoft |
| **Similar Problems** | [Reverse String II](./541-reverse-string-ii) |

---

## 🎯 Example Test Cases

### ✅ Example 1:
```
Input: s = ["h","e","l","l","o"]
Output: ["o","l","l","e","h"]
```

### ✅ Example 2:
```
Input: s = ["H","a","n","n","a","h"]
Output: ["h","a","n","n","a","H"]
```

---

## ⚠️ Constraints

```
1 ≤ s.length ≤ 10^5
s[i] is a printable ASCII character
```

---

## 💡 Solution Approaches

### 🔹 Approach 1: Two Pointers (Optimal) ✅ RECOMMENDED

**Intuition:** Use two pointers from both ends and swap characters.

| | |
|---|---|
| **Time** | O(n) |
| **Space** | O(1) |
| **Runtime** | 0ms ✅ |

**Step-by-Step:**
1. Initialize `i = 0` and `j = s.size() - 1`
2. While `i < j`:
   - Swap `s[i]` and `s[j]`
   - Increment `i`
   - Decrement `j`
3. The array is now reversed in-place

**Why it works:**
- Each swap fixes two positions (first and last)
- Only traverse half the array

---

## 📝 Detailed Implementation

### C++ ⭐
```cpp
class Solution {
public:
    void reverseString(vector<char>& s) {
        int i = 0;
        int j = s.size() - 1;

        while (i < j) {
            swap(s[i], s[j]);
            i++;
            j--;
        }
    }
};
```

**Key Points:**
- Two-pointer technique
- In-place reversal
- Runtime: 0ms, Memory: 27.3MB

---

## 🎯 Complexity Analysis

| Approach | Time | Space | Status |
|----------|------|-------|--------|
| **Two Pointers** | **O(n)** | **O(1)** | ✅ Accepted |
| Recursive | O(n) | O(n) | ✅ Accepted |

**Why O(n)?**
- Each element is visited at most once (half traversal)

**Why O(1) space?**
- Only two pointer variables used

---

## 🔥 All Accepted Solutions

| File Name | Language | Runtime | Memory |
|----------|---------|---------|--------|
| 2025-11-11 18.43.14 - Accepted | C | 0ms 🟢 | 17.1MB |
| 2025-11-11 18.44.38 - Accepted | JavaScript | 1ms 🟢 | 60.8MB |
| 2025-11-11 18.45.27 - Accepted | JavaScript | 0ms 🟢 | 61.4MB |
| 2025-11-11 18.46.08 - Accepted | Python 🐍 | 4ms 🟢 | 19.8MB |
| 2025-11-11 18.46.37 - Accepted | Python 🐍 | 0ms 🟢 | 20MB |
| 2026-04-09 11.06.35 - Accepted | **C++** | **0ms 🟢** | **27.3MB** |

---

## 🎓 Key Takeaways

### ✅ Best Practices
1. **Use two pointers** from both ends
2. **In-place** modification
3. **O(1) space** required

### ❌ Common Mistakes
1. Using extra space (not allowed)
2. Not swapping correctly
3. Using wrong loop condition

### 💡 Follow-up Questions
- How to reverse in recursion?
- How to handle k-distance reversal?

---

## 🔗 Related Problems

| # | Problem | Difficulty | Status |
|---|---------|-----------|--------|
| 541 | Reverse String II | Easy | 📝 |
| 345 | Reverse Vowels of a String | Easy | 📝 |
| 167 | Two Sum II | Easy | 📝 |

---

## 📈 Success Metrics

![C](https://img.shields.io/badge/C-A8B9CC?style=flat&logo=c&logoColor=white)
![JavaScript](https://img.shields.io/badge/JavaScript-F7DF1E?style=flat&logo=javascript&logoColor=black)
![Python](https://img.shields.io/badge/Python-3776AB?style=flat&logo=python&logoColor=white)
![C++](https://img.shields.io/badge/C++-00599C?style=flat&logo=c%2B%2B&logoColor=white)

**Total Submissions:** 6️⃣ **Accepted:** 5️⃣ **Acceptance Rate:** 83% ✅

---

*Made with ❤️ | Last Updated: 2026-04-13*
