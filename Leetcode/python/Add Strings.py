class Solution:
    def addStrings(self, num1, num2):
        """
        :type num1: str
        :type num2: str
        :rtype: str
        """
        def atoi(num):
        	l = len(num)
        	sum_ = 0
        	for i in range(l):
        		sum_ = sum_*10 + int(num[i])
        	return sum_

        return str(atoi(num1) + atoi(num2))
