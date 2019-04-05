class Solution:
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """

        l = len(nums);
        if (l<= 2): return l
        total = 2

        for i in range(2, l):
            if(nums[i] != nums[i-2]):
                total += 1

        return total




nums = [1,1,1,2,2,3]
s = Solution()
print(s.removeDuplicates(nums))
