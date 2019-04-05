// topological sort
class Solution {
public:
	vector<int> visited;
	map<int, int> topological;

	void dfs(vector<vector<int> > &adj_list, int idx){
		visited[idx] = 1;

		for(auto adj: adj_list[idx]){
			if (!visited[adj])
				dfs(adj_list, adj);
		}

		topological[idx] = topological.size();
	}

    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int> > adj_list(numCourses, vector<int>());

        for(auto arr: prerequisites){
        	adj_list[arr.second].push_back(arr.first);
        }
        visited.assign(numCourses, 0);

        for(int i=0; i< numCourses; i++){
        	if (!visited[i])
        		dfs(adj_list, i);
        }

        // check sequnence
        for(int i=0; i< numCourses; i++){
        	for(auto adj: adj_list[i]){
        		if (topological[adj] > topological[i]){
        			return false;
        		}		
        	}
        }

        return true;
        
    }
};








// check loop
class Solution {
public:
	vector<int> visited;
	vector<int> checked;

	bool dfs(vector<vector<int> > &adj_list, int idx){
		visited[idx] = 1;
		checked[idx] = 1;

		for(auto adj: adj_list[idx]){
			if (visited[adj] == 1)
				return false;
			else if (visited[adj] == 0)
				if (!dfs(adj_list, adj))
					return false;
		}

		visited[idx] = 2;

		return true;
	}

    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int> > adj_list(numCourses, vector<int>());

        // adj_list
        for(auto arr: prerequisites){
        	adj_list[arr.second].push_back(arr.first);
        }

        // check
        checked.assign(numCourses, 0);

        for(int i=0; i< numCourses; i++){
        	if (!checked[i]){
        		visited.assign(numCourses, 0);
        		if (!dfs(adj_list, i))
        			return false;
        	}
        }

        return true;
        
    }
};

















