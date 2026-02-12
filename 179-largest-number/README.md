# 179. Largest Number

**Difficulty: Medium**

## Problem Description

Given a list of non-negative integers `nums`, arrange them such that they form the largest number. Return the string representation of the largest number.

**Example 1:**
```
Input: nums = [10, 2]
Output: "210"
```

**Example 2:**
```
Input: nums = [3,30,34,5,9]
Output: "9534330"
```

**Constraints:**
* `1 <= nums.length <= 100`
* `0 <= nums[i] <= 10^9`

## Solution Approach

We use a **custom comparator** to sort numbers:
1. For two numbers a and b, compare `str(a) + str(b)` vs `str(b) + str(a)`.
2. If `ab > ba`, then a should come before b.
3. After sorting in descending order, concatenate all strings.
4. Handle edge case: if all numbers are 0, return "0" to avoid leading zeros.

## Complexity Analysis

- **Time Complexity:** O(n log n) where n is the number of elements for sorting.
- **Space Complexity:** O(n) for storing string representations.

## Accepted Solution Files

| File | Language | Runtime | Memory |
|------|----------|----------|--------|
| 2026-02-12 06.10.00 - Accepted - runtime 2ms - memory 55.1MB.js | JavaScript | 2ms | 55.1MB |
| 2026-02-12 06.10.07 - Accepted - runtime 7ms - memory 57.5MB.js | JavaScript | 7ms | 57.5MB |

## Best Code Example

```javascript
function largestNumber(nums) {
    nums.sort((a, b) => ('' + b + a) - ('' + a + b));

    if (nums[0] === 0) return "0";

    return nums.join('');
}
```

The key is the comparator: (`b` + `a`) - (`a` + `b`) ensures proper ordering where larger concatenation comes first.