# 🚀 LeetCode 79: Word Search

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-yellow)
![Topic: Array](https://img.shields.io/badge/Topic-Array-blue)
![Backtracking](https://img.shields.io/badge/Topic-Backtracking-blue)
![Matrix](https://img.shields.io/badge/Topic-Matrix-blue)
![Status: ✅ Solved](https://img.shields.io/badge/Status-Solved-brightgreen)

## 📋 Problem Statement

Given an `m x n` grid of characters `board` and a string `word`, return `true` if `word` exists in the grid.

The word can be constructed from letters of sequentially adjacent cells (horizontally or vertically). The same letter cell may not be used more than once.

---

## 📌 Quick Summary

| | |
|---|---|
| **Problem #** | 79 |
| **Difficulty** | Medium |
| **Topics** | Array, Backtracking, Matrix |
| **Companies** | Amazon, Apple, Google, Microsoft |
| **Similar Problems** | [Word Search II](./212-word-search-ii) |

---

## 🎯 Example Test Cases

### ✅ Example 1:
```
Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
Output: true
Explanation: The path is: A → B → C → C → E → D
```

### ✅ Example 2:
```
Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
Output: true
Explanation: The path is: E → E → E (vertically)
```

### ✅ Example 3:
```
Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
Output: false
Explanation: Cannot reuse the same cell 'B' twice
```

---

## ⚠️ Constraints

```
m == board.length
n = board[i].length
1 ≤ m, n ≤ 6
1 ≤ word.length ≤ 15
board and word consists of lowercase and uppercase English letters
```

---

## 💡 Solution Approaches

### 🔹 Approach 1: Backtracking (DFS) ✅ RECOMMENDED

**Intuition:** Use DFS to explore all possible paths from each starting cell.

| | |
|---|---|
| **Time** | O(m * n * 4^L) |
| **Space** | O(L) |
| **Runtime** | 305ms ✅ |

**Step-by-Step:**
1. Iterate through each cell as a starting point
2. Use DFS to explore all four directions
3. Mark visited cells temporarily with a marker (*)
4. Backtrack by restoring the original character
5. Return true when the full word is matched

**Why it works:**
- Explores all possible paths systematically
- Marks cells to avoid reuse
- Backtracks to try other paths

---

## 📝 Detailed Implementation

### JavaScript ⭐
```javascript
function exist(board, word) {
    let rows = board.length;
    let cols = board[0].length;

    function search(r, c, index) {
        if (index === word.length) {
            return true;
        }

        if (
            r < 0 ||
            c < 0 ||
            r >= rows ||
            c >= cols ||
            board[r][c] !== word[index]
        ) {
            return false;
        }

        let temp = board[r][c];
        board[r][c] = "*";

        let found =
            search(r + 1, c, index + 1) ||
            search(r - 1, c, index + 1) ||
            search(r, c + 1, index + 1) ||
            search(r, c - 1, index + 1);

        board[r][c] = temp;

        return found;
    }

    for (let i = 0; i < rows; i++) {
        for (let j = 0; j < cols; j++) {
            if (search(i, j, 0)) {
                return true;
            }
        }
    }

    return false;
}
```

**Key Points:**
- DFS with backtracking
- Marks visited cells with "*"
- Runtime: 305ms, Memory: 54.6MB

---

## 🎯 Complexity Analysis

| Approach | Time | Space | Status |
|----------|------|-------|--------|
| **Backtracking (DFS)** | **O(m * n * 4^L)** | **O(L)** | ✅ Accepted |

**Why O(m * n * 4^L)?**
- Each cell can be a starting point: m * n
- Each position has up to 4 directions
- L is the word length

**Why O(L) space?**
- Recursion stack depth equals word length

---

## 🔥 All Accepted Solutions

| File Name | Language | Runtime | Memory |
|----------|---------|---------|--------|
| 2026-03-02 13.22.10 - Accepted | **JavaScript** | **305ms 🟡** | **54.6MB** |

---

## 🎓 Key Takeaways

### ✅ Best Practices
1. **Use backtracking** for path-finding problems
2. **Mark visited cells** to avoid reuse
3. **Backtrack** to restore original state

### ❌ Common Mistakes
1. Forgetting to restore the cell after DFS
2. Not checking boundary conditions
3. Not handling early termination

### 💡 Follow-up Questions
- How to optimize with Trie for multiple words?
- How to find all word occurrences?

---

## 🔗 Related Problems

| # | Problem | Difficulty | Status |
|---|---------|-----------|--------|
| 212 | Word Search II | Hard | 📝 |
| 200 | Number of Islands | Medium | 📝 |
| 130 | Surrounded Regions | Medium | 📝 |

---

## 📈 Success Metrics

![JavaScript](https://img.shields.io/badge/JavaScript-F7DF1E?style=flat&logo=javascript&logoColor=black)

**Total Submissions:** 1️⃣ **Accepted:** 1️⃣ **Acceptance Rate:** 100% ✅

---

*Made with ❤️ | Last Updated: 2026-04-13*
