# 4280 - Count Digit Appearances

**Difficulty:** Easy  
**Problem Link:** [count-digit-appearances](https://leetcode.com/problems/count-digit-appearances/)

## Problem Description

Given an array of integers and a digit, count the total number of appearances of that digit across all numbers in the array.

## Solution Approach

**Digit Counting:**
1. Iterate through each number in the array
2. Extract each digit using modulo and division
3. Count matches with the target digit

## Complexity Analysis

- **Time Complexity:** O(n * d) where n = array size, d = avg digits per number
- **Space Complexity:** O(1)

## Accepted Solutions

| File | Runtime | Memory | Language |
|------|---------|--------|----------|
| 2026-04-11 20.28.42 - Accepted - runtime 4ms - memory 38.9MB.cpp | 4ms | 38.9MB | C++ |

## Best Code Example

```cpp
class Solution {
public:
    int countDigitOccurrences(vector<int>& nums, int digit) {
        int ans = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            int x = nums[i];
            do {
                ans += (x % 10 == digit);
                x /= 10;
            } while (x);
        }
        
        return ans;
    }
};
```