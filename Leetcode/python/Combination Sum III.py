class Solution:
    def combinationSum3(self, k, n):
        """
        :type k: int
        :type n: int
        :rtype: List[List[int]]
        """
        res = []
        sol = []
        def helper(sol, k, n, start):
        	if k==0 and n == 0:
        		res.append(sol[:])
        	elif k > 0 and n > 0:
        		for i in range(start, 10):
        			if start > n:
        				return 
        			sol.append(i)
        			helper(sol, k-1, n-i, i+1)
        			sol.pop()

        helper(sol, k, n, 1)
        return res

s = Solution()
k = 3
n = 9
print(s.combinationSum3(k, n))