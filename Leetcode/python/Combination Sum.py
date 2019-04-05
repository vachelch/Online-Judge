class Solution:
    def combinationSum(self, candidates, target):
        """
        :type candidates: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        res = []
        l = len(candidates)
        def helper(sol, left, index, len):
        	for i in range(index, len):
        		if left >= candidates[i]:
        			sol.append(candidates[i])
        			if left == candidates[i]:
        				res.append(sol[:])
        			else:
        				helper(sol, left - candidates[i], i, len)
        			sol.pop()

        sol = []
        helper(sol, target, 0, l)
        return res

s = Solution()
candidates = [7,6,5,4,3,2]
target = 7

print(s.combinationSum(candidates, target))

