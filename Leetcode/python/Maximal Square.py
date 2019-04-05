class Solution:
    def maximalSquare(self, matrix):
        """
        :type matrix: List[List[str]]
        :rtype:         """
        
        m = len(matrix)
        if (m==0): return 0
        n = len(matrix[0])
        arr = []
        dp = []

        for i in range(m):
        	dp.append([]) 
        	for j in range(n):
        		dp[i].append(ord(matrix[i][j]) - ord('0'))

        mx_border = 0 

        for j in range(n):
        	mx_border = max(mx_border, dp[0][j]) 

        for i in range(m):
        	mx_border = max(mx_border, dp[i][0]) 

        for i in range(1, m):
        	for j in range(1, n):
        		if (dp[i][j] == 1) :
        			dp[i][j] = min(dp[i][j-1], dp[i-1][j], dp[i-1][j-1]) + 1 
        			mx_border = max(mx_border, dp[i][j]) 

        return mx_border*mx_border 


s = Solution()
matrix = []
matrix.append('10100')
matrix.append('10111')
matrix.append('11111')
matrix.append('10010')

print(s.maximalSquare(matrix))










