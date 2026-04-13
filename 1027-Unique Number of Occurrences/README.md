# 🚀 LeetCode 1027: Unique Number of Occurrences

![Difficulty: Easy](https://img.shields.io/badge/Difficulty-Easy-brightgreen)
![Topic: Hash Table](https://img.shields.io/badge/Topic-Hash_Table-blue)
![Status: ✅ Solved](https://img.shields.io/badge/Status-Solved-brightgreen)

## 📋 Problem Statement

Given an integer array `arr`, return `true` if the number of occurrences of each value in the array is unique. Return `false` otherwise.

## 📌 Quick Summary

| | |
|---|---|
| **Problem #** | 1027 |
| **Difficulty** | Easy |
| **Topics** | Array, Hash Table |
| **Companies** | Google, Amazon |

## 🎯 Example Test Cases

### ✅ Example 1:
```
Input:  arr = [1, 2, 2, 1, 1, 3]
Output: true
Explanation: Value 1 occurs 3 times, value 2 occurs 2 times, value 3 occurs 1 time. All occurrence counts (3, 2, 1) are unique.
```

### ✅ Example 2:
```
Input:  arr = [0, 0]
Output: false
Explanation: Value 0 occurs 2 times. Only one unique value but it has a count - duplicate counts issue!
```

### ✅ Example 3:
```
Input:  arr = [-1, 1, -1, 0, 0]
Output: false
Explanation: -1 occurs 2 times, 1 occurs 1 time, 0 occurs 2 times. Counts (2, 1, 2) are NOT unique (2 appears twice).
```

## ⚠️ Constraints

```
1 ≤ arr.length ≤ 1000
-1000 ≤ arr[i] ≤ 1000
```

## 💡 Solution Approaches

### 🔹 Approach 1: Hash Map + Set ✅ RECOMMENDED

**Intuition:** Count occurrences of each value, then check if all counts are unique using a set.

| | |
|---|---|
| **Time** | O(n) |
| **Space** | O(n) |

**Step-by-Step:**
1. Count occurrences of each value using hash map
2. Extract all counts into a set
3. If set size equals map size → all counts unique → return true
4. Otherwise return false

### 🔹 Approach 2: Sorting (Alternative)

| | |
|---|---|
| **Time** | O(n log n) |
| **Space** | O(1) |

---

## 📝 Detailed Implementation

### C++ ⭐ (Your Solution)
```cpp
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> count;
        
        // Count occurrences
        for (int num : arr) {
            count[num]++;
        }
        
        // Check uniqueness using set
        unordered_set<int> occ;
        for (auto& [num, c] : count) {
            if (occ.count(c)) return false;  // duplicate count found
            occ.insert(c);
        }
        
        return true;
    }
};
```

### Python ⭐
```python
from collections import Counter

class Solution:
    def uniqueOccurrences(self, arr: list[int]) -> bool:
        counts = Counter(arr)
        return len(counts.values()) == len(set(counts.values()))
```

---

## 🎯 Complexity Analysis

| Approach | Time | Space | Status |
|----------|------|------|--------|
| **Hash Map + Set** | **O(n)** | **O(n)** | ✅ Accepted |
| Sorting | O(n log n) | O(1) | ✅ |

---

## 🔥 All Accepted Solutions

| File Name | Language | Runtime | Memory |
|----------|---------|---------|--------|
| solution.cpp | C++ | - | - |

---

## 🎓 Key Takeaways

### ✅ Best Practices
1. Use Hash Map to count occurrences - O(n)
2. Use Set to check uniqueness - O(n)
3. Compare set size with map size

### ❌ Common Mistakes
1. Forgetting to check if counts themselves are unique
2. Not handling negative numbers in array

---

## 🔗 Related Problems

| # | Problem | Difficulty |
|---|---------|-----------|
| 217 | Contains Duplicate | Easy |
| 1207 | Unique Number of Occurrences | Easy |

---

*Made with ❤️ | Last Updated: 2026-04-13*