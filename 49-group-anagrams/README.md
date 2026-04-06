# 49 - Group Anagrams

**Difficulty:** Medium  
**Problem Link:** [group-anagrams](https://leetcode.com/problems/group-anagrams/)

## Problem Description

Given an array of strings `strs`, group the anagrams together. You can return the answer in any order.

An anagram is a word formed by rearranging the letters of another word.

## Solution Approach

**Hash Map with Sorted String as Key:**
1. For each string, sort its characters to create a key
2. Strings with the same sorted key are anagrams
3. Use unordered_map to group anagrams

## Complexity Analysis

- **Time Complexity:** O(n * k log k) where n = number of strings, k = average length
- **Space Complexity:** O(n * k) for storing all strings

## Accepted Solutions

| File | Runtime | Memory | Language |
|------|---------|--------|----------|
| 2026-04-06 10.24.35 - Accepted - runtime 14ms - memory 26MB.cpp | 14ms | 26MB | C++ |
| 2026-04-10 14.10.51 - Accepted - runtime 28ms - memory 26.2MB.cpp | 28ms | 26.2MB | C++ |

## Best Code Example

```cpp
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;

        for (auto s : strs) {
            string key = s;
            sort(key.begin(), key.end());   
            mp[key].push_back(s);          
        }

        vector<vector<string>> ans;
        for (auto x : mp) {
            ans.push_back(x.second);
        }

        return ans;
    }
};
```