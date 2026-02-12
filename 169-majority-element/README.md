# 🚀 LeetCode 169: Majority Element

![Difficulty: Easy](https://img.shields.io/badge/Difficulty-Easy-brightgreen)
![Topic: Array](https://img.shields.io/badge/Topic-Array-blue)
![Hash Table](https://img.shields.io/badge/Topic-Hash_Table-blue)
![Divide and Conquer](https://img.shields.io/badge/Topic-Divide_and_Conquer-blue)
![Sorting](https://img.shields.io/badge/Topic-Sorting-blue)
![Status: ✅ Solved](https://img.shields.io/badge/Status-Solved-brightgreen)

## 📋 Problem Statement

Given an array `nums` of size `n`, return the majority element.

The majority element is the element that appears more than `⌊n / 2⌋` times. You may assume that the majority element always exists in the array.

---

## 📌 Quick Summary

| | |
|---|---|
| **Problem #** | 169 |
| **Difficulty** | Easy |
| **Topics** | Array, Hash Table, Divide and Conquer, Sorting |
| **Companies** | Amazon, Apple, Google, Microsoft |
| **Similar Problems** | [Majority Element II](./229-majority-element-ii) |

---

## 🎯 Example Test Cases

### ✅ Example 1:
```
Input: nums = [3,2,3]
Output: 3
```

### ✅ Example 2:
```
Input: nums = [2,2,1,1,1,2,2]
Output: 2
```

---

## ⚠️ Constraints

```
n == nums.length
1 ≤ n ≤ 5 * 10^4
-2^31 ≤ nums[i] ≤ 2^31 - 1
Majority element always exists
```

---

## 💡 Solution Approaches

### 🔹 Approach 1: Boyer-Moore Voting Algorithm (Optimal) ✅ RECOMMENDED

**Intuition:** The majority element appears more than n/2 times. We can "cancel out" each occurrence of non-majority elements with one occurrence of the majority element.

| | |
|---|---|
| **Time** | O(n) |
| **Space** | O(1) |
| **Runtime** | 0ms ✅ |

**Step-by-Step:**
1. Initialize `candidate = null`, `count = 0`
2. For each number in the array:
   - If count is 0, set candidate to current number
   - If current number equals candidate, increment count
   - Otherwise, decrement count
3. Return candidate

**Why it works:**
- Majority element appears more than half the time
- Each non-majority element "cancels" one majority element
- Remaining candidate must be the majority

---

### 🔹 Approach 2: Hash Map (Alternative)

Count occurrences of each element and find the one with count > n/2.

| | |
|---|---|
| **Time** | O(n) |
| **Space** | O(n) |

---

## 📝 Detailed Implementation

### JavaScript ⭐
```javascript
function majorityElement(nums) {
    let candidate = null;
    let count = 0;

    for (const num of nums) {
        if (count === 0) {
            candidate = num;
        }

        count += (num === candidate) ? 1 : -1;
    }

    return candidate;
}
```

**Key Points:**
- Boyer-Moore Voting Algorithm
- O(n) time, O(1) space
- Runtime: 0ms, Memory: 57.5MB

---

### C++ ⭐
```cpp
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = 0;
        int count = 0;

        for (int num : nums) {
            if (count == 0) {
                candidate = num;
            }
            count += (num == candidate) ? 1 : -1;
        }

        return candidate;
    }
};
```

---

## 🎯 Complexity Analysis

| Approach | Time | Space | Status |
|----------|------|-------|--------|
| **Boyer-Moore** | **O(n)** | **O(1)** | ✅ Accepted |
| Hash Map | O(n) | O(n) | ✅ Accepted |
| Sorting | O(n log n) | O(n) | ✅ Accepted |

**Why O(n)?**
- Single pass through the array

**Why O(1) space?**
- Only two variables used (candidate, count)

---

## 🔥 All Accepted Solutions

| File Name | Language | Runtime | Memory |
|----------|---------|---------|--------|
| 2026-02-12 06.12.39 - Accepted | JavaScript | 0ms 🟢 | 57.5MB |
| 2026-04-07 11.06.36 - Accepted | C++ | 1ms 🟢 | 28.3MB |
| 2026-04-07 11.06.50 - Accepted | C++ | 3ms 🟢 | 28.4MB |
| 2026-04-07 11.13.15 - Accepted | C++ | 4ms 🟢 | 28.3MB |

---

## 🎓 Key Takeaways

### ✅ Best Practices
1. **Use Boyer-Moore** for O(1) space
2. **Understand the cancellation principle**
3. **Majority guarantee** simplifies the problem

### ❌ Common Mistakes
1. Not resetting candidate when count reaches 0
2. Forgetting majority element always exists
3. Using extra space when O(1) is possible

### 💡 Follow-up Questions
- How to handle when majority doesn't always exist?
- How to find element appearing > n/3 times?

---

## 🔗 Related Problems

| # | Problem | Difficulty | Status |
|---|---------|-----------|--------|
| 229 | Majority Element II | Medium | 📝 |
| 115 | Distinct Subsequences | Hard | 📝 |

---

## 📈 Success Metrics

![JavaScript](https://img.shields.io/badge/JavaScript-F7DF1E?style=flat&logo=javascript&logoColor=black)
![C++](https://img.shields.io/badge/C++-00599C?style=flat&logo=c%2B%2B&logoColor=white)

**Total Submissions:** 4️⃣ **Accepted:** 4️⃣ **Acceptance Rate:** 100% ✅

---

*Made with ❤️ | Last Updated: 2026-04-13*
