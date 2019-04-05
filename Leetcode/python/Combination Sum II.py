class Solution:
    def combinationSum2(self, candidates, target):
        """
        :type candidates: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        res = []
        l = len(candidates)
        candidates.sort()
        def helper(sol, left, index, len):
            for i in range(index, len):
                if i == index or candidates[i-1] != candidates[i]:
                    if left >= candidates[i]:
                        sol.append(candidates[i])
                        if left == candidates[i]:
                            res.append(sol[:])
                        else:
                            helper(sol, left - candidates[i], i+1, len)
                        sol.pop()

        sol = []
        helper(sol, target, 0, l)
        return res

s = Solution()
target = 8
candidates = [10, 1, 2, 7, 6, 1, 5]
print(s.combinationSum2(candidates, target))