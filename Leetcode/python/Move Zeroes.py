class Solution:
    def moveZeroes(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        l = len(nums)
        zero_indexs = []
        for i in range(l):
            if nums[i] == 0:
                zero_indexs.append(i)

        if len(zero_indexs) == 0: return
        
        for i, index in enumerate(zero_indexs):
            if i == 0:
                start = index + 1
            else:
                end = index - 1
                if end >= start:
                    nums[start - i: end - i + 1] = nums[start: end + 1]
                start = index + 1
        if start <= l -1:
            nums[start - (i+1): l - (i+1)] = nums[start: ]

        nums[(l-(i+1)):] = [0 for x in range(i+1)]


#best
# class Solution:    
#     def moveZeroes(self, nums):
#         """
#         :type nums: List[int]
#         :rtype: void Do not return anything, modify nums in-place instead.
#         """
#         lastZeroFoundAt = 0
#         for cur_index in range(len(nums)):
#             if (nums[cur_index] != 0):
#                     temp = nums[lastZeroFoundAt]
#                     nums[lastZeroFoundAt] = nums[cur_index]
#                     nums[cur_index] = temp
#                     lastZeroFoundAt += 1
#         return 






























