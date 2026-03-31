# 3770 - Lexicographically Smallest Generated String

**Difficulty:** Hard

**Link:** [Lexicographically Smallest Generated String - LeetCode](https://leetcode.com/problems/lexicographically-smallest-generated-string/)

## Problem Description

You are given two strings, `str1` and `str2`, of lengths `n` and `m`, respectively.

A string `word` of length `n + m - 1` is defined to be **generated** by `str1` and `str2` if it satisfies the following conditions for **each** index `0 <= i <= n - 1`:

- If `str1[i] == 'T'`, the substring of `word` with size `m` starting at index `i` is **equal** to `str2`, i.e., `word[i..(i + m - 1)] == str2`.
- If `str1[i] == 'F'`, the substring of `word` with size `m` starting at index `i` is **not equal** to `str2`, i.e., `word[i..(i + m - 1)] != str2`.

Return the **lexicographically smallest** possible string that can be **generated** by `str1` and `str2`. If no string can be generated, return an empty string `""`.

## Example Test Cases

### Example 1:
```
Input: str1 = "TFTF", str2 = "ab"
Output: "ababa"
Explanation:
- Index 0: 'T' → substring "ab" == "ab" ✓
- Index 1: 'F' → substring "ba" != "ab" ✓
- Index 2: 'T' → substring "ab" == "ab" ✓
- Index 3: 'F' → substring "ba" != "ab" ✓
```

### Example 2:
```
Input: str1 = "TFTF", str2 = "abc"
Output: ""
Explanation: No string satisfies the conditions.
```

### Example 3:
```
Input: str1 = "F", str2 = "d"
Output: "a"
```

## Constraints

- `1 <= n == str1.length <= 10^4`
- `1 <= m == str2.length <= 500`
- `str1` consists only of 'T' or 'F'.
- `str2` consists only of lowercase English characters.

## Solution Approach

### Algorithm Explanation

The solution uses a greedy approach with backtracking:

1. **Phase 1 - Handle T positions:** Place `str2` at all positions where `str1[i] == 'T'`. If conflicts arise, return empty string.

2. **Phase 2 - Handle F positions:** Check if any 'F' positions are fully fixed and equal to `str2` - if so, return empty string.

3. **Phase 3 - Fill remaining positions:** Greedily fill each '?' with the smallest character ('a' to 'z') that maintains valid constraints. For each position, check all affected substrings to ensure:
   - 'T' positions still match `str2`
   - 'F' positions still differ from `str2`

### Step-by-Step Logic

1. Create result string of length `n + m - 1` initialized with '?'
2. For each index where `str1[i] == 'T'`, copy `str2` into the result at position `i`
3. Check all 'F' positions for conflicts
4. For each remaining '?' position:
   - Try characters 'a' to 'z' in order
   - Verify all constraints still satisfied
   - Use first valid character

### Why It Works

- The greedy approach works because choosing the smallest valid character at each position leads to the lexicographically smallest result
- By checking constraints after each placement, we backtrack immediately if invalid
- The algorithm explores at most 26 options per position

## Complexity Analysis

- **Time Complexity:** O(n × m × 26) worst case, approximately O(n × m × alphabet)
- **Space Complexity:** O(n + m) for the result string

## Accepted Solutions

| File Name | Language | Runtime | Memory |
|----------|----------|---------|--------|
| 2026-03-31 23.31.18 - Accepted - runtime 176ms - memory 10.8MB.cpp | C++ | 176ms | 10.8MB |

## Code Example (Best Solution - C++)

```cpp
class Solution {
public:
    string generateString(string str1, string str2) {
        int n = str1.size(), m = str2.size();
        string word(n + m - 1, '?');

        // Phase 1: Handle T positions
        for (int i = 0; i < n; i++) {
            if (str1[i] == 'T') {
                for (int j = 0; j < m; j++) {
                    if (word[i + j] == '?' || word[i + j] == str2[j]) {
                        word[i + j] = str2[j];
                    } else {
                        return "";
                    }
                }
            }
        }

        // Phase 2: Check F positions
        for (int i = 0; i < n; i++) {
            if (str1[i] == 'F') {
                bool allFixed = true, match = true;
                for (int j = 0; j < m; j++) {
                    if (word[i + j] == '?') allFixed = false;
                    if (word[i + j] != str2[j]) match = false;
                }
                if (allFixed && match) return "";
            }
        }

        // Phase 3: Fill remaining positions greedily
        for (int i = 0; i < word.size(); i++) {
            if (word[i] == '?') {
                for (char c = 'a'; c <= 'z'; c++) {
                    word[i] = c;
                    bool ok = true;

                    for (int start = max(0, i - m + 1); start <= min(i, n - 1); start++) {
                        bool match = true;
                        for (int j = 0; j < m; j++) {
                            if (word[start + j] != str2[j]) {
                                match = false;
                                break;
                            }
                        }
                        if (str1[start] == 'T' && !match) ok = false;
                        if (str1[start] == 'F' && match) ok = false;
                        if (!ok) break;
                    }

                    if (ok) break;
                }
                if (word[i] == '?') return "";
            }
        }

        return word;
    }
};
```

**Runtime:** 176ms | **Memory:** 10.8MB