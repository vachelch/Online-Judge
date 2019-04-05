class Trie{
public:
	int isEnd;
	map<char, Trie *> childrens;

	Trie(){
		isEnd = 0;
	}
};

void Insert(Trie * trie, string word){
	Trie * cur = trie;
	for (int i=0; i< word.size(); i++){
		char chr = word[i];
		if (cur->childrens.find(chr) != cur->childrens.end()){
			cur = cur->childrens[chr];
			
			if (i == word.size() - 1)
				cur->isEnd = 1;
		}
		else{
			Trie * trieNode = new Trie;
			if (i == word.size() - 1)
				trieNode->isEnd = 1;

			cur->childrens[chr] = trieNode;
			cur = cur->childrens[chr];
		}
	}
}

class Solution {
public:
	set<string> res_st;
	vector<int> x_p;
	vector<int> y_p;
	vector<vector<int> > visited;

	void dfs(vector<vector<char>>& board, int i, int j, Trie * trieNode, string word){
		if (trieNode->isEnd){
			res_st.insert(word);
		}
		if (trieNode->childrens.empty())
			return ;

		visited[i][j] = 1; 
		// adj in trieNode->childrens
		for (int k =0; k< 4; k++){
			int r = i + x_p[k];
			int c = j + y_p[k];

			if ( 0 <= r && r < board.size() && 0<= c && c <= board[0].size() && !visited[r][c] && trieNode->childrens.find(board[r][c]) != trieNode->childrens.end()){
				char chr = board[r][c];
				dfs(board, r, c, trieNode->childrens[chr], word + chr);
			}
		}

		visited[i][j] = 0;
		
	}
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
    	int x_plus[] = {0, 0, 1, -1};
    	int y_plus[] = {1, -1, 0, 0 };
    	x_p.assign(x_plus, x_plus + 4);
    	y_p.assign(y_plus, y_plus + 4);

    	Trie* head = new Trie;
        for (auto word: words)
        	Insert(head, word);

        visited.assign(board.size(), vector<int>(board[0].size(), 0));

        for(int i=0; i< board.size(); i++){
        	for(int j=0; j< board[0].size(); j++){
        		if (head->childrens.find(board[i][j]) != head->childrens.end()){
        			string str = "";
                    str.push_back(board[i][j]);

        			dfs(board, i, j, head->childrens[board[i][j]], str);
        		}
        	}
        }

        vector <string>res(res_st.begin(), res_st.end());

        return res;
    }
};









