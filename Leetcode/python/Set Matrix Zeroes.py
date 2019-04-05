class Solution:
    def setZeroes(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: void Do not return anything, modify matrix in-place instead.
        """
        m = len(matrix)
        n = len(matrix[0])
   
        clear_r = 0
        clear_c = 0

        for i in range(m):
            if (matrix[i][0] == 0): clear_c = 1

        for j in range(n):
            if (matrix[0][j] == 0): clear_r = 1

        for i in range(m):
            for j in range(n):
                if(matrix[i][j] == 0):
                    matrix[0][j] = 0
                    matrix[i][0] = 0

        for i in range(1, m):
            if(matrix[i][0] == 0):
                print(i)
                for j in range(1, n):
                    matrix[i][j] = 0
        print('--j--')
        for j in range(1, n):
            if(matrix[0][j] == 0):
                print(j)
                for i in range(1, m):
                    matrix[i][j] = 0

        if(clear_r):
            for j in range(n):
                matrix[0][j] = 0
        if(clear_c):
            for i in range(m):
                matrix[i][0] = 0

matrix = [[0,0,0,5],
            [4,3,1,4],
            [0,1,1,4],
            [1,2,1,3],
            [0,0,1,1]]
s = Solution()

s.setZeroes(matrix)
print(matrix)


# [
#     [0,0,0,0],
#     [0,3,1,4],
#     [0,1,1,4],
#     [0,2,1,3],
#     [0,0,1,1]]


# [
#     [0,0,0,0],
#     [0,0,0,4],
#     [0,0,0,0],
#     [0,0,0,3],
#     [0,0,0,0]]








