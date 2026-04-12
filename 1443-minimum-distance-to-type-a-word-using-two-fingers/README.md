# 1443 - Minimum Distance to Type a Word Using Two Fingers

**Difficulty:** Hard  
**Problem Link:** [minimum-distance-to-type-a-word-using-two-fingers](https://leetcode.com/problems/minimum-distance-to-type-a-word-using-two-fingers/)

## Problem Description

You have a QWERTY keyboard layout where each English uppercase letter is located at coordinates in an X-Y plane. The distance between two letters is calculated as Manhattan distance: |x1 - x2| + |y1 - y2|.

Given a string `word`, return the minimum total distance to type the string using only two fingers. Initial positions of both fingers are free (don't count towards distance).

## Solution Approach

**Dynamic Programming:**
1. Calculate total distance if using one finger (distance between consecutive characters)
2. Use DP to track the "saved" distance by using two fingers optimally
3. For each character, consider having any previous letter on the other finger
4. Subtract maximum saved distance from total

## Complexity Analysis

- **Time Complexity:** O(n * 26) where n = word length
- **Space Complexity:** O(26) = O(1)

## Accepted Solutions

| File | Runtime | Memory | Language |
|------|---------|--------|----------|
| 2026-04-12 23.32.20 - Accepted - runtime 1ms - memory 8.3MB.cpp | 1ms | 8.3MB | C++ |

## Best Code Example

```cpp
class Solution {
public:
    int dist(int a, int b) {
        if (a == -1) return 0;
        int x1 = a / 6, y1 = a % 6;
        int x2 = b / 6, y2 = b % 6;
        return abs(x1 - x2) + abs(y1 - y2);
    }

    int minimumDistance(string word) {
        vector<int> dp(26, 0);
        int total = 0;

        for (int i = 0; i < word.size() - 1; i++) {
            int a = word[i] - 'A';
            int b = word[i + 1] - 'A';

            int d = dist(a, b);
            total += d;

            for (int j = 0; j < 26; j++) {
                dp[a] = max(dp[a], dp[j] + d - dist(j, b));
            }
        }

        int best = 0;
        for (int x : dp) best = max(best, x);

        return total - best;
    }
};
```