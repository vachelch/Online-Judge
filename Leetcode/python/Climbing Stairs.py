class Solution:
    def climbStairs(self, n):
        """
        :type n: int
        :rtype: int
        """
        if n <= 2: return n
        step0 = 1
        step1 = 2

        for i in range(2, n):
        	tmp = step1
        	step1 = step1 + step0
        	step0 = tmp

        return step1