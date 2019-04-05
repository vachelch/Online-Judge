// AC
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        int r_plus[] = {-1, 1};
        int c_plus[] = {1, -1};
        int direc = 0;
        vector<int> res;
        int M = matrix.size();
        if(M == 0) return res;

        int N = matrix[0].size();

        int r, c;
        for(int i=0; i< M+N - 1; i++){	
        	if (direc == 0){
        		r = i, c = 0;
        		while(r >= 0){
        			if (0 <= r && r < M && 0 <= c && c < N)
        				res.push_back(matrix[r][c]);
        			r += r_plus[direc];
        			c += c_plus[direc];
        		}
        	}
        	else{
        		r = 0, c = i;
        		while(c >= 0){
        			if (0 <= r && r < M && 0 <= c && c < N)
        				res.push_back(matrix[r][c]);
        			r += r_plus[direc];
        			c += c_plus[direc];
        		}
        	}
        	direc = 1 - direc;
        }

        return res;
    }
};