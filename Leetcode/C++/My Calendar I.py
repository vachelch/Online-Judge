class MyCalendar:

    def __init__(self):
        self.l = 0
        self.res = []

    def book(self, start, end):
        """
        :type start: int
        :type end: int
        :rtype: bool
        """
        for left, right in self.res:
        	if not (end <= left or start >= right): return False
        self.res.append((start, end))
        return True



# Your MyCalendar object will be instantiated and called as such:
# obj = MyCalendar()
# param_1 = obj.book(start,end)