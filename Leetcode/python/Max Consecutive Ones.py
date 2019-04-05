class Solution:
    def findMaxConsecutiveOnes(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        l = len(nums)
        max_count = count = 0
        for i in range(l):
        	if nums[i] == 0:
        		count = 0
        	else:
        		count += 1
        		max_count = max(max_count, count)

        return max_count
