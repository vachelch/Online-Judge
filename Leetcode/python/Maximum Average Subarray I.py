class Solution:
    def maximumProduct(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        l = len(nums)
        if l == 3: return nums[0]*nums[1]*nums[2]
            
        nums.sort()
        
        if nums[l - 1] <= 0:
            return nums[l-3]*nums[l-2]*nums[l-1]
        
        elif nums[l -2] <= 0:
            return nums[0]*nums[1]*nums[l-1]
        elif nums[l-3] <= 0:
            return max(nums[0]*nums[1]*nums[l-1], nums[0]*nums[l-2]*nums[l-1])
        else:
            return max(nums[0]*nums[1]*nums[l-1], nums[l-3]*nums[l-2]*nums[l-1], nums[0]*nums[l-2]*nums[l-1])
                
            