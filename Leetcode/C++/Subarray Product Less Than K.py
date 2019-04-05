class Solution:
    def numSubarrayProductLessThanK(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        if k ==0: return 0
        k_log = math.log(k)
        back = [0]
        for num in nums:
        	back.append(math.log(num) + back[-1])

        count = 0
        for i, n in enumerate(nums):
        	for j in range(len(nums), i, -1):
        		if back[j] - back[i] < k_log:
        			count += j-i
        			break

        return count