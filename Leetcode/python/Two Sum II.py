class Solution:
    def twoSum(self, numbers, target):
        """
        :type numbers: List[int]
        :type target: int
        :rtype: List[int]
        """
        dic = {}
        
        for i, item in enumerate(numbers):
            if (target - item) in dic:
                return [dic[target - item], i+1]
            elif item not in dic:
                dic[item] = i+1