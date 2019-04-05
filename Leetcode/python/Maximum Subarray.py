class Solution:
    def maxSubArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        max_ = max(nums)
        if max_ <= 0: return max_
        l = len(nums)

        max_sum = 0
        sub_sum = 0

        for i in range(l):
        	if sub_sum + nums[i] > 0:
        		sub_sum += nums[i]
        		if sub_sum > max_sum:
        			max_sum = sub_sum
        	else:
        		sub_sum = 0
        return max_sum
