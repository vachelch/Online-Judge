# class Solution:
#     def countArrangement(self, N):
#         """
#         :type N: int
#         :rtype: int
#         """
#         self.res = 0
#         visited = [0 for i in range(N+1)]

#         def search(index, val, visited):
#             if index % val == 0 or val % index == 0:
#                 if index == N:
#                     self.res += 1
#                 else:
#                     for i in range(1, N+1):
#                         if visited[i] == 0:
#                             visited[i] = 1
#                             search(index+1, i, visited)
#                             visited[i] = 0
        
#         for i in range(1, N+1):
#             visited[i] = 1
#             search(1, i, visited)
#             visited[i] = 0

#         return self.res



class Solution:
    def countArrangement(self, N):
        """
        :type N: int
        :rtype: int
        """
        def swap(i, j, nums):
            tmp = nums[i]
            nums[i] = nums[j]
            nums[j] = tmp

        def helper(n, nums):
            if n<= 0: return 1

            res = 0
            for i in range(1, n+1):
                if nums[i] % n == 0 or n % nums[i] == 0:
                    swap(i, n, nums)
                    res += helper(n-1, nums)
                    swap(i, n, nums)

            return res

        nums = [i for i in range(N+1)]
        return helper(N, nums)
        

N = 15
s = Solution()
print(s.countArrangement(N))
