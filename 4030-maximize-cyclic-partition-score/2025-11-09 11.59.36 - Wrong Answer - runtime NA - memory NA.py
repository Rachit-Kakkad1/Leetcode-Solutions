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
        
        nums2 = nums + nums
        NEG = -10**15
        res = 0

       
        for start in range(n):
            arr = nums2[start:start+n]
            dp = [0] + [NEG] * n

           
            for _ in range(k):
                new_dp = [0] + [NEG] * n
                max_stack, min_stack = [], []
                j = 0
                for i in range(n):
                  
                    while max_stack and arr[max_stack[-1]] <= arr[i]:
                        max_stack.pop()
                    max_stack.append(i)

                    while min_stack and arr[min_stack[-1]] >= arr[i]:
                        min_stack.pop()
                    min_stack.append(i)

                    mx = arr[max_stack[0]]
                    mn = arr[min_stack[0]]

                    best = NEG
                    for j2 in range(i + 1):
                       
                        while max_stack and max_stack[0] < j2:
                            max_stack.pop(0)
                            mx = arr[max_stack[0]] if max_stack else -10**15
                        while min_stack and min_stack[0] < j2:
                            min_stack.pop(0)
                            mn = arr[min_stack[0]] if min_stack else 10**15
                        if dp[j2] != NEG:
                            best = max(best, dp[j2] + (mx - mn))
                    new_dp[i + 1] = best
                dp = new_dp
            res = max(res, max(dp))
        return res
