class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        if (m==0) return 0;
        int n = matrix[0].size();

        vector<vector<int>> dp;

        //assign matrix
        for(int i=0; i<m; i++){
        	dp.push_back(vector<int> {});
        	for(int j=0; j<n;j++)
        		dp[i].push_back(matrix[i][j] - '0');
        }

        for(int i=0; i<m; i++){
        	for(int j=0; j<n; j++)
        		cout<<dp[i][j]<<' ';
        	cout<<endl;
        }

        int mx_border = 0;

        //assign dp row 0
        for(int j=0; j<n; j++)
        	mx_border = max(mx_border, dp[0][j]);

        //
        for(int i=0; i<m; i++)
        	mx_border = max(mx_border, dp[i][0]);

        for(int i=1; i<m; i++)
        	for(int j=1; j<n; j++)
        		if (dp[i][j] == 1){
        			dp[i][j] = min(dp[i][j-1], dp[i-1][j], dp[i-1][j-1]) + 1;
        			mx_border = max(mx_border, dp[i][j]);
        		}

        return mx_border*mx_border;
    }
};


