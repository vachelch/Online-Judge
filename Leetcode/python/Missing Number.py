class Solution:
    def missingNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        dic = set(nums)
        l = len(nums)
        for i in range(l+1):
            if i not in dic:
                return i

