# 909 - Stone Game

**Difficulty:** Medium

**Link:** [Stone Game - LeetCode](https://leetcode.com/problems/stone-game/)

## Problem Description

Alice and Bob play a game with piles of stones. There are an **even** number of piles arranged in a row, and each pile has a **positive** integer number of stones `piles[i]`.

The objective of the game is to end with the most stones. The **total** number of stones across all the piles is **odd**, so there are no ties.

Alice and Bob take turns, with **Alice starting first**. Each turn, a player takes the entire pile of stones either from the **beginning** or from the **end** of the row. This continues until there are no more piles left, at which point the person with the **most stones wins**.

Assuming Alice and Bob play optimally, return `true` *if Alice wins the game, or* `false` *if Bob wins*.

## Example Test Cases

### Example 1:
```
Input: piles = [5,3,4,5]
Output: true
Explanation: 
Alice starts first, and can only take the first 5 or the last 5.
Say she takes the first 5, so that the row becomes [3, 4, 5].
If Bob takes 3, then the board is [4, 5], and Alice takes 5 to win with 10 points.
If Bob takes the last 5, then the board is [3, 4], and Alice takes 4 to win with 9 points.
This demonstrated that taking the first 5 was a winning move for Alice, so we return true.
```

### Example 2:
```
Input: piles = [3,7,2,3]
Output: true
```

## Constraints

- `2 <= piles.length <= 500`
- `piles.length` is **even**.
- `1 <= piles[i] <= 500`
- `sum(piles[i])` is **odd**.

## Solution Approach

### Algorithm Explanation

This is a well-known game theory problem. Alice can always win with optimal play:

1. Since there are an even number of piles and total stones are odd, no tie is possible
2. Alice can always force a win by picking either the first or last pile
3. The key insight: Alice can choose the parity (odd/even indexed) of piles she collects

### Why It Works

- Alice can always choose to take from either the odd or even indexed piles
- By selecting the side with more total stones, Alice guarantees at least as many stones as Bob
- Since total is odd, Alice will have strictly more

## Complexity Analysis

- **Time Complexity:** O(1) - Always return true
- **Space Complexity:** O(1)

## Accepted Solutions

| File Name | Language | Runtime | Memory |
|-----------|----------|---------|--------|
| 2026-03-07 17.13.24 - Accepted - runtime 0ms - memory 53.9MB.js | JavaScript | 0ms | 53.9MB |

## Code Example (Best Solution - JavaScript)

```javascript
/**
 * @param {number[]} piles
 * @return {boolean}
 */
var stoneGame = function(piles) {
  return true;  
};
```

**Runtime:** 0ms | **Memory:** 53.9MB