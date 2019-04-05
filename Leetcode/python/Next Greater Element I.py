class Solution:
    def nextGreaterElement(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: List[int]
        """
        dic = {}
        stack = []
        for item in nums2:
        	while len(stack) > 0 and item > stack[-1]:
        		dic[stack.pop()] = item
        	stack.append(item)

        for item in stack:
        	dic[item] = -1

        output = []
        for item in nums1:
        	output.append(dic[item])
        return output


s = Solution()
nums1 = [2,4]
nums2 = [1,2,3,4]

print(s.nextGreaterElement(nums1, nums2))

