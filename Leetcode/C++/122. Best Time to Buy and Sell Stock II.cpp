// DP, State Machine Thingking
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size = prices.size();
        if (size == 0) return 0;

        int s0[size], s1[size]; // buy, sale, rest = {0};

        s0[0] = -prices[0];
        s1[0] = 0;

        for (int i=1; i< size; i++){
        	s0[i] = max(max(s0[i-1], s1[i-1] - prices[i]) , 0 - prices[i]); // buy, sale, rest;
        	s1[i] = max(s0[i-1] + prices[i], s1[i-1]);
        }

        return max(s1[size-1], 0);
    }
};



// Greedy
class Solution {
public:
	int maxProfit(vector<int>& prices) {
	    int total = 0;
	    for (int i=1; i< prices.size(); i++) {
	        if (prices[i]>prices[i-1]) total += prices[i]-prices[i-1];
	    }
	    
	    return total;
	}
};