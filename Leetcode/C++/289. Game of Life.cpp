#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	void dfs(vector<vector<int> >& board, int r, int c){
		int count = 0;
		for(int i= -1; i<= 1; i++){
			for(int j= -1; j<= 1; j++){
				if (!(i==0 && j==0) && 0<= r + i && r + i < board.size() && 0<= c + j && c + j < board[0].size())
					count += (board[r+i][c+j] & 1);
			}
		}

		if (board[r][c] == 1){
			if (count < 2 || count > 3)
				board[r][c] = 5; // 0, 101
			else
				board[r][c] = 7; // 1, 111
		}
		else{
			if (count == 3)
				board[r][c] = 6; //1, 110
			else
				board[r][c] = 4; //0, 100
		}

		for(int i= -1; i<= 1; i++){
			for(int j= -1; j<= 1; j++){
				if ((!(i==0 && j==0)) && (0<= r + i) && (r + i < board.size()) && (0<= c + j) && (c + j < board[0].size()) && (board[r+i][c+j] == 1 || board[r+i][c+j] == 0)){
					dfs(board, r+i, c+j);
				}
			}
		}

		
	}
    void gameOfLife(vector<vector<int> >& board) {
    	if (board.size()==0 || board[0].size() == 0) return ;
    	dfs(board, 0, 0);

    	for(int i=0; i< board.size(); i++)
    		for(int j=0; j< board[0].size(); j++)
    			board[i][j] =  (board[i][j] >> 1) & 1;
    }
};

int main(){
	int ipt[][3] = {{0,1,0},{0,0,1},{1,1,1},{0,0,0}};
	vector<vector<int> > board;
	for(int i=0; i< 4; i++){
		vector<int> row;
		for(int j=0; j< 3; j++)
			row.push_back(ipt[i][j]);

		board.push_back(row);

		Solution s;
		s.gameOfLife(board);

		return 0;
	}
}


