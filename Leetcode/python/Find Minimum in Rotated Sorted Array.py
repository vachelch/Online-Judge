class Solution:
    def findMin(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        left = 0
        right = len(nums)-1
        mn = 2000000000

        while left <= right:
        	middle = (left + right)//2
        	if nums[middle] < nums[left]:
        		mn = min(mn, nums[middle])
        		right = middle - 1
        	elif nums[middle] > nums[left]:
        		mn = min(nums[left], mn)
        		left = middle + 1
        	else:
        		mn = min(mn, nums[left], nums[right])
        		right -= 1

        return mn


s = Solution()
nums = [1]
print(s.findMin(nums))


