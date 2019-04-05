class Solution:
    def islandPerimeter(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        r = len(grid)
        c = len(grid[0])
        idict = {}

        def near_land(i, j):
        	water = 0
        	if j==0 or grid[i][j-1] == 0:
        		water += 1
        	if j == c-1 or grid[i][j+1] == 0:
        		water += 1
        	if i==0 or grid[i-1][j] == 0:
        		water += 1
        	if i==r-1 or grid[i+1][j] == 0:
        		water += 1
        	return 4-water

        count = 0
        for i in range(r):
        	for j in range(c):
        		if grid[i][j] == 1:
        			count += 1
        			near = near_land(i, j)
        			if near in idict: idict[near] += 1
        			else: idict[near] = 1

        perimeter = 4*count
        for key, val in idict.items():
        	perimeter -= key*val

        return perimeter
