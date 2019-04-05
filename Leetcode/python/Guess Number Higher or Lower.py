# The guess API is already defined for you.
# @param num, your guess
# @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
# def guess(num):

class Solution(object):
    def guessNumber(self, n):
        """
        :type n: int
        :rtype: int
        """
        left = 1
        right = n
        while 1:
            middle = (left + right)//2
            ret = guess(middle)
            if ret == 0: return middle
            elif ret == -1: right = middle -1
            else: left = middle + 1
        
        
        