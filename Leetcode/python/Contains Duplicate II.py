class Solution:
    def containsNearbyDuplicate(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: bool
        """
        dic = {}

        for i, item in enumerate(nums):
        	if item not in dic:
        		dic[item] = i
        	else:
        		distance = abs(i - dic[item])
        		if distance <= k:
        			return True
        		else:
        			dic[item] = i
        return False
