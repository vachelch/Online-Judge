class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
    	int m = matrix.size();
    	int n = matrix[0].size();

    	int clear_r = 0;
    	int clear_c = 0;

    	//row0 and column0 exist 0
    	for(int i=0; i<m; i++)
    		if (matrix[i][0] == 0) clear_c = 1;
    	for(int j=0; j<n; j++)
    		if (matrix[0][j] == 0) clear_r = 1;

    	//
        for(int i=1; i<m; i++){
        	for(int j=1; j<n; j++){
        		if(matrix[i][j] == 0){
        			matrix[0][j] = 0;
        			matrix[i][0] = 0;
        		}
        	}
        }

        for(int i=1; i<m; i++){
        	if(matrix[i][0] == 0){
        		for(int j=1; j<n; j++)
        			matrix[i][j] = 0;
        	}
        }

        for(int j=1; j<n; j++){
        	if(matrix[0][j] == 0){
        		for(int i=1; i<m; i++)
        			matrix[i][j] = 0;
        	}
        }

        if(clear_r){
        	for(int j= 0; j<n; j++)
        		matrix[0][j] = 0;
        }
        if(clear_c){
        	for(int i= 0; i<m; i++)
        		matrix[i][0] = 0;
        }
    }
};








