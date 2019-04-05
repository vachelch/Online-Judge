// set, beat 33.48%
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0; i< 9; i++){
        	set<int> st;
        	for(int j=0; j< 9; j++){
        		if (board[i][j] != '.'){
        			if (st.find(board[i][j]) != st.end())
	        			return false;
	        		else
	        			st.insert(board[i][j]);
	        	}
        	}
        }

        for(int j=0; j< 9; j++){
        	set<int> st;
        	for(int i=0; i< 9; i++){
        		if (board[i][j] != '.'){
        			if (st.find(board[i][j]) != st.end())
	        			return false;
	        		else
	        			st.insert(board[i][j]);
        		}
        	}
        }

        for(int i=0; i< 9; i += 3){
        	for(int j=0; j< 9; j += 3){
        		set<int> st;
	        	for(int k=0; k< 3; k++){
	        		for(int l=0; l<3; l++){
	        			if (board[i+k][j+l] != '.'){
	        				if (st.find(board[i+k][j+l]) != st.end())
			        			return false;
			        		else
			        			st.insert(board[i+k][j+l]);
	        			}
	        		}
	        	}
        	}
        }

        return true;
        	
    }
};


// trace onece, beat 97.6%
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
    	int row[9][9] = {{0}}, col[9][9] = {{0}}, box[9][9] = {{0}};
        for(int i=0; i< 81; i++){
        	int r = i / 9;
        	int c = i % 9;

        	if (board[r][c] == '.') continue;

        	int idx = board[r][c] - '1';
        	int b = r / 3 * 3 + c / 3;

        	if (row[r][idx] ++) return false;
        	if (col[c][idx] ++) return false;
        	if (box[b][idx] ++) return false;
		}	

		return true;
    }
};
































