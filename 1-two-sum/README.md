# 🚀 LeetCode 1: Two Sum

![Difficulty: Easy](https://img.shields.io/badge/Difficulty-Easy-brightgreen)
![Topic: Hash Table](https://img.shields.io/badge/Topic-Hash_Table-blue)
![Status: ✅ Solved](https://img.shields.io/badge/Status-Solved-brightgreen)

## 📋 Problem Statement

Given an array of integers `nums` and an integer `target`, return **indices of the two numbers** such that they add up to `target`.

You may assume that each input would have **exactly one solution**, and you may not use the **same element twice**.

You can return the answer in any order.

---

## 📌 Quick Summary

| | |
|---|---|
| **Problem #** | 1 |
| **Difficulty** | Easy |
| **Topics** | Array, Hash Table |
| **Companies** | Amazon, Apple, Google, Microsoft |
| **Similar Problems** | [Two Sum II](./167-two-sum-ii-input-array-is-sorted), [3Sum](./15-3sum), [4Sum](./18-4sum) |

---

## 🎯 Example Test Cases

### ✅ Example 1:
```
Input:  nums = [2, 7, 11, 15], target = 9
Output: [0, 1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
```

### ✅ Example 2:
```
Input:  nums = [3, 2, 4], target = 6
Output: [1, 2]
```

### ✅ Example 3:
```
Input:  nums = [3, 3], target = 6
Output: [0, 1]
```

---

## ⚠️ Constraints

```
2 ≤ nums.length ≤ 10⁴
-10⁹ ≤ nums[i] ≤ 10⁹
-10⁹ ≤ target ≤ 10⁹
Only ONE valid answer exists (guaranteed)
```

---

## 💡 Solution Approaches

### 🔹 Approach 1: Hash Table (Optimal) ✅ RECOMMENDED

**Intuition:** For each element, check if `target - current_element` exists in a hash table.

| | |
|---|---|
| **Time** | O(n) |
| **Space** | O(n) |
| **Runtime** | 0ms ✅ |

**Step-by-Step:**
1. Create an empty hash map to store `{value: index}` pairs
2. Iterate through the array with index `i`:
   - Calculate `complement = target - nums[i]`
   - If `complement` exists in hash map → return `[map[complement], i]`
   - Otherwise, store `nums[i]` → `i` in hash map
3. If no solution found, return empty (won't happen per constraints)

**Why it works:**
- Hash table gives O(1) lookup
- Single pass through the array
- Trades O(n) space for O(n) time (vs O(n²) brute force)

---

### 🔹 Approach 2: Brute Force (NOT RECOMMENDED)

```
for i in range(n):
    for j in range(i+1, n):
        if nums[i] + nums[j] == target:
            return [i, j]
```

| | |
|---|---|
| **Time** | O(n²) ❌ |
| **Space** | O(1) |
| **Status** | Time Limit Exceeded |

---

## 📝 Detailed Implementation

### C++ (Best Performance) ⭐
```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;  // value → index
        
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            
            // Check if complement exists
            if (mp.find(complement) != mp.end()) {
                return {mp[complement], i};
            }
            
            // Store current element
            mp[nums[i]] = i;
        }
        
        return {};  // No solution (won't happen)
    }
};
```

**Key Points:**
- `unordered_map` gives O(1) average lookup
- Early return when solution found
- Memory: 14.9MB, Runtime: 0ms

---

### Python 3 ⭐
```python
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        seen = {}  # value: index
        
        for i, num in enumerate(nums):
            complement = target - num
            
            if complement in seen:
                return [seen[complement], i
            
            seen[num] = i
        
        return []  # Won't reach here
```

---

### JavaScript ⭐
```javascript
class Solution {
    twoSum(nums, target) {
        const map = new Map();
        
        for (let i = 0; i < nums.length; i++) {
            const complement = target - nums[i];
            
            if (map.has(complement)) {
                return [map.get(complement), i];
            }
            
            map.set(nums[i], i);
        }
        
        return [];
    }
}
```

---

## 🎯 Complexity Analysis

| Approach | Time | Space | Status |
|---------|------|------|--------|
| **Hash Table** | **O(n)** | **O(n)** | ✅ Accepted |
| Brute Force | O(n²) | O(1) | ❌ TLE |
| Two Pass | O(n) | O(n) | ✅ Accepted |

**Why O(n)?**
- Single iteration through array: n elements
- Hash operations: O(1) average each
- Total: O(n)

**Why O(n) space?**
- Hash map stores up to n elements
- Worst case: we check all elements before finding answer

---

## 🔥 All Accepted Solutions

| File Name | Language | Runtime | Memory |
|----------|---------|---------|--------|
| 2025-09-29 09.57.40 - Accepted | Python 🐍 | 3ms 🟢 | 18.9MB |
| 2025-11-09 11.27.11 - Accepted | C | 58ms 🟡 | 8.6MB |
| 2025-11-10 18.21.43 - Accepted | JavaScript | 3ms 🟢 | 56.6MB |
| 2025-11-10 18.24.04 - Accepted | JavaScript | 0ms 🟢 | 57.4MB |
| **2026-04-12 22.31.16 - Accepted** ⭐ | **C++** | **0ms 🟢** | **14.9MB** |

---

## 🎓 Key Takeaways

### ✅ Best Practices
1. **Use Hash Map** for O(1) lookups
2. **Single pass** is optimal for this problem
3. **Check complement** before storing current element

### ❌ Common Mistakes
1. Using nested loops (O(n²) → TLE)
2. Forgetting to store index (only storing value)
3. Not handling the "same element twice" case properly

### 💡 Follow-up Questions
- What if you need to return values instead of indices?
- What ifmultiple valid answers exist?
- What if you need the O(n) solution with O(1) space?

---

## 🔗 Related Problems

| # | Problem | Difficulty | Status |
|---|---------|-----------|--------|
| 167 | Two Sum II | Easy | 📝 |
| 15 | 3Sum | Medium | 📝 |
| 18 | 4Sum | Medium | 📝 |
| 170 | Two Sum III | Easy | 📝 |

---

## 📈 Success Metrics

![Python](https://img.shields.io/badge/Python-3776AB?style=flat&logo=python&logoColor=white)
![JavaScript](https://img.shields.io/badge/JavaScript-F7DF1E?style=flat&logo=javascript&logoColor=black)
![C++](https://img.shields.io/badge/C++-00599C?style=flat&logo=c%2B%2B&logoColor=white)
![C](https://img.shields.io/badge/C-A8B9CC?style=flat&logo=c&logoColor=white)

**Total Submissions:** 5️⃣ **Accepted:** 5️⃣ **Acceptance Rate:** 100% ✅

---

*Made with ❤️ | Last Updated: 2026-04-13*