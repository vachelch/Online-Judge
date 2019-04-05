class Solution:
    def productExceptSelf(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        l = len(nums)


        left = [1]
        multi = 1
        for i in range(1, l):
        	multi *= nums[i-1]
        	left.append(multi) 

        right = [1]
        multi = 1
        for i in range(l-2, -1, -1):
        	multi *= nums[i+1]
        	left[i] *= multi

        return left