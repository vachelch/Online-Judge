#log(n^2)
class Solution:
    def not_repeat(self, a, b):
        if a in self.pair and  b in self.pair[a]:
    	    return 0
        else:
            return 1

    def findPairs(self, nums, k):
    	if k< 0 : return 0
    	l = len(nums)
    	self.pair = {}
    	count = 0
    	for i in range(l):
    		for j in range(i+1, l):
    			if nums[j] + k == nums[i] or nums[j] - k == nums[i]:
    				if self.not_repeat(nums[i], nums[j]):
    					count += 1
    					# print(nums[i], nums[j])
    					if nums[i] not in self.pair:
    						self.pair[nums[i]] = [nums[j]]
    					else:
    						self.pair[nums[i]].append(nums[j])

    					if nums[j] not in self.pair:
    						self.pair[nums[j]] = [nums[i]]
    					else:
    						self.pair[nums[j]].append(nums[i])


    	return count





