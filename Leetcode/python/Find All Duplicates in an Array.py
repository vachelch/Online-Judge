class Solution:
    def findDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        l = len(nums)
        if l<2: return []

        nums.sort()
        res = []
        for i in range(1,l):
        	if nums[i] == nums[i-1]:
        		res.append(nums[i])
        return res