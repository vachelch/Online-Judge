class Solution:
    def subarraySum(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        back = []
        sum_ = 0
        for num in nums:
        	sum_ += num
        	back.append(sum_)

        idict = {0:1}

        count = 0
        for item in back:
        	if (item - k) in idict:
        		count += idict[item-k]
        	if item in idict:
        		idict[item] += 1
        	else:
        		idict[item] = 1

        return count

s = Solution()
nums = [1,1,1]
print(s.subarraySum(nums, 2))