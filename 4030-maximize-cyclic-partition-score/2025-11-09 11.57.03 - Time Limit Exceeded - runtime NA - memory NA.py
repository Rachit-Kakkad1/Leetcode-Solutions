class Solution(object):
    def maximumScore(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        n = len(nums)
        nums2 = nums + nums
        NEG = -10**15
        res = 0

        
        def get_bounds(arr, compare):
            n = len(arr)
            left, right = [0]*n, [0]*n
            stack = []
            for i in range(n):
                while stack and compare(arr[stack[-1]], arr[i]):
                    idx = stack.pop()
                    right[idx] = i
                stack.append(i)
            while stack:
                idx = stack.pop()
                right[idx] = n
            stack = []
            for i in range(n-1, -1, -1):
                while stack and compare(arr[stack[-1]], arr[i]):
                    idx = stack.pop()
                    left[idx] = i
                stack.append(i)
            while stack:
                idx = stack.pop()
                left[idx] = -1
            return left, right

       
        for start in range(n):
            arr = nums2[start:start+n]
            dp = [0] + [-10**15]*n
            for _ in range(k):
                new_dp = [0] + [-10**15]*n
                for i in range(n):
                    mx, mn = arr[i], arr[i]
                    for j in range(i, -1, -1):
                        if arr[j] > mx: mx = arr[j]
                        if arr[j] < mn: mn = arr[j]
                        val = dp[j] + (mx - mn)
                        if val > new_dp[i+1]:
                            new_dp[i+1] = val
                dp = new_dp
            res = max(res, max(dp))
        return res
