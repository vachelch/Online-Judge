class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        
        int res = 0;
        for(int i=0; i<m; i++){
            int mx = -1;
            for(int j=0; j< n; j++){
                mx = max(grid[i][j], mx);
                res += (grid[i][j] > 0);
            }
            res += mx;
        }
        
        for(int j = 0; j < n; j++){
            int mx = -1;
            for(int i=0; i< m; i++)
                mx = max(mx, grid[i][j]);
            res += mx;
        }
        
        return res;
    }
};