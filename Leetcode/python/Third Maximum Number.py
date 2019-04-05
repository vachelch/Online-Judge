class Solution:
    def thirdMax(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        nums_set = set(nums)
        l = len(nums_set)
        if l < 3: return max(nums_set)

        nums_set.remove(max(nums_set))
        nums_set.remove(max(nums_set))
        return max(nums_set)

