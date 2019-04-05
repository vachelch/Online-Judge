class Solution {
public:
	vector<int> visited;
	vector<int> group;

	bool dfs(vector<vector<int>> & adj_list, int id, int gp){
		visited[id] = 1;
		group[id] = gp;
		for(auto adj: adj_list[id]){
			if (visited[adj] && group[adj] == gp)
				return false;
			if (visited[adj] == 0)
				if (!dfs(adj_list, adj, 1 - gp))
					return false;
		}
		return true;
	}

    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
  		visited.assign(N+1, 0);
  		vector<vector<int>> adj_list(N+1);
  		group.assign(N+1, -1);

  		for(auto it: dislikes){
  			adj_list[it[0]].push_back(it[1]);
  			adj_list[it[1]].push_back(it[0]);
  		}

  		for(int i=1; i<= N; i++){
  			if (visited[i] == 0){
  				if(!dfs(adj_list, i, 0))
  					return false;
  			}	
  		}

  		return true;
    }
};