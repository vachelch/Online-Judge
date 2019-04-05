class Solution:
    def majorityElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        dic = {}
        l = len(nums)

        for item in nums:
        	if item not in dic:
        		dic[item] = 1
        	else:
        		dic[item] += 1

        	if dic[item] > l/2:
        		return item

#best
# class Solution:
#     def majorityElement(self, nums):
#         """
#         :type nums: List[int]
#         :rtype: int
#         """
#         x=0
#         nums.sort()
#         return nums[len(nums)//2]