// DP, State Machine Thingking
class Solution {
public:
    int maxProfit(vector<int>& prices) {
    	int size = prices.size(); 
    	if (size == 0) return 0;

        int s0[size]; // buy
        int s1[size]; // sale
        int s2[size]; // cool down

        s0[0] = -prices[0];
        s1[0] = INT_MIN; // first action could not be sale
        s2[0] = 0;
        for(int i=1; i< size; i++){
        	s0[i] = max(s0[i-1], s2[i-1] - prices[i]);
        	s1[i] = s0[i-1] + prices[i];
        	s2[i] = max(s2[i-1], s1[i-1]);
        }

        return max(s1[size-1], s2[size-1]);
    }
};