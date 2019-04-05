/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> res;
    set<int>st;
    void dfs(TreeNode *root, int d){
        if(root){
            if(st.find(d) == st.end()){
                st.insert(d);
                res.push_back(root->val);
            }
            dfs(root->right, d+1);
            dfs(root->left, d+1);
        }
    }
    vector<int> rightSideView(TreeNode* root) {
        dfs(root, 0);
        
        return res;
    }
};