class Solution:
    def numJewelsInStones(self, J, S):
        """
        :type J: str
        :type S: str
        :rtype: int
        """
        iset = set()
        for i in range(len(J)):
        	iset.add(J[i])
        count = 0
        for c in S:
        	if c in iset:
        		count += 1
        return count
