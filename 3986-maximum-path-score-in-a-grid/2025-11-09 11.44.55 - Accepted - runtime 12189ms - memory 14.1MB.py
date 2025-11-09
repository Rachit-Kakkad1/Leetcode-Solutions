class Solution(object):
    def maxPathScore(self, grid, k):
        m, n = len(grid), len(grid[0])
        def cost(v):
            return 0 if v == 0 else 1
        def score(v):
            return v
        dp = [[-1] * (k + 1) for _ in range(n)]
        dp[0][0] = 0
        cc, ss = cost(grid[0][0]), score(grid[0][0])
        if cc <= k:
            dp[0][cc] = ss
        for j in range(1, n):
            val = grid[0][j]
            cc, ss = cost(val), score(val)
            for used in range(cc, k + 1):
                if dp[j - 1][used - cc] != -1:
                    dp[j][used] = max(dp[j][used], dp[j - 1][used - cc] + ss)
        for i in range(1, m):
            new_dp = [[-1] * (k + 1) for _ in range(n)]
            for j in range(n):
                val = grid[i][j]
                cc, ss = cost(val), score(val)
                for used in range(cc, k + 1):
                    best_prev = -1
                    if dp[j][used - cc] != -1:
                        best_prev = max(best_prev, dp[j][used - cc])
                    if j > 0 and new_dp[j - 1][used - cc] != -1:
                        best_prev = max(best_prev, new_dp[j - 1][used - cc])
                    if best_prev != -1:
                        new_dp[j][used] = max(new_dp[j][used], best_prev + ss)
            dp = new_dp
        ans = max(dp[n - 1])
        return ans if ans != -1 else -1
