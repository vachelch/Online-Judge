class Solution:
    def titleToNumber(self, s):
        """
        :type s: str
        :rtype: int
        """
        def to_ten(c): return ord(c)-ord('A') + 1

        l = len(s)
        res = 0
        base = 1
        for i in range(l-1, -1, -1):
        	res += to_ten(s[i]) * base
        	base *= 26

        return res
