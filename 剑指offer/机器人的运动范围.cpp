class Solution {
public:
    int helper(vector<vector<int> >& flag, int rows, int cols, int i, int j, int threshold){
        if (i<0 || i>= rows || j<0 || j>=cols || numSum(i) + numSum(j) > threshold || flag[i][j] == 1) return 0;
            
        flag[i][j] = 1;
        return helper(flag, rows, cols, i+1, j, threshold) + 
            helper(flag, rows, cols, i-1, j, threshold) + 
            helper(flag, rows, cols, i, j+1, threshold) + 
            helper(flag, rows, cols, i, j-1, threshold) + 1;
    }
    int numSum(int num){
        int sum = 0;
        while(num){
            sum += num % 10;
            num /= 10;
        }
        
        return sum;
    }
    int movingCount(int threshold, int rows, int cols)
    {
        vector<vector<int> > flag(rows, vector<int>(cols, 0));
        return helper(flag, rows, cols, 0, 0, threshold);
    }
};