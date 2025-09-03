# 🚀 LeetCode 54: Spiral Matrix

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-yellow)
![Topic: Matrix](https://img.shields.io/badge/Topic-Matrix-blue)
![Status: ✅ Solved](https://img.shields.io/badge/Status-Solved-brightgreen)

## 📋 Problem Statement

Given an `m x n` matrix, return all elements of the matrix in spiral order.

The spiral order starts from the top-left corner and moves in a clockwise direction: right, down, left, up, and repeats.

---

## 📌 Quick Summary

| | |
|---|---|
| **Problem #** | 54 |
| **Difficulty** | Medium |
| **Topics** | Matrix, Simulation |
| **Similar Problems** | [59. Spiral Matrix II](./59-spiral-matrix-ii) |

---

## 🎯 Example Test Cases

### ✅ Example 1:
```
Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,3,6,9,8,7,4,5]
```

### ✅ Example 2:
```
Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]
```

---

## ⚠️ Constraints

```
- m == matrix.length
- n == matrix[i].length
- 1 <= m, n <= 10
- -100 <= matrix[i][j] <= 100
```

---

## 💡 Solution Approaches

### 🔹 Approach 1: Boundary Simulation ✅ RECOMMENDED

**Intuition:** Maintain four boundaries (top, bottom, left, right) and traverse in four directions, shrinking boundaries after each complete direction.

| | |
|---|---|
| **Time** | O(m * n) |
| **Space** | O(1) |

**Step-by-Step:**
1. Initialize four boundaries: top=0, bottom=m-1, left=0, right=n-1
2. Traverse right along top boundary, then increment top
3. Traverse down along right boundary, then decrement right
4. Traverse left along bottom boundary, then decrement bottom
5. Traverse up along left boundary, then increment left
6. Repeat until all elements are visited

---

## 📝 Detailed Implementation

### C++ ⭐
```cpp
vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> result;
    int m = matrix.size(), n = matrix[0].size();
    int top = 0, bottom = m - 1, left = 0, right = n - 1;
    
    while (top <= bottom && left <= right) {
        for (int col = left; col <= right; col++) result.push_back(matrix[top][col]);
        top++;
        
        for (int row = top; row <= bottom; row++) result.push_back(matrix[row][right]);
        right--;
        
        if (top <= bottom) {
            for (int col = right; col >= left; col--) result.push_back(matrix[bottom][col]);
            bottom--;
        }
        
        if (left <= right) {
            for (int row = bottom; row >= top; row--) result.push_back(matrix[row][left]);
            left++;
        }
    }
    return result;
}
```

---

## 🎯 Complexity Analysis

| Approach | Time | Space | Status |
|----------|------|-------|--------|
| Boundary Simulation | O(m * n) | O(1) | ✅ |

---

## 🔥 All Accepted Solutions

| File Name | Language | Runtime | Memory |
|----------|---------|---------|--------|
| 2026-04-07 16.34.03 - Accepted - runtime 0ms - memory 10.2MB.cpp | C++ | 0ms | 10.2MB |

---

## 🎓 Key Takeaways

### ✅ Best Practices
1. Use four boundary pointers to track visited edges
2. Check boundary validity before each traversal

### ❌ Common Mistakes
1. Forgetting to check boundaries when traversing backwards
2. Not updating boundaries properly

---

## 🔗 Related Problems

| # | Problem | Difficulty |
|---|---------|-----------|
| 59 | Spiral Matrix II | Medium |

---

*Made with ❤️ | Last Updated: 2026-04-13*
