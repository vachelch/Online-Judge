class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        if (s.size() == 0) return false;
        
        set<string>dict;
        for(auto word: wordDict)
            dict.insert(word);
        
        vector<bool> dp(s.size(), false);
        
        for(int i=0; i< s.size(); i++){
            for(int j=i; j>=0; j--){
                if(j == 0 || dp[j-1]){
                    if (dict.find(s.substr(j, i-j+1)) != dict.end()){
                        dp[i] = true;
                        break;
                    }
                }
            }
        }
        
        return dp.back();
    }
};