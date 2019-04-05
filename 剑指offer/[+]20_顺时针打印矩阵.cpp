class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        int start = 0, height = matrix.size();
        vector<int> res;
        if (height == 0) return res;
        
        int width = matrix[0].size();
        if (width == 0) return res;
        int top = start, bottom = start + height - 1;
        int left = start, right = start + width -1;
        
        while((start+1) * 2 <= matrix.size() && (start+1) * 2 <= matrix[0].size()){
            for(int i=left; i< right; i++)
                res.push_back(matrix[top][i]);
            for(int i=top; i< bottom; i++)
                res.push_back(matrix[i][right]);
            for(int i=right; i> left; i--)
                res.push_back(matrix[bottom][i]);
            for(int i=bottom; i> top; i--)
                res.push_back(matrix[i][left]);
            
            ++ start;
            width -= 2, height -= 2;
            top = start, bottom = start + height - 1;
            left = start, right = start + width -1;
        }
        
        if (start*2 +1 == matrix.size()){
            for(int i=left; i<= right; i++)
                res.push_back(matrix[start][i]);
        }
        else if (start*2 +1 == matrix[0].size()){
            for(int i=top; i<= bottom; i++)
                res.push_back(matrix[i][start]);
        }
        
        return res;
    }
};