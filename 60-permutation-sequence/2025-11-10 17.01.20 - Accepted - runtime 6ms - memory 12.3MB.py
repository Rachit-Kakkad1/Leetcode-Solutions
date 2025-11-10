class Solution(object):
    def getPermutation(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: str
        """
        import math
        nums = [str(i) for i in range(1, n + 1)]
        k -= 1
        res = ""
        for i in range(n, 0, -1):
            idx = k // math.factorial(i - 1)
            res += nums[idx]
            nums.pop(idx)
            k %= math.factorial(i - 1)
        return res
