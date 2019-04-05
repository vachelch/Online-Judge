class Solution {
public:
    /**
     * @param n an integer
     * @return a list of pair<sum, probability>
     */
    vector<pair<int, double>> dicesSum(int n) {
        // Write your code here
        vector<pair<int, double>> res;
        if (n <= 0) return res;

        vector<vector<double>> dp(n, vector<double>(6*n+1, 0));
        double poss = 1;
        poss /= 6;

        for(int j=1; j<= 6; j++){
        	dp[0][j] = poss;
        }

        for(int i=1; i < n; i++){
    		for(int j= i+1; j <= 6*(i+1); j++){
    			for (int k=1; k<=6; k++){
    				dp[i][j] += dp[i-1][j-k] * poss;
    			}
    		}	
        }
        
        for (int i= n; i<= 6*n; i++){
        	res.push_back(make_pair(i, dp[n-1][i]));
        }
        return res;
    }
}; 