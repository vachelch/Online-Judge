class Solution:
    def isUgly(self, num):
        """
        :type num: int
        :rtype: bool
        """
        if num < 1: return False
        for item in [2, 3, 5]:
        	while num % item == 0:
        		num /= item

        return num == 1