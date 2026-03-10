# 3407 - Find All Possible Stable Binary Arrays II

**Difficulty:** Hard  
**Problem Link:** [find-all-possible-stable-binary-arrays-ii](https://leetcode.com/problems/find-all-possible-stable-binary-arrays-ii/)

## Problem Description

Same as problem I but with larger constraints (zero, one, limit up to 1000). Count stable binary arrays with exactly zero zeros and one ones, where no subarray larger than limit contains only one digit.

## Solution Approach

**Optimized DP with prefix sum:**
- dp0[z][o] = arrays ending with 0, dp1[z][o] = arrays ending with 1
- Use prefix sums for O(1) transition per state instead of O(limit)
- Remove invalid states using subtraction of dp values at position limit+1 back

## Complexity Analysis

- **Time Complexity:** O(zero * one)
- **Space Complexity:** O(zero * one)

## Accepted Solutions

| File | Runtime | Memory | Language |
|------|---------|--------|----------|
| 2026-03-10 11.05.28 - Accepted - runtime 155ms - memory 176.7MB.cpp | 155ms | 176.7MB | C++ |

## Best Code Example

```cpp
class Solution {
public:
    int numberOfStableArrays(int zero, int one, int limit) {
        const int MOD = 1e9 + 7;

        vector<vector<long long>> dp0(zero + 1, vector<long long>(one + 1));
        vector<vector<long long>> dp1(zero + 1, vector<long long>(one + 1));

        for (int z = 1; z <= min(zero, limit); z++) dp0[z][0] = 1;
        for (int o = 1; o <= min(one, limit); o++) dp1[0][o] = 1;

        for (int z = 1; z <= zero; z++) {
            for (int o = 1; o <= one; o++) {
                long long val0 = (dp0[z-1][o] + dp1[z-1][o]) % MOD;
                if (z - limit - 1 >= 0)
                    val0 = (val0 - dp1[z-limit-1][o] + MOD) % MOD;
                dp0[z][o] = val0;

                long long val1 = (dp0[z][o-1] + dp1[z][o-1]) % MOD;
                if (o - limit - 1 >= 0)
                    val1 = (val1 - dp0[z][o-limit-1] + MOD) % MOD;
                dp1[z][o] = val1;
            }
        }

        return (dp0[zero][one] + dp1[zero][one]) % MOD;
    }
};
```