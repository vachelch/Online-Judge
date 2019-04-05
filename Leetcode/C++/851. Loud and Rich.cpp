class Solution {
public:
    vector<vector<int>> adj_list;
    vector<int> visited;
    vector<int> res;
    
    void dfs(vector<vector<int>> &adj_list, int idx, vector<int>& quiet){
        visited[idx] = 1;
        
        for(int i=0; i < adj_list[idx].size(); i++){
            if (visited[adj_list[idx][i]] == 0)
                dfs(adj_list, adj_list[idx][i], quiet);
        }
        
        int mn = quiet[idx];
        int mn_id;
        for(int i=0; i < adj_list[idx].size(); i++){
            int q_id = res[adj_list[idx][i]];
            if (quiet[q_id] < mn){
                mn_id = q_id;
                mn = quiet[q_id];
            }
        }
        
        if (mn == quiet[idx])
            res[idx] = idx;
        else
            res[idx] = mn_id;
    }
    
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int size = quiet.size();
        visited.assign(size, 0);
        res.assign(size, 0);
        
        // construct adj_list
        for(int i=0; i< size; i++){
            vector<int> v;
            adj_list.push_back(v);
        }
        
        for(int i=0; i< richer.size(); i++)
            adj_list[richer[i][1]].push_back(richer[i][0]);
        
        
        for(int i=0; i< size; i++){
            if(visited[i] == 0){
                dfs(adj_list, i, quiet);
            }
        }
        
        return res;
    }
};