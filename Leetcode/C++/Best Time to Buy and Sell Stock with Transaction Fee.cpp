class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int l = prices.size();
        if(l<=1) return 0;

        int cash = 0, hold = -prices[0];
        for(int i=1; i<l; i++){
        	cash = max(cash, hold + prices[i] - fee);
        	hold = max(hold, cash - prices[i]);
        }
        return cash;
    }
};