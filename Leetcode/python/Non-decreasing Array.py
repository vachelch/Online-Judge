class Solution:
    def checkPossibility(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        n = len(nums) 
        if n <= 2: return True
        
        last = nums[1]
        ct = 0
        if nums[1] < nums[0]:
            ct += 1
            
        for i in range(2, n):
            if nums[i] < last:
                ct += 1
                if nums[i] >= nums[i-2]:
                    last = nums[i]
                    continue
                if i < n-1 and nums[i+1] < nums[i-1]:
                    return False
            
            last = nums[i]
            
        if ct <= 1:
            return True
        else:
            return False
                
                


                
                
