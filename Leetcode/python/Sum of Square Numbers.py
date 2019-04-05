import math

class Solution:
    def judgeSquareSum(self, c):
        """
        :type c: int
        :rtype: bool
        """
        tmp = 0
        while tmp*tmp <= c:
        	another = math.sqrt(c - tmp*tmp) 
        	if math.sqrt(c - tmp*tmp) % 1 == 0:
        		return True
        	tmp += 1
        return False

s = Solution()
c = 0
print(s.judgeSquareSum(c))