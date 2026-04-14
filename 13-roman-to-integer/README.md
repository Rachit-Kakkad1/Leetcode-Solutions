# 🚀 LeetCode 13: Roman to Integer

![Difficulty: Easy](https://img.shields.io/badge/Difficulty-Easy-brightgreen)
![Topic: Hash Table](https://img.shields.io/badge/Topic-Hash_Table-blue)
![String](https://img.shields.io/badge/Topic-String-blue)
![Status: ✅ Solved](https://img.shields.io/badge/Status-Solved-brightgreen)

## 📋 Problem Statement

Roman numerals are represented by seven different symbols: `I`, `V`, `X`, `L`, `C`, `D` and `M`.

```
Symbol       Value
I            1
V            5
X            10
L            50
C            100
D            500
M            1000
```

For example, `2` is written as `II` in Roman numeral, just two ones added together. `12` is written as `XII`, which is simply `X + II`. The Roman numeral for `27` is `XXVII`, which is `XX + V + II`.

Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not `IIII`. Instead, four is written as `IV` because the one (`I`) is subtracted from the five (`V`), making the result four. The same principle applies to the number nine, which is written as `IX`. There are six instances where subtraction is used:

- `IV` = 4
- `IX` = 9
- `XL` = 40
- `XC` = 90
- `CD` = 400
- `CM` = 1000

Given a roman numeral, convert it to an integer.

---

## 📌 Quick Summary

| | |
|---|---|
| **Problem #** | 13 |
| **Difficulty** | Easy |
| **Topics** | Hash Table, String |
| **Companies** | Amazon, Google, Microsoft, Uber |
| **Similar Problems** | [Integer to Roman](./12-integer-to-roman) |

---

## 🎯 Example Test Cases

### ✅ Example 1:
```
Input:  s = "III"
Output: 3
Explanation: III = 3.
```

### ✅ Example 2:
```
Input:  s = "LVIII"
Output: 58
Explanation: LVIII = 58.
```

### ✅ Example 3:
```
Input:  s = "MCMXCIV"
Output: 1994
Explanation: M = 1000, CM = 900, XC = 90, IV = 4.
```

---

## 💡 Solution Approaches

### 🔹 Approach 1: Hash Table Lookup (Optimal) ✅ RECOMMENDED

**Intuition:** Use a hash table to store symbol values, then iterate through the string once.

| | |
|---|---|
| **Time** | O(n) |
| **Space** | O(1) |

**Step-by-Step:**
1. Create a hash map of Roman symbols to their values
2. Iterate through each character
3. If current value is less than next value, subtract current (subtract rule)
4. Otherwise, add current value to result

---

### 🔹 Approach 2: Direct Comparison

**Intuition:** Compare adjacent characters to handle subtraction cases.

| | |
|---|---|
| **Time** | O(n) |
| **Space** | O(1) |

---

## 📝 Detailed Implementation

### C++ (Best Performance) ⭐
```cpp
class Solution {
public:
    int getValue(char ch) {
        if (ch == 'I') return 1;
        if (ch == 'V') return 5;
        if (ch == 'X') return 10;
        if (ch == 'L') return 50;
        if (ch == 'C') return 100;
        if (ch == 'D') return 500;
        return 1000;
    };

    int romanToInt(string s) {
        int result = 0;

        for (int i = 0; i < s.length(); i++) {
            int curr = getValue(s[i]);
            int next = (i + 1 < s.length()) ? getValue(s[i + 1]) : 0;

            if (curr < next) {
                result -= curr;
            } else {
                result += curr;
            }
        }

        return result;
    }
};
```

**Key Points:**
- Handles subtraction rule by checking next character
- Single pass through string
- Time: O(n), Space: O(1)

---

### Python 3 ⭐
```python
class Solution:
    def romanToInt(self, s: str) -> int:
        values = {
            'I': 1, 'V': 5, 'X': 10,
            'L': 50, 'C': 100, 'D': 500, 'M': 1000
        }
        
        result = 0
        prev = 0
        
        for ch in reversed(s):
            curr = values[ch]
            if curr < prev:
                result -= curr
            else:
                result += curr
            prev = curr
        
        return result
```

---

### JavaScript ⭐
```javascript
class Solution {
    romanToInt(s) {
        const map = {
            'I': 1, 'V': 5, 'X': 10,
            'L': 50, 'C': 100, 'D': 500, 'M': 1000
        };

        let result = 0;
        let prev = 0;

        for (let i = s.length - 1; i >= 0; i--) {
            const curr = map[s[i]];
            if (curr < prev) {
                result -= curr;
            } else {
                result += curr;
            }
            prev = curr;
        }

        return result;
    }
}
```

---

## 🎯 Complexity Analysis

| Approach | Time | Space | Status |
|----------|------|-------|--------|
| **Hash Table** | **O(n)** | **O(1)** | ✅ Accepted |
| Direct Comparison | O(n) | O(1) | ✅ Accepted |

**Why O(n)?**
- n = length of string
- Single pass through all characters

**Why O(1)?**
- Hash map stores only 7 entries (constant)
- No additional data structures

---

## 🔥 All Accepted Solutions

| File Name | Language | Runtime | Memory |
|----------|---------|---------|--------|
| **solution.cpp** ⭐ | **C++** | **-** | **-** |

---

## 🎓 Key Takeaways

### ✅ Best Practices
1. **Check next character** to handle subtraction rule
2. **Single pass** is optimal for this problem
3. **Use hash map** for fast symbol lookup

### ❌ Common Mistakes
1. Not handling subtraction cases (IV, IX, XL, etc.)
2. Adding all values without checking next character
3. Missing edge case for last character

### 💡 Follow-up Questions
- What if input is not a valid Roman numeral?
- How would you implement integer to Roman?
- What if you need to handle larger numbers?

---

## 🔗 Related Problems

| # | Problem | Difficulty | Status |
|---|---------|-----------|--------|
| 12 | Integer to Roman | Medium | 📝 |
| 13 | Roman to Integer | Easy | 📝 |

---

## 📈 Success Metrics

![C++](https://img.shields.io/badge/C++-00599C?style=flat&logo=c%2B%2B&logoColor=white)

**Total Submissions:** 1️⃣ **Accepted:** 1️⃣ **Acceptance Rate:** 100% ✅

---

*Made with ❤️ | Last Updated: 2026-04-14*