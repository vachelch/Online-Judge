class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        if (board[0].size() == 0) return 0;
        int sum = 0;
        int col = board[0].size();
        for (int j=0; j< col-1; j++)
            if (board[0][j] == 'X' && board[0][j+1] == '.')
                sum ++;

        if (board[0][col-1] == 'X')
            sum ++;
        
        for(int i=1; i< board.size(); i++){
            for(int j=0; j< col-1; j++){
                if (board[i][j] == 'X' && board[i-1][j] == '.' && board[i][j+1] == '.')
                    sum ++;
            }
            if (board[i][col-1] == 'X' && board[i - 1][col-1] == '.')
                sum ++;
        }
        
        return sum;
    }
};