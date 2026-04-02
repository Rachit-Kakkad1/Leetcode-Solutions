# 1939 - Queries on Number of Points Inside a Circle

**Difficulty:** Medium

**Link:** [Queries on Number of Points Inside a Circle - LeetCode](https://leetcode.com/problems/queries-on-number-of-points-inside-a-circle/)

## Problem Description

You are given an array `points` where `points[i] = [x_i, y_i]` is the coordinates of the i-th point on a 2D plane. Multiple points can have the **same** coordinates.

You are also given an array `queries` where `queries[j] = [x_j, y_j, r_j]` describes a circle centered at `(x_j, y_j)` with a radius of `r_j`.

For each query `queries[j]`, compute the number of points **inside** the j-th circle. Points **on the border** of the circle are considered **inside**.

Return *an array* `answer`, *where* `answer[j]` *is the answer to the* j-th *query*.

## Example Test Cases

### Example 1:
```
Input: points = [[1,3],[3,3],[5,3],[2,2]], queries = [[2,3,1],[4,3,1],[1,1,2]]
Output: [3,2,2]
```

### Example 2:
```
Input: points = [[1,1],[2,2],[3,3],[4,4],[5,5]], queries = [[1,2,2],[2,2,2],[4,3,2],[4,3,3]]
Output: [2,3,2,4]
```

## Constraints

- `1 <= points.length <= 500`
- `points[i].length == 2`
- `0 <= x_i, y_i <= 500`
- `1 <= queries.length <= 500`
- `queries[j].length == 3`
- `0 <= x_j, y_j <= 500`
- `1 <= r_j <= 500`
- All coordinates are integers.

## Solution Approach

### Algorithm Explanation

Brute force works well given constraints (n <= 500):

1. For each query, check all points
2. Use distance formula: point is inside if (dx² + dy²) <= r²
3. Avoid floating point by comparing squared distances

### Step-by-Step Logic

1. Initialize result array
2. For each query [cx, cy, r]:
   - Compute r² once
   - For each point [px, py], compute dx = px - cx, dy = py - cy
   - If dx² + dy² <= r², increment count
3. Push count to result
4. Return result array

### Why It Works

- Distance comparison with squared values avoids floating point precision issues
- Border points are included because we use <=
- O(p * q) time works for p, q <= 500 (max 250,000 operations)

## Complexity Analysis

- **Time Complexity:** O(p * q) - For each query, check all points
- **Space Complexity:** O(q) - Result array

## Accepted Solutions

| File Name | Language | Runtime | Memory |
|-----------|----------|---------|--------|
| 2026-04-02 16.09.31 - Accepted - runtime 346ms - memory 12.5MB.py | Python | 346ms | 12.5MB |
| 2026-04-02 16.14.31 - Accepted - runtime 12ms - memory 20.3MB.cpp | C++ | 12ms | 20.3MB |

## Code Example (Best Solution - C++)

```cpp
class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        vector<int> rt;
        
        for (auto &q : queries) {
            int cx = q[0], cy = q[1], r = q[2];
            int r2 = r * r;
            int ct = 0;
            
            for (auto &p : points) {
                int dx = p[0] - cx;
                int dy = p[1] - cy;
                
                if (dx * dx + dy * dy <= r2) {
                    ct++;
                }
            }
            
            rt.push_back(ct);
        }
        
        return rt;
    }
};
```

**Runtime:** 12ms | **Memory:** 20.3MB