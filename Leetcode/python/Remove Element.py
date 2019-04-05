def swap(nums, i, next_):
	tmp = nums[next_]
	nums[next_] = nums[i]
	nums[i] = tmp

class Solution:
    def removeElement(self, nums, val):
        """
        :type nums: List[int]
        :type val: int
        :rtype: int
        """
        l = len(nums)

        next_ = 0
        for i in range(l):
        	if nums[i] != val:
        		swap(nums, i, next_)
        		next_ += 1

        return next_

#best
# class Solution:
#     def removeElement(self, nums, val):
#         """
#         :type nums: List[int]
#         :type val: int
#         :rtype: int
#         """
#         i = 0
#         while i < len(nums):
#             if nums[i] == val:
#                 nums.pop(i)
#             else:
#                 i += 1
#         return len(nums)


#second
# class Solution:
#     def removeElement(self, nums, val):
#         i = 0
#         while i < len(nums):
#             if nums[i] == val:
#                 nums[i:i+2]= nums[i+1:i+2]
#             else:
#                 i += 1















