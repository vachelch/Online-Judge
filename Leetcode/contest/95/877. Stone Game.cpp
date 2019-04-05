// dp
class Solution {
public:
    bool stoneGame(vector<int>& piles) {
    	int len = piles.size();
    	vector<vector<int>> dp(len, vector<int> (len));

    	for(int i=0; i< len; i++)
    		dp[i][i] = piles[i];

    	for(int d=1; d < len; d++)
    		for(int i = 0; i< len-d; i++)
    			dp[i][i+d] = max(piles[i] - dp[i+1][i+d], piles[i+d] - dp[i][i+d-1]);
        
        return dp[0][len-1] > 0;
    }
};





// solution 2
class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        return true;
    }
};