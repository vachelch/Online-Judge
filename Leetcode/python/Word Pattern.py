class Solution:
    def wordPattern(self, pattern, str):
        """
        :type pattern: str
        :type str: str
        :rtype: bool
        """
        idict = {}
        chars = str.split()
        iset = set()

        if len(chars) != len(pattern): return False
        for i, p in enumerate(pattern):
        	if p not in idict: 
        		word = chars[i]
        		if word in iset:
        			return False
        		idict[p] = word
        		iset.add(word)

        	else: 
        		if idict[p] != chars[i]:
        			return False

        return True


