class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int la = A.size();
        int lb = B.size();
        int ans = 0;
        int dp[la][lb];

        for(int i=0; i<la; i++){
        	for(int j=0; j<lb; j++){
        		if(A[i] == B[j]){
        			if(i && j)
        				dp[i][j] = dp[i-1][j-1] + 1;
        			else
        				dp[i][j] = 1;
        		}
        		else
        			dp[i][j] = 0;

        		ans = max(ans, dp[i][j]);
        	}
        }

        return ans;
    }
};