class Solution:
    def plusOne(self, digits):
        """
        :type digits: List[int]
        :rtype: List[int]
        """
        l = len(digits)
        i = l -1
        while i >= 0:
        	if digits[i] == 9:
        		digits[i] = 0
        	else:
        		digits[i] += 1
        		return digits
        	i -= 1

        new_digits = [1 for x in range(l+1)]
        new_digits[1:] = digits[:]

        return new_digits

s = Solution()
digits = [9, 9 ,9 ,9]
print(s.plusOne(digits))
