class Solution:
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        dic = {}
        
        for i, item in enumerate(nums):
            if (target - item) in dic:
                return [dic[target - item], i]
            elif item not in dic:
                dic[item] = i
