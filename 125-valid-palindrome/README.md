# 🚀 LeetCode 125: Valid Palindrome

![Difficulty: Easy](https://img.shields.io/badge/Difficulty-Easy-brightgreen)
![Topic: Two Pointers](https://img.shields.io/badge/Topic-Two_Pointers-blue)
![String](https://img.shields.io/badge/Topic-String-blue)
![Status: ✅ Solved](https://img.shields.io/badge/Status-Solved-brightgreen)

## 📋 Problem Statement

A phrase is a **palindrome** if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward.

Given a string `s`, return `true` if it is a **palindrome**, or `false` otherwise.

---

## 📌 Quick Summary

| | |
|---|---|
| **Problem #** | 125 |
| **Difficulty** | Easy |
| **Topics** | Two Pointers, String |
| **Companies** | Amazon, Apple, Google, Microsoft |
| **Similar Problems** | [Valid Palindrome Number](./9-palindrome-number) |

---

## 🎯 Example Test Cases

### ✅ Example 1:
```
Input: s = "A man, a plan, a canal: Panama"
Output: true
Explanation: "amanaplanacanalpanama" is a palindrome.
```

### ✅ Example 2:
```
Input: s = "race a car"
Output: false
Explanation: "raceacar" is not a palindrome.
```

### ✅ Example 3:
```
Input: s = " "
Output: true
Explanation: s is an empty string "" after removing non-alphanumeric characters.
```

---

## ⚠️ Constraints

```
1 ≤ s.length ≤ 2 * 10^5
s consists only of printable ASCII characters
```

---

## 💡 Solution Approaches

### 🔹 Approach 1: Two Pointers (Optimal) ✅ RECOMMENDED

**Intuition:** Use two pointers starting from both ends, skip non-alphanumeric characters, and compare characters.

| | |
|---|---|
| **Time** | O(n) |
| **Space** | O(1) |
| **Runtime** | 6ms ✅ |

**Step-by-Step:**
1. Initialize `left = 0`, `right = s.length - 1`
2. While `left < right`:
   - Move `left` forward while it's not alphanumeric
   - Move `right` backward while it's not alphanumeric
   - If `s[left].toLowerCase() !== s[right].toLowerCase()`: return false
   - Increment `left`, decrement `right`
3. Return true if all comparisons pass

**Why it works:**
- Only alphanumeric characters matter (skip others)
- Palindrome property means symmetric comparison from both ends
- Two-pointer approach gives O(n) time with O(1) space

---

## 📝 Detailed Implementation

### JavaScript ⭐
```javascript
var isPalindrome = function(s) {
    let left = 0;
    let right = s.length - 1;

    while (left < right) {
        
        while (left < right && !isAlphaNum(s[left])) left++;
        
        while (left < right && !isAlphaNum(s[right])) right--;

        if (s[left].toLowerCase() !== s[right].toLowerCase()) {
            return false;
        }

        left++;
        right--;
    }

    return true;
};

function isAlphaNum(ch) {
    const code = ch.charCodeAt(0);
    return (
        (code >= 48 && code <= 57) ||   
        (code >= 65 && code <= 90) ||   
        (code >= 97 && code <= 122)     
    );
}
```

**Key Points:**
- Two-pointer technique
- Custom alphanumeric check function
- Runtime: 6ms, Memory: 57.3MB

---

## 🎯 Complexity Analysis

| Approach | Time | Space | Status |
|----------|------|-------|--------|
| **Two Pointers** | **O(n)** | **O(1)** | ✅ Accepted |
| Reverse String | O(n) | O(n) | ✅ Accepted |

**Why O(n)?**
- Single pass through the string (each character visited once)

**Why O(1) space?**
- Only two pointer variables used

---

## 🔥 All Accepted Solutions

| File Name | Language | Runtime | Memory |
|----------|---------|---------|--------|
| 2026-01-31 14.04.42 - Accepted | **JavaScript** | **6ms 🟢** | **57.3MB** |

---

## 🎓 Key Takeaways

### ✅ Best Practices
1. **Use two pointers** from both ends
2. **Handle case insensitivity** with toLowerCase()
3. **Skip non-alphanumeric** characters properly

### ❌ Common Mistakes
1. Not handling special characters
2. Forgetting to convert to lowercase
3. Not skipping non-alphanumeric characters

### 💡 Follow-up Questions
- How to handle Unicode characters?
- How to check for palindrome with limited memory?

---

## 🔗 Related Problems

| # | Problem | Difficulty | Status |
|---|---------|-----------|--------|
| 9 | Palindrome Number | Easy | 📝 |
| 234 | Palindrome Linked List | Easy | 📝 |
| 680 | Valid Palindrome II | Easy | 📝 |

---

## 📈 Success Metrics

![JavaScript](https://img.shields.io/badge/JavaScript-F7DF1E?style=flat&logo=javascript&logoColor=black)

**Total Submissions:** 1️⃣ **Accepted:** 1️⃣ **Acceptance Rate:** 100% ✅

---

*Made with ❤️ | Last Updated: 2026-04-13*
