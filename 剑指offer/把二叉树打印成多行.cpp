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
class Solution {
public:
        vector<vector<int> > Print(TreeNode* pRoot) {
            vector<vector<int> > res;
            if (pRoot == NULL) return res;
            
            queue<TreeNode*> queue;
            queue.push(pRoot);
            
            while(!queue.empty()){
                int size = queue.size();
                vector<int> row;
                for(int i=0; i< size; i++){
                    TreeNode* cur = queue.front();
                    queue.pop();
                    
                    row.push_back(cur->val);
                    if (cur->left) queue.push(cur->left);
                    if (cur->right) queue.push(cur->right);
                }
                
                res.push_back(row);
            }
            
            return res;
        }
    
};