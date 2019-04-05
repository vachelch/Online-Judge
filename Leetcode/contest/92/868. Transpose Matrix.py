class Solution:
    def transpose(self, A):
        """
        :type A: List[List[int]]
        :rtype: List[List[int]]
        """
        if len(A) == 0: return []
        B = [[0 for i in range(len(A))] for j in range(len(A[0]))]
        for i in range(len(A)):
            for j in range(len(A[0])):
                B[j][i] = A[i][j]
                
        return B