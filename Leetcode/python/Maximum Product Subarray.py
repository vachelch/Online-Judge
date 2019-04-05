class Solution:
    def maxProduct(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        mx = -2000000000
        mx_pos = mx_neg = 1

        for i in range(len(nums)):
            val1 = nums[i]*mx_pos
            val2 = nums[i]*mx_neg

            mx_pos = max(val1, val2, nums[i])
            mx_neg = min(val1, val2, nums[i])

            mx = max(mx, mx_pos)

        return mx

nums = [-4,-3,-2, 0, 13]
s = Solution()

print(s.maxProduct(nums))

