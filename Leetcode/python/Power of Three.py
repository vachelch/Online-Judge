from math import pow
class Solution:
    def isPowerOfThree(self, n):
        """
        :type n: int
        :rtype: bool
        """
        return  n>0 and pow(3, 19) % n == 0

