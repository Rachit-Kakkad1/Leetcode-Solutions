class Solution(object):
    def maximumScore(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        n = len(nums)
        if n == 1:
            return 0

        diffs = []
        for i in range(n):
            nxt = (i + 1) % n
            diffs.append(abs(nums[nxt] - nums[i]))

        # Sort differences descending
        diffs.sort(reverse=True)

        # Choose k - 1 largest cuts
        return sum(diffs[:k - 1])
