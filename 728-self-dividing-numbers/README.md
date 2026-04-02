# 728 - Self Dividing Numbers

**Difficulty:** Easy  
**Problem Link:** [self-dividing-numbers](https://leetcode.com/problems/self-dividing-numbers/)

## Problem Description

A self-dividing number is a number that is divisible by every digit it contains. Numbers containing digit zero are not allowed. Given `left` and `right`, return all self-dividing numbers in the range [left, right].

## Solution Approach

**Iterate and Check:**
1. For each number in range, extract each digit
2. Check if digit is zero (invalid) or if number % digit != 0
3. Add valid numbers to result

## Complexity Analysis

- **Time Complexity:** O((right - left) * log10(right))
- **Space Complexity:** O(k) where k = number of results

## Accepted Solutions

| File | Runtime | Memory | Language |
|------|---------|--------|----------|
| 2026-04-02 15.42.02 - Accepted - runtime 3ms - memory 55.3MB.js | 3ms | 55.3MB | JavaScript |
| 2026-04-02 16.00.18 - Accepted - runtime 0ms - memory 9MB.cpp | 0ms | 9MB | C++ |

## Best Code Example

```cpp
class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> result;

        for (int num = left; num <= right; num++) {
            int t = num;
            bool iv = true;

            while (t > 0) {
                int dt = t % 10;

                if (dt == 0) {
                    iv = false;
                    break;
                }

                if (num % dt != 0) {
                    iv = false;
                    break;
                }

                t /= 10;
            }

            if (iv) {
                result.push_back(num);
            }
        }

        return result;
    }
};
```