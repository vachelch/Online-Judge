class Solution {
private:
	int plus_x[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
	int plus_y[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
public:
	void reveal(vector<vector<char>>& board, int x, int y){
		if (board[x][y] == 'E'){
			int sm = 0;
			for(int i = 0; i < 8; i++){
				if( (0 <= x + plus_x[i]) && (x + plus_x[i] < board.size()) && (0 <= y + plus_y[i]) && (y + plus_y[i] < board[0].size()))
					sm += (board[x + plus_x[i]][y + plus_y[i]] == 'M');
			}

			if (sm != 0)
				board[x][y] = sm + '0';
			else{
				board[x][y] = 'B';
				for(int i = 0; i < 8; i++){
					if( (0 <= x + plus_x[i]) && (x + plus_x[i] < board.size()) && (0 <= y + plus_y[i]) && (y + plus_y[i] < board[0].size()))
						reveal(board, x + plus_x[i], y + plus_y[i]);
				}
			}
		}
	}
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        if (board[click[0]][click[1]] == 'M'){
        	board[click[0]][click[1]] = 'X';
        	return board;
        }
        else{
        	reveal(board, click[0], click[1]);
        	return board;
        }
    }
};