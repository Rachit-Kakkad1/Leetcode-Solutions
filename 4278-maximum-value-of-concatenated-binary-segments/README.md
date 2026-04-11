# 4278 - Maximum Value of Concatenated Binary Segments

**Difficulty:** Hard

**Link:** [Maximum Value of Concatenated Binary Segments - LeetCode](https://leetcode.com/problems/maximum-value-of-concatenated-binary-segments/)

## Problem Description

You are given two arrays `nums1` and `nums0`, both of length `n`.

Each element `nums1[i]` represents a segment with `nums1[i]` ones followed by `nums0[i]` zeros.

You need to concatenate these `n` segments in some order to form a binary string. The value of a binary string is its interpretation as a binary number.

Return the maximum possible value of the concatenated binary string modulo `10^9 + 7`.

## Example Test Cases

### Example 1:
```
Input: nums1 = [1,2], nums0 = [1,1]
Output: Explanation: Best order produces maximum binary value
```

### Example 2:
```
Input: nums1 = [1,2], nums0 = [2,2]
Output: Maximize by proper ordering
```

## Constraints

- `1 <= n <= 10^5`
- `0 <= nums1[i], nums0[i] <= 10^5`

## Solution Approach

### Algorithm Explanation

Custom comparator-based sorting:

1. Custom comparison: Segment A is better than B if A+B produces larger binary value than B+A
2. Sort all segments using this comparator
3. Concatenate in sorted order
4. Compute the resulting binary value modulo MOD

### Step-by-Step Logic

1. Create pairs (ones, zeros) for each segment
2. Sort using custom comparator that compares A+B vs B+A
3. Build result: append '1' ones, then '0' zeros for each segment
4. Compute value: for each bit, result = (result * 2 + bit) % MOD

### Why It Works

- The custom comparator ensures optimal ordering
- Greedy sorting works because concatenation is associative
- The comparison is transitive and total

## Complexity Analysis

- **Time Complexity:** O(n log n)
- **Space Complexity:** O(n)

## Accepted Solutions

| File Name | Language | Runtime | Memory |
|----------|----------|---------|--------|
| 2026-04-11 20.32.11 - Accepted - runtime 446ms - memory 140.3MB.cpp | C++ | 446ms | 140.3MB |

## Code Example (C++)

```cpp
class Solution {
public:
    static const int MOD = 1e9 + 7;

    bool better(pair<int,int>& a, pair<int,int>& b) {
        int a1 = a.first, a0 = a.second;
        int b1 = b.first, b0 = b.second;

        int i = 0, j = 0;
        int n = a1 + a0 + b1 + b0;

        for (int k = 0; k < n; k++) {
            int x, y;

            if (k < a1 + a0) {
                if (k < a1) x = 1;
                else x = 0;
            } else {
                int t = k - (a1 + a0);
                if (t < b1) x = 1;
                else x = 0;
            }

            if (k < b1 + b0) {
                if (k < b1) y = 1;
                else y = 0;
            } else {
                int t = k - (b1 + b0);
                if (t < a1) y = 1;
                else y = 0;
            }

            if (x != y) return x > y;
        }
        return false;
    }

    int maxValue(vector<int>& nums1, vector<int>& nums0) {
        vector<pair<int,int>> segs;
        int n = nums1.size();

        for (int i = 0; i < n; i++)
            segs.push_back({nums1[i], nums0[i]});

        sort(segs.begin(), segs.end(),
             [&](auto &a, auto &b) {
                 return better(a, b);
             });

        long long res = 0;

        for (auto &p : segs) {
            int ones = p.first, zeros = p.second;

            while (ones--) res = (res * 2 + 1) % MOD;
            while (zeros--) res = (res * 2) % MOD;
        }

        return res;
    }
};
```

**Runtime:** 446ms | **Memory:** 140.3MB