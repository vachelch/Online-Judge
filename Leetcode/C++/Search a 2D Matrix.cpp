class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
    	int m = matrix.size();
    	if (m == 0) return false;

    	int n = matrix[0].size();

    	int top = 0;
    	int below = m-1;

    	while (top < below){
    		int middle = (top + below)/2;
    		if (matrix[middle][0] > target)
    			below = middle - 1;
    		else if(matrix[middle][n-1] < target)
    			top = middle + 1;
    		else{
    			top = middle;
    			break;
    		}
    	}

    	int left = 0;
    	int right = n-1;

    	while (left <= right){
    		int middle = (left + right)/2;
    		if(matrix[top][middle] > target)
    			right = middle - 1;
    		else if(matrix[top][middle] < target)
    			left = middle + 1;
    		else
    			return true;
    	}

    	return false;
    }
};