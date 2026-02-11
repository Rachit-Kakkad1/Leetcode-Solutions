# 🚀 LeetCode 15: 3Sum

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-yellow)
![Array](https://img.shields.io/badge/Topic-Array-blue)
![Sorting](https://img.shields.io/badge/Topic-Sorting-blue)
![Two Pointers](https://img.shields.io/badge/Topic-Two_Pointers-blue)
![Status: ✅ Solved](https://img.shields.io/badge/Status-Solved-brightgreen)

## 📋 Problem Statement

Given an integer array `nums`, return all the triplets `[nums[i], nums[j], nums[k]]` such that `i != j`, `i != k`, and `j != k`, and `nums[i] + nums[j] + nums[k] == 0`.

Notice that the solution set must not contain duplicate triplets.

---

## 📌 Quick Summary

| | |
|---|---|
| **Problem #** | 15 |
| **Difficulty** | Medium |
| **Topics** | Array, Sorting, Two Pointers |
| **Companies** | Amazon, Apple, Google, Microsoft |
| **Similar Problems** | [Two Sum](./1-two-sum), [3Sum Closest](./16-3sum-closest), [4Sum](./18-4sum) |

---

## 🎯 Example Test Cases

### ✅ Example 1:
```
Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Explanation: The distinct triplets are [-1,0,1] and [-1,-1,2].
```

### ✅ Example 2:
```
Input: nums = [0,1,1]
Output: []
Explanation: The only possible triplet [0,1,1] doesn't sum to 0.
```

### ✅ Example 3:
```
Input: nums = [0,0,0]
Output: [[0,0,0]]
Explanation: The only possible triplet sums to 0.
```

---

## ⚠️ Constraints

- 3 ≤ nums.length ≤ 3000
- -10⁵ ≤ nums[i] ≤ 10⁵

---

## 💡 Solution Approaches

### 🔹 Approach 1: Sort + Two Pointers (Optimal) ✅ RECOMMENDED

**Intuition:** Sort the array, then for each element use two pointers to find complement.

| | |
|---|---|
| **Time** | O(n²) |
| **Space** | O(1) excluding output |
| **Runtime** | 34ms ✅ |

**Step-by-Step:**
1. Sort the array
2. For each element (at index i):
   - Skip duplicates to avoid duplicate triplets
   - Use two pointers (left = i+1, right = n-1)
   - Move pointers based on sum

**Why it works:**
- Sorting enables two-pointer technique
- Skipping duplicates ensures no duplicates in result
- O(n²) time - efficient for this problem

---

### 🔹 Approach 2: Hash Set (Alternative)

Use hash set to store seen pairs.

| | |
|---|---|
| **Time** | O(n²) |
| **Space** | O(n) |

---

## 📝 Detailed Implementation

### JavaScript ⭐
```javascript
function threeSum(nums) {
    nums.sort((a, b) => a - b);
    const res = [];

    for (let i = 0; i < nums.length - 2; i++) {
        if (i > 0 && nums[i] === nums[i - 1]) continue;

        let lt = i + 1;
        let rt = nums.length - 1;

        while (lt < rt) {
            const sum = nums[i] + nums[lt] + nums[rt];

            if (sum === 0) {
                res.push([nums[i], nums[lt], nums[rt]]);
                while (lt < rt && nums[lt] === nums[lt + 1]) lt++;
                while (lt < rt && nums[rt] === nums[rt - 1]) rt--;
                lt++;
                rt--;
            }
            else if (sum < 0) {
                lt++;
            }
            else {
                rt--;
            }
        }
    }

    return res;
}
```

**Key Points:**
- Sorting enables binary search-like two pointers
- Skipping duplicates prevents duplicate triplets
- Runtime: 34ms, Memory: 72.2MB

---

## 🎯 Complexity Analysis

| Approach | Time | Space | Status |
|----------|------|-------|--------|
| **Sort + Two Pointers** | **O(n²)** | **O(1)** | ✅ Accepted |
| Hash Set | O(n²) | O(n) | ✅ Accepted |

**Why O(n²)?**
- Sorting: O(n log n)
- Outer loop: O(n)
- Two pointers: O(n)
- Total: O(n²)

**Why O(1) space?**
- Only uses constant extra variables
- Output doesn't count

---

## 🔥 All Accepted Solutions

| File Name | Language | Runtime | Memory |
|----------|---------|---------|--------|
| 2026-02-11 10.50.49 - Accepted - runtime 34ms - memory 72.2MB.js | **JavaScript** | **34ms 🟡** | **72.2MB** |

---

## 🎓 Key Takeaways

### ✅ Best Practices
1. **Sort first** for two-pointer technique
2. **Skip duplicates** to avoid duplicate results
3. **Handle edge cases** (less than 3 elements)

### ❌ Common Mistakes
1. Not sorting and using two pointers incorrectly
2. forgetting to skip duplicates
3. Not handling all elements the same

### 💡 Follow-up Questions
- How to return indices instead of values?
- How to handle 4Sum?

---

## 🔗 Related Problems

| # | Problem | Difficulty | Status |
|---|---------|-----------|--------|
| 1 | Two Sum | Easy | 📝 |
| 16 | 3Sum Closest | Medium | 📝 |
| 18 | 4Sum | Medium | 📝 |

---

## 📈 Success Metrics

![JavaScript](https://img.shields.io/badge/JavaScript-F7DF1E?style=flat&logo=javascript&logoColor=black)

**Total Submissions:** 1️⃣ **Accepted:** 1️⃣ **Acceptance Rate:** 100% ✅

---

*Made with ❤️ | Last Updated: 2026-04-13*