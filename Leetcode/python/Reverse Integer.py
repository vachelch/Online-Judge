class Solution:
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        MAX_LIMIT = pow(2, 31)-1
        MIN_LIMIT = -pow(2, 31)
        if 0 <= x <= MAX_LIMIT:
        	res = int(str(x)[::-1])
        	if res <= MAX_LIMIT: return res
        	return 0
        elif MIN_LIMIT <= x < 0:
        	res = -int(str(-x)[::-1])
        	if res >= MIN_LIMIT: return res
        	return 0
        return 0


