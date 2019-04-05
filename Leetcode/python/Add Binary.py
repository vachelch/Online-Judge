class Solution:
    def addBinary(self, a, b):
        """
        :type a: str
        :type b: str
        :rtype: str
        """
        def binary_to_ten(s):
        	sum_ = 0
        	for i in range(len(s)):
        		sum_ = sum_*2 + int(s[i])
        	return sum_


        def ten_to_binary(num):
        	res = []
        	while num > 0:
        		res.append(num%2)
        		num //= 2
        	sum_ = 0
        	for i in range(len(res)-1, -1, -1):
        		sum_ = sum_*10 + res[i]
        	return sum_

        res = binary_to_ten(a) + binary_to_ten(b)
        return str(ten_to_binary(res))

