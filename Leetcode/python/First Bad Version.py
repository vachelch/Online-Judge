# The isBadVersion API is already defined for you.
# @param version, an integer
# @return a bool
# def isBadVersion(version):

class Solution(object):
    def firstBadVersion(self, n):
        """
        :type n: int
        :rtype: int
        """
        left = 1
        right = n
        while 1:
	        middle = (left + right)//2
	        resp = isBadVersion(middle)
	        if resp:
	        	if isBadVersion(middle - 1): right = middle-1
	        	else: return middle
	        else:
	        	left = middle + 1

