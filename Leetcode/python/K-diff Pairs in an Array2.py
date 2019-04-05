#O(n)
class Solution:
    def findPairs(self, nums, k):
        l = len(nums)
        dic = {}
        for i in range(l):
            if nums[i] in dic:
                dic[nums[i]] +=1
            else:
                dic[nums[i]] = 1

        count = 0
        if k == 0:
            for key, val in dic.items():
                if val  >= 2:
                    count += 1

        else:
            for key, val in dic.items():
                if key + k in dic:
                    count += 1

        if k < 0:
            return 0
        else:
            return count






