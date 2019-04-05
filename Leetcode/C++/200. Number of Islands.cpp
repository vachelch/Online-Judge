// dfs
class Solution {
public:
	int m, n;
	vector<int> xp;
	vector<int> yp;

	void dfs(vector<vector<char>>& grid, vector<vector<int>>& visited, vector<vector<int>>& pi, int x, int y){
		visited[x][y] = -1;

		for(int i=0; i< 4; i++){
			int X = x+xp[i];
			int Y = y+yp[i];
			if ((0 <= X) && (X < m) && (0 <= Y) && (Y < n) && (!visited[X][Y]) && (grid[X][Y] == '1')){
				pi[X][Y] = 1;
				dfs(grid, visited, pi, X, Y);
			}
		}
	}

    int numIslands(vector<vector<char>>& grid) {
    	m = grid.size();
    	if (m == 0) return 0;

    	n = grid[0].size();
    	int xp_[] = {1, -1, 0, 0};
		int yp_[] = {0, 0, 1, -1};

		xp.assign(xp_, xp_+4);
		yp.assign(yp_, yp_+4);

      	vector<vector<int> >visited(m, vector<int>(n, 0));
      	vector<vector<int> >pi(m, vector<int>(n, 0));

      	for(int i=0; i< m; i++){
      		for(int j=0; j< n; j++){
      			if (grid[i][j] == '1' && !visited[i][j]){
      				dfs(grid, visited, pi, i, j);
      			}
      		}
      	}

      	int res = 0;
      	for(int i=0; i< m; i++){
      		for(int j=0; j< n; j++){
      			res += (grid[i][j] == '1' && !pi[i][j]);
      		}
      	}
      		
      	return res;
    }
};



// Union find, BUG involved
class Solution {
public:
	void Merge(vector<vector<pair<int, int> > >& pi, int x, int y, int X, int Y){
		pair<int, int> p1 = findU(pi, x, y);
		pair<int, int> p2 = findU(pi, X, Y);

		if (p1.first < p2.first || (p1.first == p2.first && p1.second < p2.second)){
			pi[p2.first][p2.second] = p1;
		}
		else
			pi[p1.first][p1.second] = p2;
	}

	pair<int, int> findU(vector<vector<pair<int, int> > >& pi, int x, int y){
		while(pi[x][y].first != -1){
			int tmp = pi[x][y].first;
			y = pi[x][y].second;
			x = tmp;
		}

		return make_pair(x, y);
	}

    int numIslands(vector<vector<char>>& grid) {
    	int m = grid.size();
    	if (m == 0) return 0;

    	int n = grid[0].size();
    	vector<vector<pair<int, int> > >pi(m, vector<pair<int, int> >(n, make_pair(-1, -1)));

    	int xp_[] = {0, 1};
		int yp_[] = {1, 0};

		vector<int> xp(xp_, xp_+2);
		vector<int> yp(yp_, yp_+2);

      	for(int i=0; i< m; i++){
      		for(int j=0; j< n; j++){
      			if (grid[i][j] == '1'){
      				for(int k=0; k< 2; k++){
	      				int X = i+xp[k];
						int Y = j+yp[k];
						if ((0 <= X) && (X < m) && (0 <= Y) && (Y < n) && (grid[X][Y] == '1'))
							Merge(pi, i, j, X, Y);
	      			}
      			}
      		}
      	}

      	int res = 0;
      	for(int i=0; i< m; i++){
      		for(int j=0; j< n; j++){
      			res += (grid[i][j] == '1' && pi[i][j].first == -1);
      		}
      	}
      		
      	return res;
    }
};