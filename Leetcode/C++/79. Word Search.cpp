class Solution {
public:
    vector<vector<int> >visited;
    vector<int> adj_x;
    vector<int> adj_y;

    bool search(vector<vector<char>>& board, int i, int j, string word, int idx){
        if (idx == word.size() - 1 && board[i][j] == word[idx]) return true;
        if (board[i][j] != word[idx]) return false;
            
        visited[i][j] = 1;

        for(int k=0; k< 4; k++){
            int x = i + adj_x[k];
            int y = j + adj_y[k];

            if ( 0 <= x && x < board.size() && 0 <= y && y < board[0].size() && !visited[x][y] )
                if (search(board, x, y, word, idx+1)) return true;
        }
        visited[i][j] = 0;
            
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        if (board.size() == 0 || board[0].size() == 0) return false;
        
        int arr_x[] = {1, -1, 0, 0};
        int arr_y[] = {0, 0, -1, 1};

        adj_x.assign(arr_x, arr_x + 4);
        adj_y.assign(arr_y, arr_y + 4);

        for(int i=0; i< board.size(); i++){
            for(int j=0; j< board[0].size(); j++){
                visited.assign(board.size(), vector<int>(board[0].size(), 0));
                if (search(board, i, j, word, 0)) return true;
            }
        }
        
        return false;
    }
};