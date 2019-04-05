class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<int> arr(n+1, INT_MAX);
        arr[0] = 0;


        for(int i=0; i<m; i++){
        	for(int j=1; j<=n; j++)
        		arr[j] = grid[i][j-1]+ min(arr[j], arr[j-1]);
        	if(i == 0)
        		arr[0] = INT_MAX;
        }
        	

       	return arr[n];
    }
};