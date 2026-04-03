# 3982 - Maximum Walls Destroyed by Robots

**Difficulty:** Hard

**Link:** [Maximum Walls Destroyed by Robots - LeetCode](https://leetcode.com/problems/maximum-walls-destroyed-by-robots/)

## Problem Description

There is an endless straight line populated with some robots and walls. You are given integer arrays `robots`, `distance`, and `walls`:

- `robots[i]` is the position of the `i-th` robot.
- `distance[i]` is the **maximum** distance the `i-th` robot's bullet can travel.
- `walls[j]` is the position of the `j-th` wall.

Every robot has **one** bullet that can either fire to the left or the right **at most** `distance[i]` meters.

A bullet destroys every wall in its path that lies within its range. Robots are fixed obstacles: if a bullet hits another robot before reaching a wall, it **immediately stops** at that robot and cannot continue.

Return the **maximum** number of **unique** walls that can be destroyed by the robots.

## Example Test Cases

### Example 1:
```
Input: robots = [4], distance = [3], walls = [1,10]
Output: 1
Explanation: Robot fires left covering [1,4], destroys wall at 1
```

### Example 2:
```
Input: robots = [10,2], distance = [5,1], walls = [5,2,7]
Output: 3
Explanation:
- Robot 0 fires left covering [5,10], destroys walls at 5 and 7
- Robot 1 fires left covering [1,2], destroys wall at 2
```

### Example 3:
```
Input: robots = [1,2], distance = [100,1], walls = [10]
Output: 0
Explanation: Robot 0 can reach wall but Robot 1 blocks the path
```

## Constraints

- `1 <= robots.length == distance.length <= 10^5`
- `1 <= walls.length <= 10^5`
- `1 <= robots[i], walls[j] <= 10^9`
- `1 <= distance[i] <= 10^5`

## Solution Approach

### Algorithm Explanation

Dynamic programming with interval counting:

1. Sort robots and walls for efficient processing
2. For each robot, calculate:
   - Walls it can hit if firing left only
   - Walls it can hit if firing right only  
   - Walls already covered by adjacent robots (overlap)
3. Use DP: for each robot, track best choice (left/right) considering previous choices

### Step-by-Step Logic

1. Sort robots by position, calculate reach intervals
2. For each robot, count walls in:
   - Own position
   - Left-only range (excluding overlap with previous robot)
   - Right-only range (excluding overlap with next robot)
   - Overlap region with previous robot
3. DP transition considering firing directions

### Why It Works

- Greedy assignment of directions with DP ensures optimal coverage
- Each robot's choice depends only on previous robot's choice

## Complexity Analysis

- **Time Complexity:** O(n log n + m log m) for sorting + binary searches
- **Space Complexity:** O(n) for DP arrays

## Accepted Solutions

| File Name | Language | Runtime | Memory |
|----------|----------|---------|--------|
| 2026-04-03 22.50.16 - Accepted - runtime 179ms - memory 196.3MB.cpp | C++ | 179ms | 196.3MB |

## Code Example (Best Solution - C++)

```cpp
class Solution {
public:
    int maxWalls(vector<int>& robots, vector<int>& distance, vector<int>& walls) {
        int n = robots.size();
        sort(walls.begin(), walls.end());

        vector<pair<int,int>> rob(n);
        for (int i = 0; i < n; i++) rob[i] = {robots[i], distance[i]};
        sort(rob.begin(), rob.end());

        auto countWalls = [&](int l, int r) -> int {
            if (l > r) return 0;
            int L = lower_bound(walls.begin(), walls.end(), l) - walls.begin();
            int R = upper_bound(walls.begin(), walls.end(), r) - walls.begin() - 1;
            return (L <= R) ? (R - L + 1) : 0;
        };

        vector<int> own(n), Lonly(n), Ronly(n), overlap(n, 0);

        for (int i = 0; i < n; i++) {
            int pos = rob[i].first, d = rob[i].second;

            int leftCap  = (i == 0)   ? pos - d : rob[i-1].first + 1;
            int rightCap = (i == n-1) ? pos + d : rob[i+1].first - 1;

            int L = max(pos - d, leftCap);
            int R = min(pos + d, rightCap);

            own[i] = countWalls(pos, pos);
            Lonly[i] = countWalls(L, pos - 1);
            Ronly[i] = countWalls(pos + 1, R);

            if (i > 0) {
                int prev_pos = rob[i-1].first, prev_d = rob[i-1].second;

                int prev_right_L = prev_pos + 1;
                int prev_right_R = min(prev_pos + prev_d, pos - 1);

                int curr_left_L = max(pos - d, rob[i-1].first + 1);
                int curr_left_R = pos - 1;

                int l = max(prev_right_L, curr_left_L);
                int r = min(prev_right_R, curr_left_R);

                overlap[i] = countWalls(l, r);
            }
        }

        vector<array<int,2>> dp(n);

        dp[0][0] = own[0] + Lonly[0];
        dp[0][1] = own[0] + Ronly[0];

        for (int i = 1; i < n; i++) {
            dp[i][0] = own[i] + Lonly[i] + max(
                dp[i-1][0],
                dp[i-1][1] - overlap[i]
            );

            dp[i][1] = own[i] + Ronly[i] + max(
                dp[i-1][0],
                dp[i-1][1]
            );
        }

        return max(dp[n-1][0], dp[n-1][1]);
    }
};
```

**Runtime:** 179ms | **Memory:** 196.3MB