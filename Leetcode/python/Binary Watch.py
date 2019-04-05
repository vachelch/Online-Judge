class Solution(object):
    def readBinaryWatch(self, num):
        """
        :type num: int
        :rtype: List[str]
        """
        def bitcount(num):
        	count = 0
        	while num>0:
        		mod = num % 2
        		num //= 2
        		count += mod
        	return count

        res = []
        for h in range(12):
        	for m in range(60):
        		if bitcount(h) + bitcount(m) == num:
        			res.append("%d:%02d"%(h, m))
        return res

s = Solution()
num = 1
print(s.readBinaryWatch(num))





















