class Solution:
    def mySqrt(self, x):
        """
        :type x: int
        :rtype: int
        """
        if x == 0: return 0
        left = 1
        right = x

        while left <= right:
            middle = left + (right - left)//2
            if x//middle == middle:
                return middle
            elif x//middle > middle: left = middle + 1
            else: right = middle -1 
        return right


