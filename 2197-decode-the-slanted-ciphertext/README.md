# 2197 - Decode the Slanted Ciphertext

**Difficulty:** Medium  
**Problem Link:** [decode-the-slanted-ciphertext](https://leetcode.com/problems/decode-the-slanted-ciphertext/)

## Problem Description

A string `originalText` is encoded using a slanted transposition cipher to `encodedText` using a matrix with `rows`. The original text is placed in top-left to bottom-right manner, and encoded by reading row-wise.

Given `encodedText` and `rows`, return the original string.

## Solution Approach

**Matrix Reconstruction:**
1. Calculate columns = encodedText.length / rows
2. Build the matrix row-wise from encodedText
3. Read diagonally (top-left to bottom-right) to reconstruct original text
4. Remove trailing spaces

## Complexity Analysis

- **Time Complexity:** O(n) where n = encodedText length
- **Space Complexity:** O(n) for the matrix

## Accepted Solutions

| File | Runtime | Memory | Language |
|------|---------|--------|----------|
| 2026-04-05 00.30.14 - Accepted - runtime 40ms - memory 43.4MB.cpp | 40ms | 43.4MB | C++ |

## Best Code Example

```cpp
class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int n = encodedText.size();
        if (rows == 1) return encodedText;

        int cols = n / rows;

        vector<vector<char>> mat(rows, vector<char>(cols));
        int idx = 0;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                mat[i][j] = encodedText[idx++];
            }
        }

        string result = "";

        for (int startCol = 0; startCol < cols; startCol++) {
            int i = 0, j = startCol;

            while (i < rows && j < cols) {
                result += mat[i][j];
                i++;
                j++;
            }
        }
        while (!result.empty() && result.back() == ' ') {
            result.pop_back();
        }

        return result;
    }
};
```