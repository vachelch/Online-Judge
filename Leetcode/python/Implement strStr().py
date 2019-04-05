class Solution(object):
    def strStr(self, haystack, needle):
        """
        :type haystack: str
        :type needle: str
        :rtype: int
        """
        l_n = len(needle)
        l_h = len(haystack)
        if l_n > l_h: return -1

        start = 0
        
        while start <= l_h-l_n:
        	is_same = 1
        	for i in range(l_n):
        		if haystack[i+start] != needle[i]: 
        			is_same = 0
        			break

        	if is_same: return start
        	start += 1

        return -1


haystack = 'asdf'
needle = ''
s = Solution()
print(s.strStr(haystack, needle))