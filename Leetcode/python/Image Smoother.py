class Solution:
    def cond(self, M, i ,j):
        sum = 0
        divider = 0

        for r in range(-1, 2):
            if 0 <= i+r < self.r:
                for c in range(-1, 2):
                    if 0 <= j+c < self.c:
                            sum += M[i + r][j + c]
                            divider += 1
        return divider ,sum
    
    def imageSmoother(self, M):
        """
        :type M: List[List[int]]
        :rtype: List[List[int]]
        """
        N = []
        self.r = len(M)
        self.c = len(M[0])
        
        
        for i in range(self.r):
            row = []
            for j in range(self.c):
                divider, sum = self.cond(M, i, j)
                row.append(sum // divider)
            N.append(row)
            
        return N























        