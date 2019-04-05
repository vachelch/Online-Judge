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
                return middle
            if middle == left:
            	if left == right: return -1
            	else:
            		if nums[right] == target: return right
            		else: return -1
            if nums[left] < nums[middle]:
            	if nums[left] <= target < nums[middle]:
            		right = middle -1
            	else:
            		left = middle + 1
            else:
            	if nums[middle] < target <= nums[right]:
            		left = middle + 1
            	else:
            		right = middle - 1


        return -1


nums = [5, 1, 3]
target = 3
print(Solution().search(nums, target))