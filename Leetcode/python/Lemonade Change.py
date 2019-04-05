class Solution:
    def lemonadeChange(self, bills):
        """
        :type bills: List[int]
        :rtype: bool
        """
        five, ten = 0, 0
        for bill in bills:
        	if bill == 5:
        		five += 1
        	elif bill == 10:
        		ten += 1
        		five -= 1
        		if five < 0:
        			return False
        	else:
        		if ten == 0:
        			five -= 3
        			if five < 0:
        				return False
        		else:
        			ten -= 1
        			five -= 1
        			if ten < 0 or five < 0:
        				return False

        return True

bills = [5,5,5,5,20,20,5,5,20,5]
s = Solution()

print(s.lemonadeChange(bills))
