class Solution(object):
    def isPalindrome(self, s):
        """
        :type s: str
        :rtype: bool
        """
        l = len(s)
        right = l - 1
        left = 0
        s = s.lower()

        while left < right:
        	while right > left and not s[right].isalnum():
        		right -= 1

        	while left < right and not s[left].isalnum():
        		left += 1

        	if left >= right: break

        	if s[right] != s[left]: return False
        	right -= 1
        	left += 1

        return True






