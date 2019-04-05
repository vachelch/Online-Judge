class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int dp[1001][1001] = {0};
        int s1_len = s1.size(), s2_len = s2.size();
        for(int i= s1_len-1; i>= 0; i--)
            dp[i][s2_len] = dp[i+1][s2_len] + s1[i];
        for(int j= s2_len-1; j>= 0; j--)
            dp[s1_len][j] = dp[s1_len][j+1] + s2[j];
        
        for(int i = s1_len-1; i >= 0; i--){
            for(int j = s2_len-1; j >= 0; j--){
                if (s1[i] == s2[j])
                    dp[i][j] = dp[i+1][j+1];
                else
                    dp[i][j] = min(dp[i][j+1] + s2[j], dp[i+1][j] + s1[i]);
            }
        }
        
        return dp[0][0];
    }
};