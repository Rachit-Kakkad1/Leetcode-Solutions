# 🚀 LeetCode 151: Reverse Words in a String

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)
![Topics](https://img.shields.io/badge/Topics-String-blue)
![Topics](https://img.shields.io/badge/Topics-Two%20Pointers-purple)
![Acceptance](https://img.shields.io/badge/Acceptance-52.5%25-yellow)

---

## ⚡ The Problem

Given an input string `s`, reverse the order of the words.

Words are separated by spaces (multiple spaces possible). Handle:
- Leading/trailing spaces
- Multiple spaces between words

Example:
```
Input: "  hello   world  "
Output: "world hello"
```

---

## 💡 The Solution (JavaScript - Elegant)

```javascript
var reverseWords = function(s) {
    return s
        .trim()
        .split(/\s+/)
        .reverse()
        .join(" ");
};
```

### 🔥 Why This Is Beautiful

1. `.trim()` - Remove leading/trailing spaces
2. `.split(/\s+/)` - Split by **one or more** spaces (regex magic!)
3. `.reverse()` - Reverse the array
4. `.join(" ")` - Join with single space

**Time Complexity**: O(n)  
**Space Complexity**: O(n)

---

## 💡 The Solution (C++ - In-Place)

```cpp
class Solution {
public:
    string reverseWords(string s) {
        string an = "";
        int i = s.size() - 1;

        while (i >= 0) {
            while (i >= 0 && s[i] == ' ') i--;

            if (i < 0) break;

            int j = i;
            while (j >= 0 && s[j] != ' ') j--;
            
            if (!an.empty()) an += " ";
            an += s.substr(j + 1, i - j);

            i = j - 1;
        }

        return an;
    }
};
```

### 🔥 C++ Approach

- Traverse from **right to left**
- Skip spaces, find word boundaries
- Append each word with a space in between

**Time Complexity**: O(n)  
**Space Complexity**: O(n)

---

## 🎯 Key Patterns

| Technique | Use Case |
|----------|----------|
| `trim()` | Remove edge spaces |
| `split(/\s+/)` | Handle multiple spaces |
| Two pointers | In-place string manipulation |

---

## 🏆 Stats

| Language | Runtime | Rank |
|---------|---------|------|
| JavaScript | 52ms | Top 95% |
| C++ | 0ms | Top 100% |

---

> *"Words reversed, problems solved."* 🔤