class Solution:
    def selfDividingNumbers(self, left, right):
        """
        :type left: int
        :type right: int
        :rtype: List[int]
        """
        def self_dividing(num):
        	copy = num
        	while copy > 0:
        		divide = copy % 10
        		copy //= 10
        		if divide == 0 or num % divide != 0:
        			return 0
        	return 1

        result = []
        for i in range(left, right+1):
        	if self_dividing(i):
        		result.append(i)

        return result
































