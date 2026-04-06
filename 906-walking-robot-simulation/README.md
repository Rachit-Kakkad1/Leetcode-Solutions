# 906 - Walking Robot Simulation

**Difficulty:** Medium

**Link:** [Walking Robot Simulation - LeetCode](https://leetcode.com/problems/walking-robot-simulation/)

## Problem Description

A robot on an infinite XY-plane starts at point `(0, 0)` facing north. The robot receives an array of integers `commands`, which represents a sequence of moves that it needs to execute. There are only three possible types of instructions the robot can receive:

- `-2`: Turn left `90` degrees.
- `-1`: Turn right `90` degrees.
- `1 <= k <= 9`: Move forward `k` units, one unit at a time.

Some of the grid squares are `obstacles`. The i-th obstacle is at grid point `obstacles[i] = (x_i, y_i)`. If the robot runs into an obstacle, it will stay in its current location and move onto the next command.

Return the **maximum squared Euclidean distance** that the robot reaches at any point in its path.

## Example Test Cases

### Example 1:
```
Input: commands = [4,-1,3], obstacles = []
Output: 25
```

### Example 2:
```
Input: commands = [4,-1,4,-2,4], obstacles = [[2,4]]
Output: 65
```

### Example 3:
```
Input: commands = [6,-1,-1,6], obstacles = [[0,0]]
Output: 36
```

## Constraints

- `1 <= commands.length <= 10^4`
- `commands[i]` is either `-2`, `-1`, or an integer in the range `[1, 9]`.
- `0 <= obstacles.length <= 10^4`
- `-3 * 10^4 <= x_i, y_i <= 3 * 10^4`

## Solution Approach

### Algorithm Explanation

Use a hash set for O(1) obstacle lookup and simulate robot movement:

1. Store obstacles in a hash set with encoded coordinates
2. Process each command:
   - -2: turn left (direction - 1)
   - -1: turn right (direction + 1)
   - k: move forward k steps, checking each step against obstacles
3. Track maximum squared distance (x² + y²)

### Step-by-Step Logic

1. Encode obstacle coordinates into a 64-bit integer for hash set
2. Define direction vectors: [0,1], [1,0], [0,-1], [-1,0]
3. Process each command:
   - For movement commands, step one at a time
   - Check if next position is in obstacle set
   - If blocked, stop moving in that command
   - Update max distance after each successful step

### Why It Works

- Hash set provides O(1) obstacle lookup
- Step-by-step movement catches obstacles at each position
- Maximum distance tracked throughout simulation

## Complexity Analysis

- **Time Complexity:** O(c + o) where c = total steps moved
- **Space Complexity:** O(o) for obstacle set

## Accepted Solutions

| File Name | Language | Runtime | Memory |
|-----------|----------|---------|--------|
| 2026-04-06 15.14.53 - Accepted - runtime 13ms - memory 36.8MB.cpp | C++ | 13ms | 36.8MB |

## Code Example (Best Solution - C++)

```cpp
class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_set<long long> obs;

      
        for (auto& o : obstacles) {
            long long key = ((long long)o[0] << 32) | (o[1] & 0xffffffff);
            obs.insert(key);
        }

        vector<pair<int,int>> dir = {
            {0,1}, {1,0}, {0,-1}, {-1,0}
        };

        int d = 0; 
        int x = 0, y = 0;
        int maxDist = 0;

        for (int cmd : commands) {
            if (cmd == -1) {
                d = (d + 1) % 4; 
            } 
            else if (cmd == -2) {
                d = (d + 3) % 4; 
            } 
            else {
                for (int i = 0; i < cmd; i++) {
                    int nx = x + dir[d].first;
                    int ny = y + dir[d].second;

                    long long key = ((long long)nx << 32) | (ny & 0xffffffff);

                    if (obs.count(key)) break;

                    x = nx;
                    y = ny;

                    maxDist = max(maxDist, x*x + y*y);
                }
            }
        }

        return maxDist;
    }
};
```

**Runtime:** 13ms | **Memory:** 36.8MB