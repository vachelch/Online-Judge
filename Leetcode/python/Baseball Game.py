class Solution:
    def calPoints(self, ops):
        """
        :type ops: List[str]
        :rtype: int
        """
        stack = []
        for item in ops:
        	if item == '+':
        		stack.append(stack[-2] + stack[-1])
        	elif item == 'D':
        		stack.append(stack[-1] * 2)
        	elif item == 'C':
        		stack.pop()
        	else:
        		stack.append(int(item))
        return sum(stack)

s = Solution()
ops = ["5","-2","4","C","D","9","+","+"]
print(s.calPoints(ops))








