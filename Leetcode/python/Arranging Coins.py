from math import sqrt

class Solution:
    def arrangeCoins(self, n):
        """
        :type n: int
        :rtype: int
        """
        def sum_(n):
        	return n*(n+1)//2
        x = int(sqrt(n*2))
        while sum_(x) <= n: x += 1

        return x-1