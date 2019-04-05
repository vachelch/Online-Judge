class Solution:
    def isAnagram(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        if len(s) != len(t): return False
        
        idict = {}
        for w in s:
        	if w in idict: idict[w] += 1
        	else: idict[w] = 1

        for w in t:
        	if w not in idict or idict[w] == 0: return False
        	idict[w] -= 1

        return True

