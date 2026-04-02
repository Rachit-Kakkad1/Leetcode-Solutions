# 1674 - Minimum Operations to Make Array Equal

**Difficulty:** Medium

**Link:** [Minimum Operations to Make Array Equal - LeetCode](https://leetcode.com/problems/minimum-operations-to-make-array-equal/)

## Problem Description

You have an array `arr` of length `n` where `arr[i] = (2 * i) + 1` for all valid values of `i` (i.e., `0 <= i < n`).

In one operation, you can select two indices `x` and `y` where `0 <= x, y < n` and subtract `1` from `arr[x]` and add `1` to `arr[y]` (i.e., perform `arr[x] -=1` and `arr[y] += 1`). The goal is to make all the elements of the array **equal**. It is **guaranteed** that all the elements of the array can be made equal using some operations.

Given an integer `n`, the length of the array, return *the minimum number of operations* needed to make all the elements of arr equal.

## Example Test Cases

### Example 1:
```
Input: n = 3
Output: 2
Explanation: arr = [1, 3, 5]
First operation choose x = 2 and y = 0, this leads arr to be [2, 3, 4]
In the second operation choose x = 2 and y = 0 again, thus arr = [3, 3, 3].
```

### Example 2:
```
Input: n = 6
Output: 9
```

## Constraints

- `1 <= n <= 10^4`

## Solution Approach

### Algorithm Explanation

Mathematical insight about the target value:

1. Array is [1, 3, 5, 7, ...] - odd numbers from 1 to (2n-1)
2. Target value = (first + last) / 2 = (1 + (2n-1)) / 2 = n
3. For each element > n, we need to transfer to elements < n
4. The optimal number of operations is n²/4

### Step-by-Step Logic

1. For even n: operations = (n/2) * (n/2)
2. For odd n: operations = ((n-1)/2) * ((n+1)/2)
3. Both simplify to n²/4 using integer division

### Why It Works

- Each operation moves 1 unit closer to the target value n
- Elements above n must give away (n - arr[i]) units total
- Elements below n must receive (arr[i] - n) units total
- These totals are equal, ensuring feasibility

## Complexity Analysis

- **Time Complexity:** O(1) - Constant time formula
- **Space Complexity:** O(1)

## Accepted Solutions

| File Name | Language | Runtime | Memory |
|-----------|----------|---------|--------|
| 2026-04-02 17.11.10 - Accepted - runtime 0ms - memory 8.1MB.cpp | C++ | 0ms | 8.1MB |

## Code Example (Best Solution - C++)

```cpp
class Solution {
public:
    int minOperations(int n) {
        return (n*n)/4;
    }
};
```

**Runtime:** 0ms | **Memory:** 8.1MB