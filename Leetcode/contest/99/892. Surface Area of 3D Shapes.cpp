class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
    	int m = grid.size(); 
    	if (m == 0) return 0;
    	int n = grid[0].size();

    	int res = 0;
    	for(int i=0; i< m; i++){
    		for(int j=0; j< n; j++){
    			res += 4 * grid[i][j];
    			if (grid[i][j] != 0)
    				res += 2;

    			if (i != 0)
    				res -= 2*min(grid[i-1][j], grid[i][j]);

    			if (j != 0)
    				res -= 2*min(grid[i][j], grid[i][j-1]);
    		}	
    	}


    	return res;
    }
};