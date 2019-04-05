class Solution:
    def floodFill(self, image, sr, sc, newColor):
        """
        :type image: List[List[int]]
        :type sr: int
        :type sc: int
        :type newColor: int
        :rtype: List[List[int]]
        """
        self.starting = image[sr][sc]
        self.newColor = newColor
        self.image = image
        self.r = len(image)
        self.c = len(image[0])
        self.flooded = [[0 for i in range(self.c)] for j in range(self.r)]

        def traverse(r, c):
        	if 0<=r<self.r and 0<=c<self.c and self.flooded[r][c]==0 and self.image[r][c] == self.starting:
        		self.image[r][c] = self.newColor
        		self.flooded[r][c] = 1
        		for i in [-1, 1]:
        			traverse(r+i, c)
        			traverse(r, c+i)

        traverse(sr, sc)

        return image




















