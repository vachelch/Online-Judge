class Solution:
    def findLengthOfLCIS(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        count = 0
        max_count = 0
        max_ = -2000000000
        for i, item in enumerate(nums):
            if item > max_:
                count += 1
                max_ = item
                
                if max_count < count:
                    max_count = count
            else:
                count = 1
                max_ = item
        
        return max_count