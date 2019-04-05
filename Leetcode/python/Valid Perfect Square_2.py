class Solution:
    def isPerfectSquare(self, num):
        """
        :type num: int
        :rtype: bool
        """
        if num == 0: return True
        left, right = 1, num
        while left <= right:
        	middle = (left + right)//2
        	if middle*middle == num: return True
        	elif middle*middle < num: left = middle + 1
        	else: right = middle - 1
        return False


s = Solution()
num = 17
print(s.isPerfectSquare(num))