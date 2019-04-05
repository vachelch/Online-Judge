class Solution {
public:
    set<string> res;
    void swap(string& str, int i, int j){
        char tmp = str[i];
        str[i] = str[j];
        str[j] = tmp;
    }
    void permute(string &str, int idx){
        if (idx == str.size()){
            res.insert(str);
        }
        else{
            for(int i=idx; i< str.size(); i++){
                swap(str, i, idx);
                permute(str, idx+1);
                swap(str, i, idx);
            }
        }
    }
    vector<string> Permutation(string str) {
        if (str.empty()) return vector<string>();
        
        permute(str, 0);
        
        return vector<string> (res.begin(), res.end());
    }
};


// 列出整數陣列所有n個數字的排列
// 列出整數陣列所有n個數字的組合
// https://programming.im.ncnu.edu.tw/J_index.html