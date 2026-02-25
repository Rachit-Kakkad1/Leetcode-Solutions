# 3154 - Maximum Value of an Ordered Triplet I

**Difficulty:** Easy

**Link:** [Maximum Value of an Ordered Triplet I - LeetCode](https://leetcode.com/problems/maximum-value-of-an-ordered-triplet-i/)

## Problem Description

You are given a **0-indexed** integer array `nums`.

Return *the **maximum value over all triplets of indices** (i, j, k) such that* `i < j < k`. If all such triplets have a negative value, return `0`.

The **value of a triplet of indices** (i, j, k) is equal to `(nums[i] - nums[j]) * nums[k]`.

## Example Test Cases

### Example 1:
```
Input: nums = [12,6,1,2,7]
Output: 77
Explanation: The value of the triplet (0, 2, 4) is (nums[0] - nums[2]) * nums[4] = 77.
```

### Example 2:
```
Input: nums = [1,10,3,4,19]
Output: 133
Explanation: The value of the triplet (1, 2, 4) is (nums[1] - nums[2]) * nums[4] = 133.
```

### Example 3:
```
Input: nums = [1,2,3]
Output: 0
Explanation: The only ordered triplet of indices (0, 1, 2) has a negative value of (nums[0] - nums[1]) * nums[2] = -3.
```

## Constraints

- `3 <= nums.length <= 100`
- `1 <= nums[i] <= 10^6`

## Solution Approach

### Algorithm Explanation

Use **brute force** with three nested loops since n <= 100:

1. Try all possible triplets (i, j, k) where i < j < k
2. Calculate the value: (nums[i] - nums[j]) * nums[k]
3. Track maximum value, return 0 if all are negative

### Step-by-Step Logic

1. Initialize maxval = 0
2. Loop i from 0 to n-3
3. Loop j from i+1 to n-2
4. Loop k from j+1 to n-1
5. Calculate val = (nums[i] - nums[j]) * nums[k]
6. Update maxval if val > maxval
7. Return maxval

### Why It Works

- All valid triplets are checked exhaustively
- Maximum value is correctly tracked
- n <= 100 makes O(n³) acceptable (max ~161,700 combinations)

## Complexity Analysis

- **Time Complexity:** O(n³) - Three nested loops
- **Space Complexity:** O(1) - Only tracking max value

## Accepted Solutions

| File Name | Language | Runtime | Memory |
|-----------|----------|---------|--------|
| 2026-02-25 09.30.48 - Accepted - runtime 2ms - memory 56.8MB.js | JavaScript | 2ms | 56.8MB |
| 2026-02-25 09.43.17 - Accepted - runtime 1ms - memory 21.8MB.cpp | C++ | 1ms | 21.8MB |

## Code Example (Best Solution - C++)

```cpp
class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
    long long maxval = 0;

    for(int i =0;  i< nums.size()-2;i++){
        for(int j= i+1;j<nums.size()-1;j++){
            for(int k = j+1;k<nums.size();k++){
                long long val = (long long)
                (nums[i] - nums[j])*nums[k];
                if(val > maxval){
                    maxval = val;
                }
            }
        }
    }
    return maxval;
 }
 
};
```

**Runtime:** 1ms | **Memory:** 21.8MB