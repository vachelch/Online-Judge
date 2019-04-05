/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/

// two stack
class Solution {
public:
    vector<vector<int> > Print(TreeNode* pRoot) {
        vector<vector<int> > res;
        if (pRoot == NULL) return res;
        
        stack<TreeNode*> stk_lr;
        stack<TreeNode*> stk_rl;
        int depth = 0;
        stk_lr.push(pRoot);
        
        while(!stk_lr.empty() || !stk_rl.empty()){
            vector<int> row;
            if (depth % 2 == 0){
                while(!stk_lr.empty()){
                    TreeNode* cur = stk_lr.top();
                    stk_lr.pop();
                    
                    row.push_back(cur->val);
                    if (cur->left) stk_rl.push(cur->left);
                    if (cur->right) stk_rl.push(cur->right);
                }
            }
            else{
                while(!stk_rl.empty()){
                    TreeNode* cur = stk_rl.top();
                    stk_rl.pop();
                    
                    row.push_back(cur->val);
                    if (cur->right) stk_lr.push(cur->right);
                    if (cur->left) stk_lr.push(cur->left);
                }
            }
            
            depth ++;
            res.push_back(row);
        }
        
        return res;
    }
    
};