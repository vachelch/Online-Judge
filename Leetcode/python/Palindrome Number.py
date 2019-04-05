class Solution:
    def isPalindrome(self, x):
        """
        :type x: int
        :rtype: bool
        """
        s = str(x)
        l = len(s)
        for i in range(l//2 + 1):
        	if s[i] != s[l-i-1]: return False
        return True
