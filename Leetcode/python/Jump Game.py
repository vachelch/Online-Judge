class Solution:
    def canJump(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        l = len(nums)
        mx = 0;

        for i in range(l):
            mx = max(nums[i] + i, mx)
            if mx <= i:
                if i == l-1: return True
                else: return False
        return True


nums = [0]
s = Solution()

print(s.canJump(nums))
