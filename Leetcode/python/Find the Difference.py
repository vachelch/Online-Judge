class Solution:
    def findTheDifference(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: str
        """
        idict = {}
        for w in s:
        	if w in idict: idict[w] += 1
        	else: idict[w] = 1

        for w in t:
        	if w not in idict or idict[w] == 0:
        		return w
        	idict[w] -= 1
