class Solution {
public:
    vector<int> x_plus;
    vector<int> y_plus;
    
    bool dfs(vector<vector<char> >& board, vector<vector<pair<int, int> > >& groups, int i, int j, int inix, int iniy){
        if (i == 0 || i == board.size()-1 || j == 0 || j == (board[0].size()-1)){
            return false;
        }
        
        int edgeO = 0;
        for(int k=0; k< 4; k++){
            int x = i + x_plus[k];
            int y = j + y_plus[k];
            
            if (0 <= x && x < board.size() && 0 <= y && y < board[0].size() && board[x][y] == 'O' && groups[x][y].first == -1){
                groups[x][y] = make_pair(inix, iniy);
                if (!dfs(board, groups, x, y, inix, iniy)){
                    edgeO = 1;
                }
            }
        }
        
        return edgeO == 0? true : false;
    }
        
    void solve(vector<vector<char> >& board) {
    	if (board.size() == 0) return;

        int x_p[4] = {1,-1,0,0};
        int y_p[4] = {0,0,1,-1};
        x_plus.assign(x_p, x_p+4);
        y_plus.assign(y_p, y_p+4);
        
        vector<vector<pair<int, int> > > groups(board.size(), vector<pair<int, int> >(board[0].size(), make_pair(-1, -1)));
       

        for(int i=1; i< board.size()-1; i++){
            for(int j=1; j< board[0].size()-1; j++){
                // 'O' appear
                if (groups[i][j].first == -1 && board[i][j] == 'O'){
                	// all neighbors don't apppear in edge
                    groups[i][j] = make_pair(i, j);
                    if (dfs(board, groups, i, j, i, j)){
                        board[i][j] = 'X';
                    }
                }   
            }
        }
        
        for(int i=1; i< board.size()-1; i++){
            for(int j=1; j< board[0].size()-1; j++){
                if (board[i][j] == 'O'){
                    pair<int, int> coord = groups[i][j];
                    board[i][j] = board[coord.first][coord.second];   
                }
            }
        }
    }
};