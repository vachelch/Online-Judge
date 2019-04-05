class Solution:
    def containsDuplicate(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        dic = set()

        for item in nums:
        	if item in dic:
        		return True
        	else:
        		dic.add(item)

        return False

#best
# class Solution:
#     def containsDuplicate(self, nums):
#         """
#         :type nums: List[int]
#         :rtype: bool
#         """
        
#         return len(nums) != len(set(nums))