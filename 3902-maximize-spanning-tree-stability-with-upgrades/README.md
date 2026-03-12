# 3902 - Maximize Spanning Tree Stability with Upgrades

**Difficulty:** Hard

**Link:** [Maximize Spanning Tree Stability with Upgrades - LeetCode](https://leetcode.com/problems/maximize-spanning-tree-stability-with-upgrades/)

## Problem Description

You are given an integer `n`, representing `n` nodes numbered from 0 to `n - 1` and a list of `edges`, where `edges[i] = [u_i, v_i, s_i, must_i]`:

- `u_i` and `v_i` indicates an undirected edge between nodes `u_i` and `v_i`.
- `s_i` is the strength of the edge.
- `must_i` is an integer (0 or 1). If `must_i == 1`, the edge **must** be included in the **spanning tree**. These edges **cannot** be **upgraded**.

You are also given an integer `k`, the **maximum** number of upgrades you can perform. Each upgrade **doubles** the strength of an edge, and each eligible edge (with `must_i == 0`) can be upgraded **at most** once.

The **stability** of a spanning tree is defined as the **minimum** strength score among all edges included in it.

Return the **maximum** possible stability of any valid spanning tree. If it is impossible to connect all nodes, return `-1`.

## Example Test Cases

### Example 1:
```
Input: n = 3, edges = [[0,1,2,1],[1,2,3,0]], k = 1
Output: 2
Explanation:
- Edge [0,1] with strength = 2 must be included
- Edge [1,2] is optional and can be upgraded from 3 to 6
- Minimum strength = 2 (maximum possible)
```

### Example 2:
```
Input: n = 3, edges = [[0,1,4,0],[1,2,3,0],[0,2,1,0]], k = 2
Output: 6
Explanation:
- Upgrade [0,1] from 4 to 8, [1,2] from 3 to 6
- Minimum strength = 6
```

### Example 3:
```
Input: n = 3, edges = [[0,1,1,1],[1,2,1,1],[2,0,1,1]], k = 0
Output: -1
Explanation: All edges are mandatory and form a cycle, impossible
```

## Constraints

- `2 <= n <= 10^5`
- `1 <= edges.length <= 10^5`
- `0 <= u_i, v_i < n`
- `1 <= s_i <= 10^5`
- `must_i` is 0 or 1
- `0 <= k <= n`

## Solution Approach

### Algorithm Explanation

The solution uses binary search with Union-Find (DSU):

1. **Binary Search:** Find the maximum possible stability value `x`
2. **Feasibility Check:** For a given `x`, can we build a spanning tree with minimum edge strength >= `x`?
3. **Union-Find:** Use DSU to check connectivity

### Step-by-Step Logic

1. Binary search on stability value from 1 to max_edge_strength × 2
2. For each mid value, check if feasible:
   - Use all mandatory edges with strength >= x
   - Use optional edges with strength >= x (no upgrade needed)
   - Use upgraded optional edges (strength × 2 >= x) if upgrades available
   - If we can connect all n nodes with <= k upgrades, the value is feasible
3. Return the maximum feasible stability, or -1 if impossible

### Why It Works

- Binary search finds the maximum by testing feasibility at each value
- The DSU efficiently tracks connectivity
- The greedy choice of using stronger edges first is optimal

## Complexity Analysis

- **Time Complexity:** O(log(max_s) × (E × α(n))) where α is inverse Ackermann
- **Space Complexity:** O(n) for DSU

## Accepted Solutions

| File Name | Language | Runtime | Memory |
|----------|----------|---------|--------|
| 2026-03-13 01.48.45 - Accepted - runtime 3067ms - memory 65.9MB.py | Python | 3067ms | 65.9MB |

## Code Example (Best Solution - Python)

```python
class DSU:
    def __init__(self, n):
        self.parent = list(range(n))
        self.rank = [0]*n

    def find(self, x):
        if self.parent[x] != x:
            self.parent[x] = self.find(self.parent[x])
        return self.parent[x]

    def union(self, a, b):
        pa, pb = self.find(a), self.find(b)
        if pa == pb:
            return False
        if self.rank[pa] < self.rank[pb]:
            pa, pb = pb, pa
        self.parent[pb] = pa
        if self.rank[pa] == self.rank[pb]:
            self.rank[pa] += 1
        return True


class Solution:
    def maxStability(self, n, edges, k):
        def can(x):
            dsu = DSU(n)
            upgrades = 0
            used = 0

            optional = []

            for u, v, s, must in edges:
                if must == 1:
                    if s < x:
                        return False
                    if not dsu.union(u, v):
                        return False
                    used += 1
                else:
                    optional.append((u, v, s))

            if used == n - 1:
                return True

            zero = []
            one = []

            for u, v, s in optional:
                if s >= x:
                    zero.append((u, v))
                elif s * 2 >= x:
                    one.append((u, v))

            for u, v in zero:
                if dsu.union(u, v):
                    used += 1
                if used == n - 1:
                    return True

            for u, v in one:
                if upgrades == k:
                    break
                if dsu.union(u, v):
                    upgrades += 1
                    used += 1
                if used == n - 1:
                    return True

            return False

        left = 1
        right = max(s for _,_,s,_ in edges) * 2
        ans = -1

        while left <= right:
            mid = (left + right) // 2

            if can(mid):
                ans = mid
                left = mid + 1
            else:
                right = mid - 1

        return ans
```

**Runtime:** 3067ms | **Memory:** 65.9MB