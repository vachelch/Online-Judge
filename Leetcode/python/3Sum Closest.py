class Solution:
    def threeSumClosest(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        nums.sort()
        l = len(nums)
        mn = 2000000000

        for i in range(l-2):
            left = i+1
            right = l-1
            while left < right:
                sum_3 = nums[left] + nums[right] + nums[i]
                if abs(target - sum_3) < mn:
                    mn = abs(target - sum_3)
                    res = sum_3
                mn = min(mn, abs(target - sum_3))
                if sum_3 < target:
                    left += 1
                elif sum_3 > target:
                    right -= 1
                else:
                	return sum_3
        return res

s = Solution()
nums = [0,1,2]
target = 3

print(s.threeSumClosest(nums, target))