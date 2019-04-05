class Solution:
    def isPowerOfTwo(self, n):
        """
        :type n: int
        :rtype: bool
        """
        if n <= 0: return False
        while n % 10 in [0, 2, 4, 6, 8]:
        	n /= 2
        return n == 1

#method 2
# class Solution:
#     def isPowerOfTwo(self, n):
#         """
#         :type n: int
#         :rtype: bool
#         """
#         return n>0 and n&(n-1) == 0

