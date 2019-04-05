class Solution:
    def findMin(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        left = 0
        right = len(nums)-1

        while left < right:
            middle = (left + right)//2
            if nums[middle] < nums[left]:
                right = middle
            elif nums[middle] > nums[left] and nums[middle] > nums[right]:
                left = middle + 1
            elif nums[middle] > nums[left] and nums[middle] < nums[right]:
                right = middle - 1
            else:
                return min(nums[left], nums[right])
        return  nums[left]