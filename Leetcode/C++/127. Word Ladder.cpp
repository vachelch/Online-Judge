class Solution {
public:
    bool Is_adjcent(string a, string b){
        int cnt = 0;
        for(int i=0; i< a.size(); i++)
            if (a[i] != b[i]){
                cnt ++;
                if (cnt > 1) return false;
            }
        
        return (cnt == 1)? true: false;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        wordList.push_back(beginWord);
        vector<vector<int> > adj_list(wordList.size(), vector<int>());
        vector<int> visited(wordList.size(), 0);
        vector<int> depth(wordList.size());
         
        // adj_list
        for(int i=0; i< wordList.size(); i++){
            for(int j=i+1; j< wordList.size(); j++){
                if (Is_adjcent(wordList[i], wordList[j])){
                    adj_list[i].push_back(j);
                    adj_list[j].push_back(i);
                }
            }
        }
        
        // bfs
        deque<int> q;
        visited.back() = 1;
        depth.back() = 1;
        
        q.push_back(visited.size()-1);
        
        while(!q.empty()){
            int cur = q[0];
            q.pop_front();
            
            for(auto adj: adj_list[cur]){
                if (!visited[adj]){
                    visited[adj] = 1;
                    depth[adj] = depth[cur] + 1;
                    
                    if (wordList[adj] == endWord) return depth[adj];
                    
                    q.push_back(adj);
                }
            }
        }
        
        return 0;
    }
};