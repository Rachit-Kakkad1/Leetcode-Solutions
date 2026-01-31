# 🚀 LeetCode 4: Median of Two Sorted Arrays

![Difficulty: Hard](https://img.shields.io/badge/Difficulty-Hard-red)
![Binary Search](https://img.shields.io/badge/Topic-Binary_Search-blue)
![Array](https://img.shields.io/badge/Topic-Array-blue)
![Divide and Conquer](https://img.shields.io/badge/Topic-Divide_and_Conquer-blue)
![Status: ✅ Solved](https://img.shields.io/badge/Status-Solved-brightgreen)

## 📋 Problem Statement

Given two sorted arrays `nums1` and `nums2` of size m and n respectively, return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).

---

## 📌 Quick Summary

| | |
|---|---|
| **Problem #** | 4 |
| **Difficulty** | Hard |
| **Topics** | Binary Search, Array, Divide and Conquer |
| **Companies** | Amazon, Google, Microsoft, Apple |
| **Similar Problems** | [Find Kth Element](./) |

---

## 🎯 Example Test Cases

### ✅ Example 1:
```
Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.
```

### ✅ Example 2:
```
Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
```

---

## ⚠️ Constraints

- nums1.length == m
- nums2.length == n
- 0 ≤ m ≤ 1000
- 0 ≤ n ≤ 1000
- 1 ≤ m + n ≤ 2000
- -10⁶ ≤ nums1[i], nums2[i] ≤ 10⁶

---

## 💡 Solution Approaches

### 🔹 Approach 1: Binary Search (Optimal) ✅ RECOMMENDED

**Intuition:** Use binary search on the smaller array to find the partition point where left half <= right half in both arrays.

| | |
|---|---|
| **Time** | O(log(min(m, n))) |
| **Space** | O(1) |
| **Runtime** | 0ms ✅ |

**Step-by-Step:**
1. Ensure nums1 is the smaller array
2. Binary search on nums1 to find partition point
3. Calculate partition elements on both arrays
4. Check if partitions are valid (left <= right)
5. Calculate median from partition elements

**Why it works:**
- Binary search reduces search space by half each iteration
- Partition ensures all left elements <= all right elements

---

### 🔹 Approach 2: Merge and Find Median (NOT RECOMMENDED)

Merge both arrays and find median.

| | |
|---|---|
| **Time** | O(m + n) ❌ |
| **Space** | O(m + n) |

---

## 📝 Detailed Implementation

### C++ ⭐
```cpp
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size())
            return findMedianSortedArrays(nums2, nums1);

        int m = nums1.size(), n = nums2.size();
        int low = 0, high = m;
        int half = (m + n + 1) / 2;

        while (low <= high) {
            int i = (low + high) / 2; 
            int j = half - i;      

            int l1 = (i == 0) ? INT_MIN : nums1[i - 1];
            int r1 = (i == m) ? INT_MAX : nums1[i];
            int l2 = (j == 0) ? INT_MIN : nums2[j - 1];
            int r2 = (j == n) ? INT_MAX : nums2[j];

            if (l1 <= r2 && l2 <= r1) {
                if ((m + n) % 2 == 1)
                    return max(l1, l2);
                else
                    return (max(l1, l2) + min(r1, r2)) / 2.0;
            }
            else if (l1 > r2)
                high = i - 1;
            else
                low = i + 1;
        }

        return 0.0;
    }
};
```

**Key Points:**
- Uses dummy values for boundary conditions
- Handles both even and odd lengths
- Runtime: 0ms, Memory: 94.9MB

---

### JavaScript ⭐
```javascript
var findMedianSortedArrays = function(nums1, nums2) {
    if (nums1.length > nums2.length) {
        [nums1, nums2] = [nums2, nums1];
    }
    
    let m = nums1.length, n = nums2.length;
    let low = 0, high = m;
    let half = Math.floor((m + n + 1) / 2);
    
    while (low <= high) {
        let i = Math.floor((low + high) / 2);
        let j = half - i;
        
        let l1 = i === 0 ? -Infinity : nums1[i - 1];
        let r1 = i === m ? Infinity : nums1[i];
        let l2 = j === 0 ? -Infinity : nums2[j - 1];
        let r2 = j === n ? Infinity : nums2[j];
        
        if (l1 <= r2 && l2 <= r1) {
            if ((m + n) % 2 === 1) {
                return Math.max(l1, l2);
            }
            return (Math.max(l1, l2) + Math.min(r1, r2)) / 2;
        } else if (l1 > r2) {
            high = i - 1;
        } else {
            low = i + 1;
        }
    }
    
    return 0;
};
```

---

## 🎯 Complexity Analysis

| Approach | Time | Space | Status |
|----------|------|-------|--------|
| **Binary Search** | **O(log(min(m,n)))** | **O(1)** | ✅ Accepted |
| Merge Arrays | O(m + n) | O(m + n) | ⚠️ TLE |

**Why O(log(min(m, n)))?**
- Binary search halves search space each iteration
- Only search on the smaller array

**Why O(1) space?**
- Only uses constant extra variables

---

## 🔥 All Accepted Solutions

| File Name | Language | Runtime | Memory |
|----------|---------|---------|--------|
| 2026-02-01 00.31.39 - Accepted - runtime 3ms - memory 58.6MB.js | JavaScript | 3ms 🟡 | 58.6MB |
| 2026-02-01 00.33.57 - Accepted - runtime 3ms - memory 58MB.js | JavaScript | 3ms 🟡 | 58MB |
| **2026-04-12 21.26.38 - Accepted** ⭐ | **C++** | **0ms 🟢** | **95.2MB** |
| 2026-04-12 22.09.04 - Accepted | C++ | 0ms 🟢 | 94.9MB |
| 2026-04-12 22.11.57 - Accepted | C++ | 3ms 🟡 | 95.1MB |

---

## 🎓 Key Takeaways

### ✅ Best Practices
1. **Binary search** on the smaller array
2. Use **dummy values** for boundaries
3. Check both partition conditions

### ❌ Common Mistakes
1. Not handling different array sizes
2. Forgetting edge cases at boundaries
3. Using incorrect partition calculations

### 💡 Follow-up Questions
- How to find the kth element?
- How to handle duplicates?

---

## 🔗 Related Problems

| # | Problem | Difficulty | Status |
|---|---------|-----------|--------|
| 295 | Find Median from Data Stream | Hard | 📝 |

---

## 📈 Success Metrics

![JavaScript](https://img.shields.io/badge/JavaScript-F7DF1E?style=flat&logo=javascript&logoColor=black)
![C++](https://img.shields.io/badge/C++-00599C?style=flat&logo=c%2B%2B&logoColor=white)

**Total Submissions:** 5️⃣ **Accepted:** 4️⃣ **Acceptance Rate:** 80% ✅

---

*Made with ❤️ | Last Updated: 2026-04-13*