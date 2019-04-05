class Solution:
    def countable(self, grid, a, b):
        if 0 <= a < self.row and 0<= b<self.col and grid[a][b] == 1:
            return 1
        return 0

    def helper(self, grid, i, j):
        self.cnt += 1
        if self.max_cnt < self.cnt:
            self.max_cnt = max(self.max_cnt, self.cnt)
        #search around
        grid[i][j] = -1
        for k in [-1, 1]:
            if self.countable(grid, i+k, j):
                self.helper(grid, i+k, j)

            if self.countable(grid, i, j+k):
                self.helper(grid, i, j+k)
    
    def maxAreaOfIsland(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        self.cnt = 0
        self.max_cnt = 0
        self.row = len(grid)
        self.col = len(grid[0])
        for i in range(self.row):
            for j in range(self.col):
                if grid[i][j] == 1:
                    self.helper(grid, i, j)
                    self.cnt = 0
                    
        
        return self.max_cnt
    










