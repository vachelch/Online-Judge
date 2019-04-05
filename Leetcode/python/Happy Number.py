class Solution:
    def isHappy(self, n):
        """
        :type n: int
        :rtype: bool
        """
        sets = set()
        while 1:
            sum_ = 0
            while n>0:
                i = n % 10
                sum_ += i*i
                n //= 10
            if sum_ == 1: return True
            if sum_ in sets: return False
            sets.add(sum_)
            n = sum_


