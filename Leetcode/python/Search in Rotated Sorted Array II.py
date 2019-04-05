class Solution:
    def search(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        l = len(nums)
        left = 0
        right = l-1

        while left <= right:
            middle = (left+right)//2
            if target == nums[middle]:
                return True
            if nums[middle] == nums[left]:
            	left += 1
            elif nums[left] < nums[middle]:
            	if nums[left] <= target < nums[middle]:
            		right = middle -1
            	else:
            		left = middle + 1
            else:
            	if nums[middle] < target <= nums[right]:
            		left = middle + 1
            	else:
            		right = middle - 1


        return False