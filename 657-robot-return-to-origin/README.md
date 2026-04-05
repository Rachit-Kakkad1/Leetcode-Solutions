# 657 - Robot Return to Origin

**Difficulty:** Easy  
**Problem Link:** [robot-return-to-origin](https://leetcode.com/problems/robot-return-to-origin/)

## Problem Description

There is a robot starting at position (0, 0). Given a sequence of moves ('U', 'D', 'L', 'R'), judge if the robot ends up at (0, 0) after completing all moves.

## Solution Approach

**Coordinate Counting:**
1. Count occurrences of each direction
2. Robot returns to origin if:
   - Up count equals Down count
   - Left count equals Right count

## Complexity Analysis

- **Time Complexity:** O(n)
- **Space Complexity:** O(1)

## Accepted Solutions

| File | Runtime | Memory | Language |
|------|---------|--------|----------|
| 2026-04-05 17.57.49 - Accepted - runtime 3ms - memory 10.5MB.cpp | 3ms | 10.5MB | C++ |
| 2026-04-05 17.59.10 - Accepted - runtime 3ms - memory 10.4MB.cpp | 3ms | 10.4MB | C++ |

## Best Code Example

```cpp
class Solution {
public:
    bool judgeCircle(string moves) {
        return count(moves.begin(), moves.end(), 'U') ==
               count(moves.begin(), moves.end(), 'D') &&
               count(moves.begin(), moves.end(), 'L') ==
               count(moves.begin(), moves.end(), 'R');
    }
};
```