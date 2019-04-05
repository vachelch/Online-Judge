// dp
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
    	int size = strs.size();
    	if (size == 0) return 0;

        int dp[m+1][n+1];
        memset(dp, 0, (m+1)*(n+1)* sizeof(int)); // Do not use dp[m+1][n+1] = {{0}} as initializeation !

        for(int k=0; k< size; k++){
        	int zero = 0;
        	int one = 0;

        	for(auto c: strs[k]){
        		if (c - '0')
        			one ++;
        		else
        			zero ++;
        	}

        	for(int i=m; i>= zero; i--){
        		for(int j=n; j>= one; j--){
        			dp[i][j] = max(dp[i][j], dp[i- zero][j - one] + 1);
        		}
        	}
        }
        return dp[m][n];
    }
};