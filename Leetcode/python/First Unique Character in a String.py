class Solution:
    def firstUniqChar(self, s):
        """
        :type s: str
        :rtype: int
        """
        idict = {}
        iset = set()

        for w in s:
        	if w in idict: idict[w] += 1
        	else: idict[w] = 1

        	if idict[w] >= 2: iset.add(w)

        for i in range(len(s)):
        	if s[i] not in iset:
        		return i

        return -1





