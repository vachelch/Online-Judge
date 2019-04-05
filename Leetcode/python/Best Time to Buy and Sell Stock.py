class Solution:
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        if not prices: return 0

        buy_price = prices[0]
        maxprofit = 0

        for price in prices:
        	maxprofit = max(maxprofit, price - buy_price)
        	buy_price = min(price, buy_price)

        return maxprofit


prices = [7, 1, 5, 3, 6, 4]
s = Solution()
print(s.maxProfit(prices))








