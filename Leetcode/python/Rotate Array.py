class Solution:
    def rotate(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        l = len(nums)
        left = nums[k+1:] #l-k-1 length 0
        right = nums[:k+1] # k+1 length 1
        nums[:l-k-1] = left[:]
        nums[l-k-1:] = right[:]

        return nums


s = Solution()
nums = [1,2]
k = 0
print(s.rotate(nums, k))