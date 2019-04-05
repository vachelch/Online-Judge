# Definition for an interval.
# class Interval:
#     def __init__(self, s=0, e=0):
#         self.start = s
#         self.end = e

class Solution:
    def merge(self, intervals):
        """
        :type intervals: List[Interval]
        :rtype: List[Interval]
        """
        l = len(intervals)
        if l == 0: return []

        intervals.sort(key = lambda x: x.start)

        res = [intervals[0]]

        for i in range(1, l):
        	start, end = intervals[i].start, intervals[i].end
        	if start <= res[-1].end:
        		res[-1].end = max(res[-1].end, end)
        	else:
        		res.append(intervals[i])

        return res






















