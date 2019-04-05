class Solution:
    def countPrimes(self, n):
        """
        :type n: int
        :rtype: int
        """
        if n < 2: return 0
        def isPrime(num):
        	test = 2
        	while test * test <= num:
        		if num % test == 0: return False
        		test += 1
        	return True
        prime = [1 for i in range(n-1)]
        prime[0] = 0
        i = 1
        while (i+1)*(i+1) <= n -1:
        	if prime[i] == 1:
        		num = i+1
        		if isPrime(num): 
        			sum_ = 2*num
        			while sum_ <= n-1:
        				prime[sum_ - 1] = 0
        				sum_ += num
        	i += 1
        return sum(prime)

















