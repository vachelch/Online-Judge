class Solution:
    def isPerfectSquare(self, num):
        """
        :type num: int
        :rtype: bool
        """
        if num == 0: return True
        n = 1
        while num >= n*n:
        	if n*n == num: return True
        	n += 1
        return False

