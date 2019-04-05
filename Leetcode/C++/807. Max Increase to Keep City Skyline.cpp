class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();

        vector<int>row(r, 0);
        vector<int>col(c, 0);

        for(int i=0; i< r; i++)
        	for(int j = 0; j< c; j++)
        		row[i] = max(row[i], grid[i][j]);

        for(int i=0; i< c; i++)
        	for(int j = 0; j< r; j++)
        		col[i] = max(col[i], grid[j][i]);

        int sum = 0;
        for(int i=0; i< r; i++)
        	for(int j=0; j< c; j++)
        		sum += min(row[i], col[j]) - grid[i][j];

        return sum;
    }
};