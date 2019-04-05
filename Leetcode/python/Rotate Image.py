# class Solution:
#     def rotate(self, matrix):
#         """
#         :type matrix: List[List[int]]
#         :rtype: void Do not return anything, modify matrix in-place instead.
#         """
#         def transpose(matrix, i, j):
#             tmp = matrix[i][j]
#             matrix[i][j] = matrix[j][i]
#             matrix[j][i] = tmp

#         def swap(matrix, i, j, n):
#             tmp = matrix[i][j]
#             matrix[i][j] = matrix[i][n-j-1]
#             matrix[i][n-j-1] = tmp

#         m = len(matrix)
#         n = len(matrix[0])
#         for i in range(m):
#             for j in range(i+1, n):
#                 transpose(matrix, i, j)

#         for i in range(m):
#             for j in range(n//2):
#                 swap(matrix, i, j, n)

#best solution
class Solution:
    def rotate(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: void Do not return anything, modify matrix in-place instead.
        """
        m = len(matrix)

        for i in range(m//2):
            for j in range(i, m-1-i):
                tmp = matrix[i][j]
                matrix[i][j] = matrix[m-j-1][i]
                matrix[m-j-1][i] = matrix[m-1-i][m-j-1]
                matrix[m-1-i][m-j-1] = matrix[j][m-1-i]
                matrix[j][m-1-i] = tmp


s = Solution()
matrix = [
 [5 ,1 ,9 ,11],
 [2 ,4 ,8 ,10],
 [13,3 ,6 , 7],
 [15,14,12,16]]
s.rotate(matrix)
print(matrix)









