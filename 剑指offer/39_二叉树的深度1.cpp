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
    int res;
    void dfs(TreeNode* root, int depth){
        if (root){
            res = max(depth, res);
            dfs(root->left, depth + 1);
            dfs(root->right, depth + 1);
        }
        return ;
    }
    int maxDepth(TreeNode* root) {
        res = 0;
        
        dfs(root, 1);
        return res;
    }
};