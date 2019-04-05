class Solution:
    def maxArea(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        left = 0
        right = len(height)-1
        mx = 0

        while left < right:
        	if height[left] > height[right]:
        		mx = max(mx, (right-left)*height[right])
        		right -= 1
        	else:
        		mx = max(mx, (right-left)*height[left])
        		left += 1

        return mx


s = Solution()
height = [1,10, 1, 1000, 10, 1]
print(s.maxArea(height))