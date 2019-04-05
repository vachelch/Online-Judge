import math

class Solution:
    def primePalindrome(self, N):
        """
        :type N: int
        :rtype: int
        """
        def isPalindrome(n):
            s = str(n)
            l = len(s)
            if l % 2 == 0:
                if s[ :l//2] == s[-1 : l//2-1 : -1]:
                    return True
            else:
                if s[ :(l-1)//2] == s[-1 : (l+1)//2 - 1 : -1]:
                    return True
            return False

        def isPrime(n):
            sqrt_n = math.sqrt(n)
            i = 2
            while i <= sqrt_n:
                if n % i == 0:
                    return False
                i += 1

            return True  

        if N == 1: return 2

        n = N
        while not isPalindrome(n) or not isPrime(n):
            n += 1

        return n

s = Solution()
print(s.primePalindrome(8))











