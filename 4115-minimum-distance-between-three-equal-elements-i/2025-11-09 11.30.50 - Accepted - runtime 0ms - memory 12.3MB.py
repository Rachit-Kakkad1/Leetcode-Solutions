class Solution(object):
    def minimumDistance(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        
        from collections import defaultdict

        index_map = defaultdict(list)

       
        for i, num in enumerate(nums):
            index_map[num].append(i)

        min_dist = float('inf')
        found = False

       
        for num, indices in index_map.items():
            if len(indices) < 3:
                continue

            
            for i in range(len(indices) - 2):
                dist = 2 * (indices[i + 2] - indices[i])
                min_dist = min(min_dist, dist)
                found = True

       
        return min_dist if found else -1