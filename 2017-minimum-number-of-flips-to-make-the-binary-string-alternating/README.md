# 2017 - Minimum Number of Flips to Make the Binary String Alternating

**Difficulty:** Medium  
**Problem Link:** [minimum-number-of-flips-to-make-the-binary-string-alternating](https://leetcode.com/problems/minimum-number-of-flips-to-make-the-binary-string-alternating/)

## Problem Description

You are given a binary string `s`. You are allowed to perform two types of operations in any sequence:

1. **Type-1 (Rotate):** Remove the first character and append it to the end.
2. **Type-2 (Flip):** Flip any character's value (0 → 1 or 1 → 0).

Return the minimum number of Type-2 operations needed to make `s` alternating (no two adjacent characters are equal).

## Solution Approach

**Sliding Window Approach:**
1. Double the string to handle rotations virtually
2. Use two target alternating patterns: "010101..." and "101010..."
3. Use sliding window of size n to find minimum flips for any rotation
4. Count mismatches for each pattern and take the minimum

## Complexity Analysis

- **Time Complexity:** O(n) where n = length of string
- **Space Complexity:** O(n) for the doubled string

## Accepted Solutions

| File | Runtime | Memory | Language |
|------|---------|--------|----------|
| 2026-03-07 15.40.51 - Accepted - runtime 24ms - memory 59.9MB.js | 24ms | 59.9MB | JavaScript |

## Best Code Example

```javascript
function minFlips(s) {
    let n = s.length;
    let t = s + s;

    let alt1 = 0; 
    let alt2 = 0; 

    let left = 0;
    let ans = n;

    for (let right = 0; right < 2 * n; right++) {
        if (t[right] !== (right % 2 === 0 ? '0' : '1')) alt1++;
        if (t[right] !== (right % 2 === 0 ? '1' : '0')) alt2++;

        if (right - left + 1 > n) {
            if (t[left] !== (left % 2 === 0 ? '0' : '1')) alt1--;
            if (t[left] !== (left % 2 === 0 ? '1' : '0')) alt2--;
            left++;
        }

        if (right - left + 1 === n) {
            ans = Math.min(ans, alt1, alt2);
        }
    }

    return ans;
}
```