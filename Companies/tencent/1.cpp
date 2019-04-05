// AC
// recursion, find the rule
class GrayCode {
public:
    void helper(int n, vector<string>& res){
        if (n == 1){
            res.push_back("0");
            res.push_back("1");
            return ;
        }
        helper(n-1, res);
        vector<string> res_reverse;
        for(int i=res.size()-1; i>= 0; i--){
            res_reverse.push_back("1" + res[i]);
            res[i] = "0" + res[i];
        }
        
        for(int i=0; i< res_reverse.size(); i++)
            res.push_back(res_reverse[i]);
    }
    vector<string> getGray(int n) {
        // write code here
        if (n < 1) return vector<string>();
        vector<string> res;
        helper(n, res);
        
        return res;
    }
};