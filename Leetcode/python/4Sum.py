class Solution:
    def fourSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        l = len(nums)
        res = []
        nums.sort()
        for i in range(l-3):
            if i ==0 or nums[i] != nums[i-1]:
                n_i = nums[i]
                for j in range(i+1, l-2):
                    if j==i+1 or nums[j] != nums[j-1]:
                        n_j = nums[j]
                        left = j+1
                        right = l-1

                        while left < right:
                            n_l = nums[left]
                            n_r = nums[right]
                            sum_ = n_i + n_j + n_l + n_r

                            if sum_ == target:
                                res.append([n_i, n_j, n_l, n_r])
                                left += 1
                                while left < right and nums[left] == nums[left-1]:
                                	left += 1
                            elif sum_ < target:
                                left += 1
                                while left < right and nums[left] == nums[left-1]:
                                	left += 1
                            else:
                                right -= 1
                                while left < right and nums[right] == nums[right+1]:
                                	right -= 1

        return res
