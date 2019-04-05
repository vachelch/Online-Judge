class Solution:
    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        nums.sort()
        l = len(nums)
        res = []

        for i in range(l-2):
            n_i = nums[i]
            if i==0 or n_i != nums[i-1]:
                left = i+1
                right = l-1

                while left < right:
                    n_l = nums[left]
                    n_r = nums[right]

                    sum_ = n_l + n_r + n_i
                    if sum_ == 0:
                        item = [n_i, n_l, n_r]
                        if ((left == i+1 or n_l != nums[left-1]) and (right == l-1 or n_r != nums[right + 1])):
                            res.append(item)
                        left += 1
                    elif sum_ > 0:
                        right -= 1
                    else:
                        left += 1

        return res

