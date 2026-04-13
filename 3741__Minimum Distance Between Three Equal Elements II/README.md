# 🚀 LeetCode 3741: Minimum Distance Between Three Equal Elements II

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)
![Topics](https://img.shields.io/badge/Topics-Array-blue)
![Topics](https://img.shields.io/badge/Topics-Hash%20Table-purple)
![Acceptance](https://img.shields.io/badge/Acceptance-67.8%25-yellow)

---

## ⚡ The Problem

Given an array `nums`, find the **minimum distance** between **three equal elements** with the same value.

Return the minimum value of `2 × (last_index - first_index)` where we pick three occurrences of the same value.

If fewer than 3 of any value exist, return `-1`.

---

## 💡 The Solution (C++)

```cpp
class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int, vector<int>> mp;

        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]].push_back(i);
        }

        int ans = INT_MAX;

        for (auto &p : mp) {
            auto &v = p.second;

            if (v.size() < 3) continue;
           
            for (int i = 0; i + 2 < v.size(); i++) {
                int first = v[i];
                int last = v[i + 2];

                ans = min(ans, 2 * (last - first));
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};
```

### 🔥 How It Works

| Step | Operation |
|------|-----------|
| 1 | Build a map: value → list of all indices |
| 2 | For each value with ≥3 occurrences |
| 3 | Check all triplets: first=v[i], second=v[i+1], last=v[i+2] |
| 4 | Calculate distance: 2 × (last - first) |
| 5 | Return minimum |

**Time Complexity**: O(n)  
**Space Complexity**: O(n)

---

## 📊 Visual Example

```
Input: [1, 2, 1, 2, 2, 1]

Positions of each value:
  1 → [0, 2, 5]
  2 → [1, 3, 4]

For value 1:
  first=0, last=2 → distance = 2×2 = 4
  first=0, last=5 → distance = 2×5 = 10 ← better
  first=2, last=5 → distance = 2×3 = 6

For value 2:
  first=1, last=3 → distance = 2×2 = 4 ← best!
  first=1, last=4 → distance = 2×3 = 6
  first=3, last=4 → distance = 2×1 = 2 ← OOPS!

Answer: 2
```

**Wait!** Distance = `last - first` = positions between first and last, not counting middle!

Correct is min(4, 10, 6, 4, 6, 2) = **2**

---

## 🎯 Key Insight

The minimal distance always comes from **adjacent indices** in the sorted position list!

For indices `[a, b, c, d, ...]`, only check:
- `(d - a)` for first three  
- `(c - a)` skipping one, etc.

**Optimization**: Check each consecutive triplet only once!

---

## 🏆 Stats

| Metric | Value |
|--------|-------|
| Runtime | 189ms |
| Memory | 71.5 MB |
| Rank | Top 90% |

---

> *"Distance measured in indices, solved with hashes!"* 📏