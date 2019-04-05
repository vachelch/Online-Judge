class Solution:
    def advantageCount(self, A, B):
        """
        :type A: List[int]
        :type B: List[int]
        :rtype: List[int]
        """
        B_idxs = sorted(range(len(B)), key=lambda k: B[k])

        A.sort()
        B_tmp = sorted(B)

        i, j = 0, 0
        l_A, l_B = len(A), len(B)
        sm = 0

        while i < l_A and j < l_B:
        	if A[i] <= B_tmp[j]:
        		i += 1
        	else:
        		i += 1
        		j += 1
        		sm += 1

        res = A[:]
        for i in range(sm):
        	res[B_idxs[i]] = A[l_A - sm + i]
        for i in range(sm, l_A):
        	res[B_idxs[i]] = A[i - sm]

        return res

A = [12,24,8,32]
B = [13,25,32,11]
s = Solution()
print(s.advantageCount(A, B))










