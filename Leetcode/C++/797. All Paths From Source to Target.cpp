void dfs(vector<vector<int>>& graph, vector<vector<int>> &res, int pos, vector<int> &path){
    if (pos == graph.size() - 1){
        res.push_back(path);
        return; 
    }
    for(int i=0; i< graph[pos].size(); i++){
        vector<int> tmp;
        tmp = path;
        tmp.push_back(graph[pos][i]);
        dfs(graph, res, graph[pos][i], tmp);
    }
}

class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> res;
        vector<int> path(1, 0);
        dfs(graph, res, 0, path);
        return res;
    }
};