class Solution:
    def intersection(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: List[int]
        """
        iset1 = set(nums1)
        iset2 = set(nums2)

        res = []
        for num in iset1:
        	if num in iset2: res.append(num)
        return res