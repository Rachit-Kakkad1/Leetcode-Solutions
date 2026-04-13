# 🚀 LeetCode 119: Pascal's Triangle II

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)
![Topics](https://img.shields.io/badge/Topics-Array-blue)
![Acceptance](https://img.shields.io/badge/Acceptance-63.2%25-brightgreen)

---

## ⚡ The Problem

Given an index `rowIndex`, return the `rowIndex-th` row of Pascal's Triangle.

The triangle starts:
```
Row 0: [1]
Row 1: [1, 1]
Row 2: [1, 2, 1]
Row 3: [1, 3, 3, 1]
Row 4: [1, 4, 6, 4, 1]
```

---

## 💡 The Solution (C++)

```cpp
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> row = {1};

        for (int i = 1; i <= rowIndex; i++) {
            vector<int> newRow(i + 1, 1);

            for (int j = 1; j < i; j++) {
                newRow[j] = row[j - 1] + row[j];
            }

            row = newRow;
        }

        return row;
    }
};
```

### 🔥 How It Works

1. Start with row `{1}`
2. For each new row, create a vector of size `i+1` filled with 1s
3. Each internal element = `row[j-1] + row[j]` (sum of two above)
4. **Time Complexity**: O(rowIndex²)
5. **Space Complexity**: O(rowIndex²)

---

## 🎯 Alternative: O(k) Space Using USACO Formula

```cpp
vector<int> getRow(int rowIndex) {
    vector<int> row(rowIndex + 1, 1);
    for (int i = 2; i <= rowIndex; i++) {
        for (int j = i - 1; j > 0; j--) {
            row[j] += row[j - 1];
        }
    }
    return row;
}
```

Actually builds the row in-place using **binomial coefficients**!

---

## 🏆 Stats

| Metric | Value |
|--------|-------|
| Runtime | 0ms |
| Memory | 6.22 MB |
| Rank | Top 100% |

---

> *"Mathematical elegance meets programming brilliance."* 🔢