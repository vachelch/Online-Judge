#O(nlogn)

class Solution:
    def findUnsortedSubarray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        l = len(nums)

        nums_2 = sorted(nums)
        count = 0

        start = end = 0
        flag = 1

        for i in range(l):
        	if nums[i] != nums_2[i]:
        		if flag == 1:
        			start = i
        			flag = 0
        		else:
        			end = i

        if start == end: 
        	return 0
        else:
        	return end - start + 1

