class Solution:
    def matrixReshape(self, nums, r, c):
        """
        :type nums: List[List[int]]
        :type r: int
        :type c: int
        :rtype: List[List[int]]
        """
        R = len(nums)
        C = len(nums[0])
        if R*C != r*c: return nums

        count = 0
        new_nums = []
        for i in range(R):
        	for j in range(C):
        		if count % c == 0:
        			new_nums.append([])
        		new_nums[(i*C + j) // c].append(nums[i][j])
        		count += 1

        return new_nums

