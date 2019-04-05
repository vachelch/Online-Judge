class Solution:
    def primePalindrome(self, N):
        """
        :type N: int
        :rtype: int
        """

        def isPrime(n):
            if n % 2 == 0 or n < 2: return n == 2

            sqrt_n = n ** 0.5
            i = 3
            while i <= sqrt_n:
                if n % i == 0:
                    return False
                i += 2
            return True  

        if 8 <= N <= 11: return 11

        l = len(str(N))
        for x in range(10 ** (l // 2), 10**5):
            y = int(str(x) + str(x)[-2::-1])
            if y >= N and isPrime(y): return y