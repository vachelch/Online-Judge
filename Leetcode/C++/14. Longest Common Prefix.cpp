// brute force
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) return "";
        string res = "";
        
        for(int j=0; j< strs[0].size(); j++){
            int next = 1;
            for(int i=0; i< strs.size(); i++){
                if (strs[i].size()-1 < j || strs[i][j] != strs[0][j]){
                    next = 0;
                    break;   
                }
            }
            if(!next)
                break;
            res.push_back(strs[0][j]);
        }
        return res;
    }
};



// dp
class Solution {
public:
    string CommonPrefix(string str_a, string str_b){
        int mn_size = min(str_a.size(), str_b.size());

        string common = "";
        for(int i=0; i< mn_size; i++){
            if (str_a[i] == str_b[i])
                common.push_back(str_b[i]);
            else
                break;
        }

        return common;
    }

    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) return "";
        if (strs.size() == 1) return strs[0];

        string res = CommonPrefix(strs[0], strs[1]);
        for(int i=2; i< strs.size(); i++){
            res = CommonPrefix(res, strs[i]);
        }

        return res;
    }
};


















