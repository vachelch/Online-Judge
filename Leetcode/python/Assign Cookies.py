class Solution(object):
    def findContentChildren(self, g, s):
        """
        :type g: List[int]
        :type s: List[int]
        :rtype: int
        """
        g.sort()
        s.sort()

        lg = len(g)
        ls = len(s)

        child = 0
        cookie = 0
        count = 0

        while child < lg and cookie< ls:
        	if g[child] <= s[cookie]:
        		count += 1
        		child += 1
        		cookie += 1
        	else:
        		cookie += 1
        return count
