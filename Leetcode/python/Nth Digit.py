class Solution:
    def findNthDigit(self, n):
        """
        :type n: int
        :rtype: int
        """
        cnt = 9
        len_ = 1
        start = 1
        while n > cnt*len_:
        	n -= cnt*len_
        	cnt *= 10
        	len_ += 1
        	start *= 10

        num = start + (n-1)//len_
        index = (n-1)%len_
        return int(str(num)[index])

n = 100
s = Solution()
print(s.findNthDigit(n))
