class Solution:
    def intersection(self, nums1, nums2):
        if len(nums1) > len(nums2):
            nums1, nums2 = nums2, nums1

        set1 = set(nums1)
        return list({x for x in nums2 if x in set1})
