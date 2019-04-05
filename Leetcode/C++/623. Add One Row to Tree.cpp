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
    void dfs(TreeNode *root, int depth, int d, int v){
        if (root == NULL) return ;
        
        if (depth == d - 1){
            TreeNode *node = new TreeNode(v);
            TreeNode *left = root->left;
            root->left = node;
            node->left = left;
            
            node = new TreeNode(v);
            TreeNode *right = root->right;
            root->right = node;
            node->right = right;
        }
        dfs(root->left, depth + 1, d, v);
        dfs(root->right, depth + 1, d, v);
    }
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if (d == 1){
            TreeNode *node = new TreeNode(v);
            node->left = root;
            return node;
        }
        
        dfs(root, 1, d, v);
        return root;
    }
};