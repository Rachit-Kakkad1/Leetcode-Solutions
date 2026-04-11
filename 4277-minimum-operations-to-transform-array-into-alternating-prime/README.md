# 4277 - Minimum Operations to Transform Array into Alternating Prime

**Difficulty:** Medium

**Link:** [Minimum Operations to Transform Array into Alternating Prime - LeetCode](https://leetcode.com/problems/minimum-operations-to-transform-array-into-alternating-prime/)

## Problem Description

You are given an integer array `nums`.

An array is considered **alternating prime** if:

- Elements at **even** indices (0-based) are **prime** numbers.
- Elements at **odd** indices are **non-prime** numbers.

In one operation, you may **increment** any element by 1.

Return the **minimum** number of operations required to transform `nums` into an **alternating prime** array.

## Example Test Cases

### Example 1:
```
Input: nums = [1,2,3,4]
Output: 3
Explanation:
- Index 0: 1→2 (1 operation) - now prime
- Index 1: 2→4 (2 operations) - now non-prime
- Index 2: is already prime
- Index 3: is already non-prime
Total: 3
```

### Example 2:
```
Input: nums = [5,6,7,8]
Output: 0
Explanation: Already alternating prime
```

### Example 3:
```
Input: nums = [4,4]
Output: 1
Explanation: Index 0: 4→5 (1 operation)
```

## Constraints

- `1 <= nums.length <= 10^5`
- `1 <= nums[i] <= 10^5`

## Solution Approach

### Algorithm Explanation

Direct computation with prime checking:

1. For each element at even index:
   - If not prime, increment to next prime
   - Count operations needed
2. For each element at odd index:
   - If prime, increment to next non-prime
   - Count operations needed
3. Sum all operations

### Helper Functions

- `isPrime(x)`: Check if x is prime using trial division
- `nextPrime(x)`: Find next prime >= x
- `nextNonPrime(x)`: Find next non-prime >= x

### Why It Works

- Each element can be independently fixed
- Incrementing to next valid value is always optimal

## Complexity Analysis

- **Time Complexity:** O(n × √max(nums))
- **Space Complexity:** O(1)

## Accepted Solutions

| File Name | Language | Runtime | Memory |
|----------|----------|---------|--------|
| 2026-04-11 20.29.25 - Accepted - runtime 159ms - memory 122.3MB.cpp | C++ | 159ms | 122.3MB |

## Code Example (C++)

```cpp
class Solution {
public:
    bool isPrime(int x) {
        if (x < 2) return false;
        if (x == 2) return true;
        if (x % 2 == 0) return false;
        for (int i = 3; i * i <= x; i += 2)
            if (x % i == 0) return false;
        return true;
    }

    int nextPrime(int x) {
        while (!isPrime(x)) x++;
        return x;
    }

    int nextNonPrime(int x) {
        while (isPrime(x)) x++;
        return x;
    }

    int minOperations(vector<int>& nums) {
        int ops = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            int val = nums[i];
            
            if (i % 2 == 0) {
                if (!isPrime(val)) {
                    int target = nextPrime(val);
                    ops += target - val;
                }
            } else {
                if (isPrime(val)) {
                    int target = nextNonPrime(val);
                    ops += target - val;
                }
            }
        }
        
        return ops;
    }
};
```

**Runtime:** 159ms | **Memory:** 122.3MB