class Solution(object):
    def maximumScore(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        n = len(nums)
        nums2 = nums + nums
        res = 0

        for start in range(n):
            dp = [0] * (n + 1)
            for parts in range(1, k + 1):
                new_dp = [-float('inf')] * (n + 1)
                for i in range(1, n + 1):
                    mx = -float('inf')
                    mn = float('inf')
                    for p in range(i - 1, -1, -1):
                        val = nums2[start + p]
                        mx = max(mx, val)
                        mn = min(mn, val)
                        new_dp[i] = max(new_dp[i], dp[p] + (mx - mn))
                dp = new_dp
            res = max(res, dp[n])
        return res
