// dfs
class Solution {
private:
    vector<int> visited;
    vector<int> pi;
public:
    void dfs(vector<vector<int>>& M, int i){
        visited[i] = 1;
        for(int j = 0; j< M[0].size(); j++){
            if (M[i][j] == 1){
                if (visited[j] == 0){
                    pi[j] = i;
                    dfs(M, j);
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& M) {
        visited.assign(200, 0);
        pi.assign(200, -1);
        for(int i=0; i< M.size(); i++)
            if (visited[i] == 0)
                dfs(M, i);
        
        int res = 0;
        for(int i=0; i< M.size(); i++)
            res += (pi[i] == -1);
        
        return res;
    }
};