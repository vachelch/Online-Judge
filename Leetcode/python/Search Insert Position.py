class Solution:
    def searchInsert(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        l = len(nums)
        for i in range(l):
        	cur = nums[i]
        	if target <= cur :
        		return i
        return l

s = Solution()
nums, target = [1,3,5,6], 0
print(s.searchInsert(nums, target))

