class Solution:
    def trailingZeroes(self, n):
        """
        :type n: int
        :rtype: int
        """
        count = 0
        x = 5
        while x <= n:
            count += n // x
            x *= 5
        return count


