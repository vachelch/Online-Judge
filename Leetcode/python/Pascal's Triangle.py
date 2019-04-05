class Solution:
    def generate(self, numRows):
        """
        :type numRows: int
        :rtype: List[List[int]]
        """
        if numRows == 0: return []

        pascal = [[1]]
        for i in range(1, numRows):
        	row = []
        	for j in range(i+1):
        		if j == 0 or j == i:
        			row.append(1)
        		else:
        			row.append(pascal[i-1][j-1] + pascal[i-1][j])
        	pascal.append(row)

        return pascal

s = Solution()
numRows = 1
print(s.generate(numRows))
