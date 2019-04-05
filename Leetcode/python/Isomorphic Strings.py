class Solution:
    def isIsomorphic(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        ls = len(s)
        lt = len(t)
        if ls != lt: return False
        
        idict = {}
        iset = set()
        for i in range(ls):
        	ws = s[i]
        	wt = t[i]
        	if ws not in idict: 
        		if wt in iset: return False
        		iset.add(wt)
        		idict[ws] = wt
        	elif idict[ws] != wt: return False

        return True

