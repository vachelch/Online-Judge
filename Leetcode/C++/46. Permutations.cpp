class Solution {
    
public:
    vector <vector<int>> res;
    void dfs(vector<int>& cur, vector<int>& back){
        if (back.size() == 0) res.push_back(cur);
        
        for(int i=0; i< back.size(); i++){
            int num = back[i]; // this line is very important! or back[i] will change because of action back.erase()
            cur.push_back(num);
            back.erase(back.begin() + i);

            dfs(cur, back);

            cur.pop_back();
            back.insert(back.begin() + i, num);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> cur;
        dfs(cur, nums);
        
        return res;
    }
};