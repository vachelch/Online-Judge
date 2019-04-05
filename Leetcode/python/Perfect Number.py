import math

class Solution:
    def checkPerfectNumber(self, num):
        """
        :type num: int
        :rtype: bool
        """
        if num < 2: return False
        divider = 2
        sum_ = 1
        sqrt = math.sqrt(num)
        while divider <= sqrt:
        	if num % divider == 0 and num/divider != divider:
        		sum_ = sum_ + divider + num//divider
        	divider += 1
        return sum_ == num


s = Solution()
num = 1
print(s.checkPerfectNumber(num))