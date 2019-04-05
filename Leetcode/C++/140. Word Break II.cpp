class Solution {
public:
    bool canBreak(string s, set<string>& word_set){
        vector<bool> can_break(s.size(), false);

        for(int i=0; i< s.size(); i++)
            for(int j=i; j>= 0; j--){
                if (j == 0 || can_break[j-1]){
                    string tmp = s.substr(j, i-j+1);
                    if (word_set.find(tmp) != word_set.end()){
                        can_break[i] = true;
                        break;
                    }
                }
            }

        return can_break.back();
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        set<string> word_set;
        for(auto word: wordDict)
            word_set.insert(word);
        
        if (!canBreak(s, word_set)) return vector<string>();

        vector<vector<string> > dp(s.size(), vector<string>());
        
        for(int i=0; i< s.size(); i++)
            for(int j=i; j>= 0; j--){
                if (j == 0 || !dp[j-1].empty()){
                    string tmp = s.substr(j, i-j+1);
                    if (word_set.find(tmp) != word_set.end()){
                        if (j == 0){
                            dp[i].push_back(tmp);
                        }
                        else{
                            for(auto seq: dp[j-1]){
                                seq += " " + tmp;
                                dp[i].push_back(seq);
                            }
                        }
                    }
                }
            }
        
        return dp.back();
    }
};