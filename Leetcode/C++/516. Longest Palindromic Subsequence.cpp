class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int size = s.size();
        
        int dp[size][size];
        for(int i=0; i< size; i++)
            dp[i][i] = 1;
        for(int i=0; i< size-1; i++)
            if(s[i] == s[i+1])
                dp[i][i+1] = 2;
            else
                dp[i][i+1] = 1;
        
        for(int d=2; d<size; d++){
            for(int i=0; i + d < size; i++){
                if(s[i] == s[i+d])
                    dp[i][i+d] = dp[i+1][i+d-1] + 2;
                else
                    dp[i][i+d] = max(dp[i+1][i+d], dp[i][i+d-1]);
            }
        }
        
        return dp[0][size-1];
    }
};