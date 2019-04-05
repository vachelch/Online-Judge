class Solution {
public:
	vector<int> visited;

	bool isloop(vector<vector<int>>& graph, int i){
		if (visited[i] != 0) return (visited[i] == 1);

		visited[i] = 1;

		for(auto adj: graph[i]){
			if (visited[adj] == 1){
				return true;
			}
			else{
				if (isloop(graph, adj))
					return true;
			}
		}

		visited[i] = 2;

		return false;
	}
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
    	int size = graph.size();
		visited.assign(size, 0);
		
		vector<int> res;

        for(int i=0; i< size; i++){
        	if (!isloop(graph, i)) res.push_back(i);
        }

        return res;
    }
};