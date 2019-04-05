class Solution:
    def minMoves(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        mn = min(nums)
        sum_ = 0
        l =  len(nums)
        for i in range(l):
        	sum_ += nums[i]

        return sum_ - l*mn