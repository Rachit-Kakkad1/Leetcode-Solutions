# 2178 - Walking Robot Simulation II

**Difficulty:** Medium  
**Problem Link:** [walking-robot-simulation-ii](https://leetcode.com/problems/walking-robot-simulation-ii/)

## Problem Description

A `width x height` grid with bottom-left cell at (0, 0) and top-right at (width-1, height-1). A robot starts at (0, 0) facing East. Each step:
1. Try to move forward one cell
2. If out of bounds, turn 90° counterclockwise and retry

Implement Robot class with step(num), getPos(), and getDir() methods.

## Solution Approach

**Simulation with Position Tracking:**
1. Track current position and direction
2. For each step, attempt to move forward
3. If blocked, turn left and try again
4. Use direction array and boundary checks

## Complexity Analysis

- **Time Complexity:** O(total steps) - depends on total calls to step()
- **Space Complexity:** O(1)

## Accepted Solutions

No accepted solutions currently available in this folder (attempts resulted in Wrong Answers).

## Best Code Example

No accepted solution available yet.