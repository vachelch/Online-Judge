class Solution:
    def spiralOrder(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: List[int]
        """
        l_r = len(matrix)
        if l_r == 0: return []
        l_c = len(matrix[0])

        direction = [(0, 1), (1, 0), (0, -1), (-1, 0)]

        i, j = 0, 0
        direct = direction[0]
        k = 0
        CONST = -2000000000
        res = []

        while 0<=i<l_r and 0<=j<l_c and matrix[i][j] != CONST:

            while 0<=i<l_r and 0<=j<l_c and matrix[i][j] != CONST:
                res.append(matrix[i][j])
                matrix[i][j] = CONST
                i += direct[0]
                j += direct[1]

            i -= direct[0]
            j -= direct[1]
            
            if k == 3: k=0
            else: k += 1
            direct = direction[k]
            i += direct[0]
            j += direct[1]

        return res

s = Solution()
matrix = [[1],[2],[3]]

print(s.spiralOrder(matrix))




