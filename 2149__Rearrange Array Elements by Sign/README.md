# 🚀 LeetCode 2149: Rearrange Array Elements by Sign

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)
![Topics](https://img.shields.io/badge/Topics-Array-blue)
![Acceptance](https://img.shields.io/badge/Acceptance-84.7%25-brightgreen)

---

## ⚡ The Problem

Given an array `nums` with **equal** number of positive and negative integers.

Rearrange the array so that:
- Alternating signs: positive, negative, positive, negative...
- Order within positives and negatives should be preserved

Example:
```
Input:  [3, 1, -2, -5, -4, -1]
Output: [3, -2, 1, -5, -4, -1]
```

---

## 💡 The Solution (C++)

```cpp
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> pos, neg;

        for (int x : nums) {
            if (x > 0) pos.push_back(x);
            else neg.push_back(x);
        }

        vector<int> ans;
        int i = 0;
        while (i < pos.size()) {
            ans.push_back(pos[i]);
            ans.push_back(neg[i]);
            i++;
        }

        return ans;
    }
};
```

### 🔥 How It Works

| Step | Operation |
|------|-----------|
| 1 | Separate positive & negative into two lists |
| 2 | Interleave them: pos[0], neg[0], pos[1], neg[1]... |
| 3 | Return combined array |

**Time Complexity**: O(n)  
**Space Complexity**: O(n)

---

## 🎯 Alternative: In-PlaceO(1) Space

```cpp
vector<int> rearrangeArray(vector<int>& nums) {
    vector<int> ans(nums.size());
    int p = 0, n = 1;
    for (int x : nums) {
        if (x > 0) {
            ans[p] = x;
            p += 2;
        } else {
            ans[n] = x;
            n += 2;
        }
    }
    return ans;
}
```

Even cleaner - place directly in alternating positions!

---

## 📊 Visual Example

```
Input:  [3, 1, -2, -5, -4, -1]
         ↑  ↑   ↑   ↑   ↑   ↑
        pos(pos(neg(neg(neg(neg

Separate:
  pos = [3, 1]
  neg = [-2, -5, -4, -1]

Interleave:
  ans[0] = pos[0] = 3
  ans[1] = neg[0] = -2
  ans[2] = pos[1] = 1
  ans[3] = neg[1] = -5
  ans[4] = neg[2] = -4
  ans[5] = neg[3] = -1

Output: [3, -2, 1, -5, -4, -1] ✓
```

---

## 🏆 Stats

| Metric | Value |
|--------|-------|
| Runtime | 49ms |
| Memory | 42.6 MB |
| Rank | Top 95% |

---

> *"Positive, negative, never indecisive!"* ⚡