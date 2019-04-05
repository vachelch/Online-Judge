class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.size()==0 || matrix[0].size() == 0) return 0;
        
        int neighbors[][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> cache(m, vector<int>(n, 0));
        
        int mx = 1;
        for (int i=0; i< m; i++)
            for (int j=0; j< n; j++){
                mx = max(mx, dfs(i, j, cache, matrix, neighbors));
            }
        
        return mx;
    }
    
    int dfs(int i, int j, vector<vector<int>>& cache, vector<vector<int>>& matrix, int neighbors[][2]){
        if (cache[i][j] != 0) return cache[i][j];
        
        int m = matrix.size();
        int n = matrix[0].size();
        int length = 1;
        for(int k=0; k< 4; k++){
                int x = i + neighbors[k][0];
                int y = j + neighbors[k][1];

                if (0<= x && x < m && 0<= y && y < n && matrix[x][y] > matrix[i][j]){
                    length = max(length, dfs(x, y, cache, matrix, neighbors) + 1);
                }
        }
        
        cache[i][j] = length;
        return length;
    }
};