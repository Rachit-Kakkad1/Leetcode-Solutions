# 830 - Largest Triangle Area

**Difficulty:** Easy

**Link:** [Largest Triangle Area - LeetCode](https://leetcode.com/problems/largest-triangle-area/)

## Problem Description

Given an array of points on the **X-Y** plane `points` where `points[i] = [x_i, y_i]`, return *the area of the largest triangle that can be formed by any three different points*. Answers within `10^-5` of the actual answer will be accepted.

## Example Test Cases

### Example 1:
```
Input: points = [[0,0],[0,1],[1,0],[0,2],[2,0]]
Output: 2.00000
Explanation: The five points are shown in the above figure. The red triangle is the largest.
```

### Example 2:
```
Input: points = [[1,0],[0,0],[0,1]]
Output: 0.50000
```

## Constraints

- `3 <= points.length <= 50`
- `-50 <= x_i, y_i <= 50`
- All the given points are **unique**.

## Solution Approach

### Algorithm Explanation

The brute force approach is efficient enough given the constraints (max 50 points):

1. Iterate through all possible combinations of 3 points (triples)
2. Calculate the area of each triangle using the **shoelace formula**
3. Keep track of the maximum area

The shoelace formula for triangle area:
```
Area = |x1(y2 - y3) + x2(y3 - y1) + x3(y1 - y2)| / 2
```

We can compute 2*Area using integer arithmetic to avoid floating-point issues.

### Step-by-Step Logic

1. Initialize `max2 = 0` to store double the area
2. Loop through all combinations of three different points (i, j, k)
3. For each triplet, compute the double area:
   ```
   val = x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)
   val = |val| (absolute value)
   ```
4. Update `max2` if current `val` is larger
5. Return `max2 / 2.0` as the actual area

### Why It Works

- The shoelace formula gives exact area for any triangle
- Since constraints are small (n <= 50), O(n³) = 19600 combinations is manageable
- Using double area avoids floating-point division during intermediate steps

## Complexity Analysis

- **Time Complexity:** O(n³) - Checking all possible triples of points
- **Space Complexity:** O(1) - Only a few variables used

## Accepted Solutions

| File Name | Language | Runtime | Memory |
|-----------|----------|---------|--------|
| 2025-11-23 17.53.12 - Accepted - runtime 70ms - memory 12.5MB.py | Python | 70ms | 12.5MB |
| 2025-11-23 17.53.57 - Accepted - runtime 28ms - memory 12.4MB.py | Python | 28ms | 12.4MB |
| 2025-11-23 17.55.03 - Accepted - runtime 3ms - memory 8.6MB.c | C | 3ms | 8.6MB |
| 2025-11-23 17.56.38 - Accepted - runtime 0ms - memory 8.5MB.c | C | 0ms | 8.5MB |
| 2025-11-23 17.57.48 - Accepted - runtime 10ms - memory 57.9MB.js | JavaScript | 10ms | 57.9MB |
| 2025-11-23 17.58.28 - Accepted - runtime 4ms - memory 54.4MB.js | JavaScript | 4ms | 54.4MB |

## Code Example (Best Solution - C)

```c
double largestTriangleArea(int** points, int pointsSize, int* pointsColSize){
    int max2 = 0;  // store double-area to avoid using double inside loops

    for (int i = 0; i < pointsSize; i++) {
        int x1 = points[i][0], y1 = points[i][1];

        for (int j = i + 1; j < pointsSize; j++) {
            int x2 = points[j][0], y2 = points[j][1];

            for (int k = j + 1; k < pointsSize; k++) {
                int x3 = points[k][0], y3 = points[k][1];

                // Compute 2*Area using integer arithmetic
                int val =
                    x1 * (y2 - y3) +
                    x2 * (y3 - y1) +
                    x3 * (y1 - y2);

                // manual abs avoids call to fabs()
                if (val < 0) val = -val;

                if (val > max2)
                    max2 = val;
            }
        }
    }

    return max2 / 2.0; 
}
```

**Runtime:** 0ms | **Memory:** 8.5MB