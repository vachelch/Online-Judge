class Solution {
public:
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
    	int size = A.size();
    	int res = 0, sm;

        for(int i= 1 - size; i< size; i++){
        	for(int j= 1 - size; j< size; j++){
        		sm = 0;
        		for(int k = 0; k< size; k++){
        			for(int l=0; l< size; l++){
        				int x = i + k, y = j + l;
        				if (0<= x && x < size && 0<= y && y < size){
        					sm += A[k][l] & B[x][y];
        				}
        			}
        		}
        		res = max(res, sm);
        	}
        }

        return res;
    }
};