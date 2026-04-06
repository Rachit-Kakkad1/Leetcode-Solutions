# 279 - Perfect Squares

**Difficulty:** Medium

**Link:** [Perfect Squares - LeetCode](https://leetcode.com/problems/perfect-squares/)

## Problem Description

Given an integer `n`, return *the least number of perfect square numbers that sum to* `n`.

A **perfect square** is an integer that is the square of an integer; in other words, it is the product of some integer with itself. For example, `1`, `4`, `9`, and `16` are perfect squares while `3` and `11` are not.

## Example Test Cases

### Example 1:
```
Input: n = 12
Output: 3
Explanation: 12 = 4 + 4 + 4.
```

### Example 2:
```
Input: n = 13
Output: 2
Explanation: 13 = 4 + 9.
```

## Constraints

- `1 <= n <= 10^4`

## Solution Approach

### Algorithm Explanation

Use **dynamic programming** with bottom-up approach:

1. dp[i] = minimum perfect squares that sum to i
2. For each i, try all possible squares j² where j² <= i
3. dp[i] = min(dp[i], dp[i - j²] + 1)

### Step-by-Step Logic

1. Initialize dp array with INT_MAX, dp[0] = 0
2. For each i from 1 to n:
   - For each j from 1 while j*j <= i:
     - dp[i] = min(dp[i], dp[i - j*j] + 1)
3. Return dp[n]

### Why It Works

- DP correctly captures optimal substructure
- Each state depends only on smaller states
- The +1 accounts for using j² as one of the squares

## Complexity Analysis

- **Time Complexity:** O(n * sqrt(n)) - For each i, try up to sqrt(i) squares
- **Space Complexity:** O(n) - DP array

## Accepted Solutions

| File Name | Language | Runtime | Memory |
|-----------|----------|---------|--------|
| 2026-04-06 17.05.02 - Accepted - runtime 39ms - memory 13MB.cpp | C++ | 39ms | 13MB |

## Code Example (Best Solution - C++)

```cpp
class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j * j <= i; j++) {
                dp[i] = min(dp[i], dp[i - j*j] + 1);
            }
        }

        return dp[n];
    }
};
```

**Runtime:** 39ms | **Memory:** 13MB