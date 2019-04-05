class NumArray:

    def __init__(self, nums):
        """
        :type nums: List[int]
        """
        l = len(nums)
        self.sums = []
        sum_ = 0
        for i in range(l):
            sum_ += nums[i]
            self.sums.append(sum_)

    def sumRange(self, i, j):
        """
        :type i: int
        :type j: int
        :rtype: int
        """
        if i == 0: return self.sums[j]
        return self.sums[j] - self.sums[i-1]


# Your NumArray object will be instantiated and called as such:
# obj = NumArray(nums)
# param_1 = obj.sumRange(i,j)