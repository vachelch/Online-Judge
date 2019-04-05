class Solution:
    def nextPermutation(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        def swap(i, j, nums):
        	tmp = nums[i]
        	nums[i] = nums[j]
        	nums[j] = tmp

        l = len(nums)

        for i in range(l-2, -1, -1):
        	if nums[i] < nums[i+1]:
        		for j in range(l-1, i, -1):
        			if nums[j] > nums[i]:
        				swap(i, j, nums)
        				break

        		print(i, j)
        		start = i+1
        		end = l-1

        		while start < end:
        			swap(start, end, nums)
        			start += 1
        			end -= 1

        		return

        nums.sort()


nums = [4,2,0,2,3,2,0]
s = Solution()
print(s.nextPermutation(nums))