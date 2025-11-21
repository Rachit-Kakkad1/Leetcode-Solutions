class Solution(object):
    def containsDuplicate(self, nums):
        seen = set()
        for n in nums:
            if n in seen:
                return True
            seen |= {n}   # faster than seen.add(n) in some environments
        return False
