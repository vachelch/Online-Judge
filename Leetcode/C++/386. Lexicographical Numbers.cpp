class Solution {
public:
    vector<int> res;
    void dfs(int num, int target){
        for(int i=0; i< 10; i++){
            int cur = num * 10 + i;
            if (cur <= target && cur != 0){
                res.push_back(num * 10 + i);
                dfs(num * 10 + i, target);
            }
        }
    }
        
    vector<int> lexicalOrder(int n) {
        dfs(0, n);
        
        return res;
    }
};