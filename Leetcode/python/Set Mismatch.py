class Solution:
    def findErrorNums(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        l = len(nums)
        dic = set()
        sums = 0
        for i in range(l):
        	if nums[i] in dic:
        		duplicate =  nums[i]
        	else:
        		dic.add(nums[i])
        	sums += nums[i]

        return [duplicate, (l+1)*l//2 + duplicate - sums]


nums = [3,2,2]
s = Solution()
print(s.findErrorNums(nums))

