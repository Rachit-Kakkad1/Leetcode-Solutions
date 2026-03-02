# 1658 - Minimum Swaps to Arrange a Binary Grid

**Difficulty:** Medium

**Link:** [Minimum Swaps to Arrange a Binary Grid - LeetCode](https://leetcode.com/problems/minimum-swaps-to-arrange-a-binary-grid/)

## Problem Description

Given an `n x n` binary `grid`, in one step you can choose two **adjacent rows** of the grid and swap them.

A grid is said to be **valid** if all the cells above the main diagonal are **zeros**.

Return *the minimum number of steps* needed to make the grid valid, or **-1** if the grid cannot be valid.

## Example Test Cases

### Example 1:
```
Input: grid = [[0,0,1],[1,1,0],[1,0,0]]
Output: 3
```

### Example 2:
```
Input: grid = [[0,1,1,0],[0,1,1,0],[0,1,1,0],[0,1,1,0]]
Output: -1
Explanation: All rows are similar, swaps have no effect on the grid.
```

### Example 3:
```
Input: grid = [[1,0,0],[1,1,0],[1,1,1]]
Output: 0
```

## Constraints

- `n == grid.length` `== grid[i].length`
- `1 <= n <= 200`
- `grid[i][j]` is either `0` or `1`

## Solution Approach

### Algorithm Explanation

Count trailing zeros in each row, then greedily arrange them:

1. For each row, count consecutive zeros from the right
2. Row i needs at least (n-1-i) trailing zeros to be valid
3. Find a row from current position that meets the requirement
4. Swap rows upward to position, counting swaps

### Step-by-Step Logic

1. For each row i, count trailing zeros and store in array
2. For position i from 0 to n-1:
   - Need = n - 1 - i (required zeros for this row)
   - Find j >= i where zeros[j] >= need
   - If not found, return -1
   - Swap rows j down to i, counting swaps
3. Return total swaps

### Why It Works

- Greedy approach works because we only need to ensure each row has enough trailing zeros
- Moving rows up preserves the relative order of other rows
- This is optimal as each row's requirement is independent

## Complexity Analysis

- **Time Complexity:** O(n²) - Scanning and swapping
- **Space Complexity:** O(n) - Storing trailing zero counts

## Accepted Solutions

| File Name | Language | Runtime | Memory |
|-----------|----------|---------|--------|
| 2026-03-02 13.30.23 - Accepted - runtime 3ms - memory 59.5MB.js | JavaScript | 3ms | 59.5MB |

## Code Example (Best Solution - JavaScript)

```javascript
/**
 * @param {number[][]} grid
 * @return {number}
 */
function minSwaps(grid) {

    let n = grid.length
    let zeros = []

    for (let i = 0; i < n; i++) {

        let count = 0

        for (let j = n - 1; j >= 0; j--) {
            if (grid[i][j] === 0) {
                count++
            } else {
                break
            }
        }

        zeros.push(count)
    }

    let swaps = 0

    for (let i = 0; i < n; i++) {

        let need = n - 1 - i

        let j = i

        while (j < n && zeros[j] < need) {
            j++
        }

        if (j === n){ 
            return -1
        }

        while (j > i) {
            let temp = zeros[j]
            zeros[j] = zeros[j - 1]
            zeros[j - 1] = temp

            swaps++
            j--
        }
    }

    return swaps
}
```

**Runtime:** 3ms | **Memory:** 59.5MB