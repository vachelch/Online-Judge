class Solution:
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        l = len(nums)
        if l == 0: return 0
        index = 1
        last = nums[0]

        k = 1
        while k < l:
        	cur = nums[k]
        	if cur != last:
        		last = nums[index] = cur
        		index += 1
        	k += 1
        return index

s = Solution()
nums = [1, 1, 2]
a = s.removeDuplicates(nums)
print(a)
print(nums[:a])