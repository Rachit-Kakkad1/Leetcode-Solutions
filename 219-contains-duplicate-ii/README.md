# 🚀 LeetCode 219: Contains Duplicate II

![Difficulty: Easy](https://img.shields.io/badge/Difficulty-Easy-brightgreen)
![Topic: Array](https://img.shields.io/badge/Topic-Array-blue)
![Hash Table](https://img.shields.io/badge/Topic-Hash_Table-blue)
![Sliding Window](https://img.shields.io/badge/Topic-Sliding_Window-blue)
![Status: ✅ Solved](https://img.shields.io/badge/Status-Solved-brightgreen)

## 📋 Problem Statement

Given an integer array `nums` and an integer `k`, return `true` if there are two distinct indices `i` and `j` such that `nums[i] == nums[j]` and `abs(i - j) <= k`.

---

## 📌 Quick Summary

| | |
|---|---|
| **Problem #** | 219 |
| **Difficulty** | Easy |
| **Topics** | Array, Hash Table, Sliding Window |
| **Companies** | Amazon, Apple |
| **Similar Problems** | [Contains Duplicate](./217-contains-duplicate) |

---

## 🎯 Example Test Cases

### ✅ Example 1:
```
Input: nums = [1,2,3,1], k = 3
Output: true
Explanation: nums[0] == nums[3], |0 - 3| = 3 ≤ 3
```

### ✅ Example 2:
```
Input: nums = [1,0,1,1], k = 2
Output: true
Explanation: nums[2] == nums[3], |2 - 3| = 1 ≤ 2
```

### ✅ Example 3:
```
Input: nums = [1,2,3,1,2,3], k = 2
Output: false
```

---

## ⚠️ Constraints

```
1 ≤ nums.length ≤ 10^5
-10^9 ≤ nums[i] ≤ 10^9
0 ≤ k ≤ 10^5
```

---

## 💡 Solution Approaches

### 🔹 Approach 1: Sliding Window with Hash Set (Optimal) ✅ RECOMMENDED

**Intuition:** Keep a sliding window of size k and check for duplicates.

| | |
|---|---|
| **Time** | O(n) |
| **Space** | O(k) |
| **Runtime** | 20ms ✅ |

**Step-by-Step:**
1. Create a Set for the sliding window
2. For each element:
   - If element already in set, return true
   - Add element to set
   - If set size > k, remove oldest element
3. Return false if no duplicates found

**Why it works:**
- Set stores elements within distance k
- If we see a duplicate, it's within the required distance

---

## 📝 Detailed Implementation

### JavaScript ⭐
```javascript
function containsNearbyDuplicate(nums, k) {
    const set = new Set();

    for (let i = 0; i < nums.length; i++) {
        if (set.has(nums[i])) return true;

        set.add(nums[i]);

        if (set.size > k) {
            set.delete(nums[i - k]);
        }
    }

    return false;
}
```

**Key Points:**
- Sliding window with hash set
- O(n) time, O(k) space
- Runtime: 20ms, Memory: 70.6MB

---

## 🎯 Complexity Analysis

| Approach | Time | Space | Status |
|----------|------|-------|--------|
| **Sliding Window** | **O(n)** | **O(k)** | ✅ Accepted |
| Hash Map | O(n) | O(n) | ✅ Accepted |

**Why O(n)?**
- Single pass through array

**Why O(k) space?**
- Set stores at most k elements

---

## 🔥 All Accepted Solutions

| File Name | Language | Runtime | Memory |
|----------|---------|---------|--------|
| 2026-02-12 06.13.10 - Accepted | **JavaScript** | **20ms 🟡** | **70.6MB** |

---

## 🎓 Key Takeaways

### ✅ Best Practices
1. **Use sliding window** for distance constraint
2. **Hash Set** for O(1) lookups
3. **Remove oldest** element when window exceeds k

### ❌ Common Mistakes
1. Not removing elements outside window
2. Not handling k = 0 case
3. Using brute force (causes TLE)

### 💡 Follow-up Questions
- How to find indices with minimum distance?
- How to handle multiple duplicates?

---

## 🔗 Related Problems

| # | Problem | Difficulty | Status |
|---|---------|-----------|--------|
| 217 | Contains Duplicate | Easy | 📝 |
| 220 | Contains Duplicate III | Medium | 📝 |

---

## 📈 Success Metrics

![JavaScript](https://img.shields.io/badge/JavaScript-F7DF1E?style=flat&logo=javascript&logoColor=black)

**Total Submissions:** 1️⃣ **Accepted:** 1️⃣ **Acceptance Rate:** 100% ✅

---

*Made with ❤️ | Last Updated: 2026-04-13*
