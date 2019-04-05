class Solution:
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        l = len(prices)
        if l <= 1: return 0

        profit = 0

        for i in range(1, l):
        	if prices[i] > prices[i-1]:
        		profit += prices[i] - prices[i-1]

        return profit


