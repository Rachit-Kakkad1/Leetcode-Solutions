# 2846 - Robot Collisions

**Difficulty:** Hard  
**Problem Link:** [robot-collisions](https://leetcode.com/problems/robot-collisions/)

## Problem Description

There are n robots on a line, each with a position, health, and direction (L or R). All robots move simultaneously at the same speed. When robots collide:
- Robot with lower health is removed
- Surviving robot loses 1 health
- If same health, both are removed

Return final health of surviving robots in original order.

## Solution Approach

**Stack-based Simulation:**
1. Sort robots by position
2. Process left-to-right using a stack
3. For right-moving robots, push to stack
4. For left-moving robots, check collisions with stack (right-moving ones ahead)
5. Handle collision logic: compare healths, decrement or remove
6. At the end, add remaining stack robots to survivors

## Complexity Analysis

- **Time Complexity:** O(n log n) for sorting
- **Space Complexity:** O(n) for stack and tracking survivors

## Accepted Solutions

| File | Runtime | Memory | Language |
|------|---------|--------|----------|
| 2026-04-01 17.34.54 - Accepted - runtime 203ms - memory 41.2MB.py | 203ms | 41.2MB | Python |

## Best Code Example

```python
class Solution:
    def survivedRobotsHealths(self, positions, healths, directions):
        robots = sorted(zip(positions, healths, directions, range(len(positions))))
        
        stack = [] 
        alive = {} 
        
        for pos, h, d, idx in robots:
            if d == 'R':
                stack.append([h, idx])
            else:
                while stack and h > 0:
                    if stack[-1][0] < h:
                        h -= 1
                        stack.pop()
                    elif stack[-1][0] > h:
                        stack[-1][0] -= 1
                        h = 0
                    else:
                        stack.pop()
                        h = 0
                
                if h > 0:
                    alive[idx] = h
        
        
        for h, idx in stack:
            alive[idx] = h
        
        return [alive[i] for i in sorted(alive)]
```