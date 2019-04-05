class Solution:
    def rob(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        l = len(nums)
        if l == 0: return 0
        if l <=2: return max(nums)
        dp0 = nums[0]
        dp1 = max(nums[0], nums[1])
        for i in range(2, len(nums)):
        	tmp = dp1
        	dp1 = max(dp0 + nums[i], dp1)
        	dp0 = tmp

        return dp1

nums = [2,1,1,2]
s = Solution()

print(s.rob(nums))
