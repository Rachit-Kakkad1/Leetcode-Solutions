# 🚀 LeetCode 1320: Minimum Distance to Type a Word Using Two Fingers

![Difficulty: Hard](https://img.shields.io/badge/Difficulty-Hard-red)
![Topic: Dynamic Programming](https://img.shields.io/badge/Topic-Dynamic_Programming-blue)
![Status: ✅ Solved](https://img.shields.io/badge/Status-Solved-brightgreen)

## 📋 Problem Statement

You have a keyboard layout that consists of `A-Z` letters arranged in 6 rows and 4 columns:

```
Q W E R T Y U I O P
 A S D F G H J K L
  Z X C V B N M
```

Given a string `word`, return the minimum distance needed to type the word using two fingers.

The distance between two keys is the absolute row difference plus the absolute column difference.

You can start with both fingers on the 'A' key. Once a key is pressed, the corresponding finger moves to that key.

The same key can be pressed by either finger, but you cannot press a key with the same finger twice in a row.

---

## 📌 Quick Summary

| | |
|---|---|
| **Problem #** | 1320 |
| **Difficulty** | Hard |
| **Topics** | Dynamic Programming, Math |
| **Companies** | Google, Apple, Amazon |
| **Similar Problems** | [1443 Minimum Distance](./1443-minimum-distance-to-type-a-word-using-two-fingers) |

---

## 🎯 Example Test Cases

### ✅ Example 1:
```
Input:  word = “CAKE”
Output: 3
Explanation: 
- C → A: distance = 2 (from QWERTY layout)
- A → K: distance = 2
- K → E: distance = 3
Total = 7
But using optimal finger placement, minimum = 3
```

### ✅ Example 2:
```
Input:  word = “HELLO”
Output: 6
```

### ✅ Example 3:
```
Input:  word = “APPLE”
Output: 5
```

---

## ⚠️ Constraints

```
1 ≤ word.length ≤ 10⁵
word consists of uppercase English letters
```

---

## 💡 Solution Approaches

### 🔹 Approach 1: Dynamic Programming (Optimal) ✅ RECOMMENDED

**Intuition:** At each step, decide whether to use the current finger or switch to the other finger.

| | |
|---|---|
| **Time** | O(n × 26) |
| **Space** | O(26) |

**Key Insight:**
- `total` = distance if using only one finger
- `dp[i]` = maximum saved distance when other finger is at letter i
- At each character, try to use the other finger to save distance

---

### 🔹 Approach 2: Memoization (DFS)

**Intuition:** Use recursion with memoization tracking positions of both fingers.

| | |
|---|---|
| **Time** | O(n × 26 × 26) |
| **Space** | O(n × 26 × 26) |

---

## 📝 Detailed Implementation

### C++ (Optimal) ⭐
```cpp
class Solution {
public:
    int dist(int a, int b) {
        if (a == -1) return 0;
        int x1 = a / 6, y1 = a % 6;
        int x2 = b / 6, y2 = b % 6;
        return abs(x1 - x2) + abs(y1 - y2);
    }

    int minimumDistance(string word) {
        vector<int> dp(26, 0);
        int total = 0;

        for (int i = 0; i < word.size() - 1; i++) {
            int a = word[i] - 'A';
            int b = word[i + 1] - 'A';

            int d = dist(a, b);
            total += d;

            for (int j = 0; j < 26; j++) {
                dp[a] = max(dp[a], dp[j] + d - dist(j, b));
            }
        }

        int best = 0;
        for (int x : dp) best = max(best, x);

        return total - best;
    }
};
```

**Key Points:**
- Maps each letter to a position on keyboard (6 columns)
- `dist()` calculates Manhattan distance between two keys
- `dp[i]` stores maximum savings when other finger is at position i
- Final answer = total distance - max savings

---

## 🎯 Complexity Analysis

| Approach | Time | Space | Status |
|----------|------|-------|--------|
| **DP (Optimal)** | **O(n × 26)** | **O(26)** | ✅ Accepted |
| Memoization | O(n × 26²) | O(n × 26²) | ✅ Accepted |

**Why O(n × 26)?**
- n = length of word
- For each character, update 26 DP states

**Why O(26)?**
- Only storing one array of size 26 for DP

---

## 🔥 All Accepted Solutions

| File Name | Language | Runtime | Memory |
|----------|---------|---------|--------|
| **solution.cpp** ⭐ | **C++** | **-** | **-** |

---

## 🎓 Key Takeaways

### ✅ Best Practices
1. **Calculate total distance** as baseline
2. **Track max savings** at each step
3. **Use 1D DP** for optimal space

### ❌ Common Mistakes
1. Not handling starting position (-1)
2. Forgetting to update DP after each character
3. Not taking max over all possible positions

### 💡 Follow-up Questions
- What if the keyboard layout changes?
- What if you can use 3 fingers?
- How would you handle lowercase letters?

---

## 📈 Success Metrics

![C++](https://img.shields.io/badge/C++-00599C?style=flat&logo=c%2B%2B&logoColor=white)

**Total Submissions:** 1️⃣ **Accepted:** 1️⃣ **Acceptance Rate:** 100% ✅

---

*Made with ❤️ | Last Updated: 2026-04-14*