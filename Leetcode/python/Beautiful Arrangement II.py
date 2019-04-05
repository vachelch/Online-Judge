# class Solution:
#     def constructArray(self, n, k):
#         """
#         :type n: int
#         :type k: int
#         :rtype: List[int]
#         """
#         def helper(index, k, res, iset):
#             if index == n+1:
#                 if k==0: 
#                     return 1
#                 else:
#                     return 0

#             if k >= 0:
#                 for val in range(1, n+1):
#                     if visited[val] == 0:
#                         visited[val] = 1
#                         diff = abs(val - res[-1])
#                         res.append(val)
#                         flag = 0
#                         if diff not in iset:
#                             flag = 1
#                             iset.add(diff)
#                             k -= 1


#                         if helper(index + 1, k, res, iset):
#                             return 1
#                         res.pop()
#                         visited[val] = 0
#                         if flag:
#                             iset.remove(diff)
#                             k += 1

#             return 0

#         visited = [0 for i in range(n+1)]
#         res = []
#         iset = set()
#         for i in range(1 ,n+1):
#             res.append(i)
#             visited[i] = 1
#             if helper(2, k, res, iset):
#                 return res
#             res.pop()
#             visited[i] = 0
        




class Solution:
    def constructArray(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: List[int]
        """
        left = 1
        right = n
        res = []
        while left <= right:
        	if k > 1:
        		if k % 2 != 0:
        			res.append(left)
        			left += 1
        		else:
        			res.append(right)
        			right -= 1
        		k -= 1

        	else:
        		res.append(left)
        		left += 1

        return res


n = 3
k = 1
s = Solution()
print(s.constructArray(n ,k))


