class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
    	int m = matrix.size();
    	if (m == 0) return false;
    	int n = matrix[0].size();
    	if (n ==0) return false;

    	int left = 0, right = m-1;

    	while(left <= right){
    		int middle = (left + right)/2;
    		if(matrix[middle][0] > target)
    			right = middle - 1;
    		else
    			left = middle + 1;
    	}

    	int limit = left -1;

    	for(int i=0; i<= limit; i++){
    		left = 0, right = n-1;

    		while(left <= right){
    			int middle = (left + right)/2;
    			if (matrix[i][middle] > target)
    				right = middle - 1;
    			else if(matrix[i][middle] < target)
    				left = middle + 1;
    			else
    				return true;
    		}
    	}

    	return false;
    }
};