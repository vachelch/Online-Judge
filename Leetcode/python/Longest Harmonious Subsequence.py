class Solution:
    def findLHS(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        idict = {}
        for num in nums:
        	if num in idict:
        		idict[num] += 1
        	else:
        		idict[num] = 1

        max_ = 0
        for key, val in idict.items():
        	if key + 1 in idict:
        		n = idict[key] + idict[key+1]
        		max_ = max(n, max_)

        return max_