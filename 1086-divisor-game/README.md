# 1086 - Divisor Game

**Difficulty:** Easy

**Link:** [Divisor Game - LeetCode](https://leetcode.com/problems/divisor-game/)

## Problem Description

Alice and Bob take turns playing a game, with Alice starting first.

Initially, there is a number `n` on the chalkboard. On each player's turn, that player makes a move consisting of:

- Choosing any integer `x` with `0 < x < n` and `n % x == 0`.
- Replacing the number `n` on the chalkboard with `n - x`.

Also, if a player cannot make a move, they lose the game.

Return `true` if and only if Alice wins the game, assuming both players play optimally.

## Example Test Cases

### Example 1:
```
Input: n = 2
Output: true
Explanation: Alice chooses 1, and Bob has no more moves.
```

### Example 2:
```
Input: n = 3
Output: false
Explanation: Alice chooses 1, Bob chooses 1, and Alice has no more moves.
```

## Constraints

- `1 <= n <= 1000`

## Solution Approach

### Algorithm Explanation

This problem has a mathematical pattern:

- Alice wins if n is even
- Alice loses if n is odd

This can be proven by induction:
- Base case: n=1 (odd) - Alice loses
- If n is even, Alice can always make a move leaving an odd n to Bob
- If n is odd, all moves leave an even n to Alice (so Alice loses)

### Step-by-Step Logic

1. Check if n is even
2. Return true if even, false if odd

### Why It Works

- Mathematical proof by induction shows n%2 determines winner
- O(1) solution without any complex computation

## Complexity Analysis

- **Time Complexity:** O(1)
- **Space Complexity:** O(1)

## Accepted Solutions

| File Name | Language | Runtime | Memory |
|-----------|----------|---------|--------|
| 2026-04-10 17.40.57 - Accepted - runtime 0ms - memory 7.5MB.cpp | C++ | 0ms | 7.5MB |

## Code Example (Best Solution - C++)

```cpp
class Solution {
public:
    bool divisorGame(int n) {
        return n%2 == 0;
    }
};
```

**Runtime:** 0ms | **Memory:** 7.5MB