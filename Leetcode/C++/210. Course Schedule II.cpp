class Solution {
public:
	vector<int> topology;
	vector<int> visited;

	void dfs(vector<vector<int> > &adj_list, int idx){
		visited[idx] = 1;

		for(auto adj: adj_list[idx]){
			if (!visited[adj])
				dfs(adj_list, adj);
		}

		topology.push_back(idx);
	}
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int> > adj_list(numCourses, vector<int>());
        visited.assign(numCourses, 0);

        for(auto edge: prerequisites)
        	adj_list[edge.second].push_back(edge.first);

        for(int i=0; i< numCourses; i++)
        	if (!visited[i])
        		dfs(adj_list, i);

        // check topology sequence
        map<int, int>topo_map;
        for(int i=0; i< numCourses; i++)
        	topo_map[topology[i]] = i;

        for(auto edge: prerequisites){
        	if (topo_map[edge.second] < topo_map[edge.first])
        		return vector<int>();
        }

        // return reversed topology
        vector<int> topo_ascend;
        for(int i=topology.size()-1; i >=0; i--)
        	topo_ascend.push_back(topology[i]);

        return topo_ascend;
    }
};