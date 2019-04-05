class Solution {
private:
    vector <string> res;
public:
    void dfs(int n, string s, vector<char> & queue){
        if (n == 0) {
            for(int i=0; i< queue.size(); i++)
                s += ')';
            res.push_back(s);
        }
        if (n > 0){
            // branch1, add '('
            vector<char> queue2 = queue;
            queue.push_back('(');
            dfs(n-1, s + '(', queue);
            
            // branch2, add ')'
            if (queue2.size() != 0){
                queue2.pop_back();
                dfs(n, s + ')', queue2);
            }
                
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<char> queue;
        string s = "";
        dfs(n, s, queue);
        return res;
    }
};