class MinStack:

    def __init__(self):
        """
        initialize your data structure here.
        """
        self.stack = []
        self.min_stack = []

    def push(self, x):
        """
        :type x: int
        :rtype: void
        """
        self.stack.append(x)
        if len(self.min_stack) == 0 or x < self.min_stack[-1]:
            self.min_stack.append(x)
        

    def pop(self):
        """
        :rtype: void
        """
        if self.stack[-1] == self.min_stack[-1]:
            self.min_stack.pop()
        self.stack.pop()
        

    def top(self):
        """
        :rtype: int
        """
        return self.stack[-1]    

    def getMin(self):
        """
        :rtype: int
        """
        return self.min_stack[-1]

# # Your MinStack object will be instantiated and called as such:
# minStack = MinStack()
# minStack.push(-2)
# minStack.push(0)
# minStack.push(-3)
# print(minStack.getMin())
# minStack.pop()
# # print(minStack.top())
# print(minStack.getMin())


























