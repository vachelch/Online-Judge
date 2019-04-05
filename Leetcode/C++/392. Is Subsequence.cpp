// dp
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int l_t = t.size();
        int l_s = s.size();
        
        if (l_s == 0) return true;
        
        int dp[l_s+1] = {0};
        int last[l_s+ 1] = {0};
        for(int i=1; i<= l_t; i++){
            for(int j=1; j<= l_s; j++){
                last[j] = dp[j];
                if (t[i-1] == s[j-1]){
                    dp[j] = last[j-1] + 1;
                }
                else{
                    dp[j] = max(dp[j], dp[j-1]);
                }
            }
            if (dp[l_s] == l_s)
                return true;
        }
        
        return false;
    }
};


// greedy, faster
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int l_t = t.size();
        int l_s = s.size();
        
        int i=0, j=0;
        while(i < l_s && j < l_t){
            if(s[i] == t[j]){
                i++;
                j++;
            }
            else{
                j++;
            }
        }

        if(i == l_s)
            return true;
        else
            return false;
    }
};






















