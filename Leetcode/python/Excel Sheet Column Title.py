class Solution:
    def convertToTitle(self, n):
        """
        :type n: int
        :rtype: str
        """
        def to_alpha(num):
        	return chr(ord('A') + num)
        res = ''
        while n>0:
        	res = to_alpha((n-1) % 26) + res
        	n = (n-1) // 26

        return res

