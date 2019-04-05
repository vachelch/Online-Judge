class Solution:
    def maxCount(self, m, n, ops):
        """
        :type m: int
        :type n: int
        :type ops: List[List[int]]
        :rtype: int
        """
        if ops == []: return m*n
        min_a = min_b = 40000
        for op in ops:
        	x, y = op
        	min_a = min(x, min_a)
        	min_b = min(y, min_b)

        return min_a*min_b

