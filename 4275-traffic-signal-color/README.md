# 4275 - Traffic Signal Color

**Difficulty:** Easy

**Link:** [Traffic Signal Color - LeetCode](https://leetcode.com/problems/traffic-signal-color/)

## Problem Description

You are given an integer `timer` representing the remaining time (in seconds) on a traffic signal.

The signal follows these rules:

- If `timer == 0`, the signal is `"Green"`
- If `timer == 30`, the signal is `"Orange"`
- If `30 < timer <= 90`, the signal is `"Red"`

Return the current state of the signal. If none of the above conditions are met, return `"Invalid"`.

## Example Test Cases

### Example 1:
```
Input: timer = 60
Output: "Red"
Explanation: 30 < 60 <= 90
```

### Example 2:
```
Input: timer = 5
Output: "Invalid"
```

## Constraints

- `0 <= timer <= 1000`

## Solution Approach

### Algorithm Explanation

Simple conditional checks:

1. Check for Green (timer == 0)
2. Check for Orange (timer == 30)
3. Check for Red (30 < timer <= 90)
4. Otherwise return "Invalid"

## Complexity Analysis

- **Time Complexity:** O(1)
- **Space Complexity:** O(1)

## Accepted Solutions

| File Name | Language | Runtime | Memory |
|----------|----------|---------|--------|
| 2026-04-11 20.27.37 - Accepted - runtime 0ms - memory 7.8MB.cpp | C++ | 0ms | 7.8MB |

## Code Example (C++)

```cpp
class Solution {
public:
    string trafficSignal(int timer) {
        if (timer == 0) return "Green";
        else if (timer == 30) return "Orange";
        else if (timer > 30 && timer <= 90) return "Red";
        else return "Invalid";
    }
};
```

**Runtime:** 0ms | **Memory:** 7.8MB