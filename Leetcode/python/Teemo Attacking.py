class Solution:
    def findPoisonedDuration(self, timeSeries, duration):
        """
        :type timeSeries: List[int]
        :type duration: int
        :rtype: int
        """
        l = len(timeSeries)
        if  l==0: return 0
        res = 0
        for i in range(1, l):
        	period = timeSeries[i] - timeSeries[i-1]
        	period = min(duration, period)
        	res += period

        res += duration

        return res