class Solution {
public:
    string longestPalindrome(string s) {
        int size = s.size();
        if (size == 0) return s;
        
        vector< vector<int> > dp(size, vector<int>(size));
        for(int i=0; i< size; i++)
            dp[i][i] = 1;
        
        for(int i=0; i< size-1; i++)
            if (s[i] == s[i+1])
                dp[i][i+1] = 2;
            else
                dp[i][i+1] = 0;
        
        for(int d=2; d< size; d++){
            for(int i=0; i+d< size; i++){
                int j = i + d;
                if (dp[i+1][j-1] == 0 || s[i] != s[j])
                    dp[i][j] = 0;
                else
                    dp[i][j] = dp[i+1][j-1] + 2;
            }
        }
        
        for(int d=size-1; d>=0; d--){
            for(int i=0; i + d < size; i++){
                if (dp[i][i+d] != 0)
                    return s.substr(i, d+1);
            }
        }
    }
};