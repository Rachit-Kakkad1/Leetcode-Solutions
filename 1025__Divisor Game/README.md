# 🚀 LeetCode 1025: Divisor Game

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)
![Topics](https://img.shields.io/badge/Topics-Math-blue)
![Acceptance](https://img.shields.io/badge/Acceptance-65.9%25-brightgreen)

---

## ⚡ The Problem

Alice and Bob play a game. Given an integer `N`, Alice moves first, and both play optimally.

- A player chooses `x` where `0 < x < N` and `N % x == 0`
- Replace `N` with `N - x`
- Player who cannot make a move loses

**Determine if Alice wins.**

---

## 💡 The Solution

```cpp
class Solution {
public:
    bool divisorGame(int n) {
        return n % 2 == 0;
    }
};
```

### 🔥 Why This Works

This is a beautiful mathematical problem with a **recursive proof**:

1. **Base Case**: `N = 1` → Alice loses (no valid move)
2. **Inductive Step**:
   - If `N` is **even**: Alice can always subtract an odd divisor to make `N` odd for Bob
   - If `N` is **odd**: All divisors are odd, so Alice makes it even for Bob
3. By induction, all **even** `N` are winning positions!

**Time Complexity**: O(1)  
**Space Complexity**: O(1)

---

## 🎯 Key Insight

| N (Parity) | Alice Wins? |
|-----------|------------|
| Even      | ✅ Yes     |
| Odd       | ❌ No     |

The answer is simply: **`N % 2 == 0`**

---

## 🏆 Stats

| Metric | Value |
|--------|-------|
| Runtime | 0ms |
| Memory | 6.13 MB |
| Rank | Top 100% |

---

> *"Mathematical beauty beats brute force every time."* 💎