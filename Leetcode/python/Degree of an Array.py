class Solution:
    def findShortestSubArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        dict = {}
        start = {}
        end = {}
        i = 0
        for num in nums:
            if num in dict:
                dict[num] += 1
                end[num] = i
            else:
                dict[num] = 1
                start[num] = i
                end[num] = i
            
            i += 1
        
        max = 0
        distance = 1

        for key, val in dict.items():
            if max < val:   
                max = val
                distance = end[key] - start[key] + 1
            elif max == val:
            	if end[key] - start[key] + 1 < distance:
            		distance = end[key] - start[key] + 1
   
        return distance

