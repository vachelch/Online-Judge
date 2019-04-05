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
    int res, n;
    
    void inorder(TreeNode* root){
        if (root == NULL || n < 0) return ;
        inorder(root->left);
        n--;
        if (n == 0){
            res = root->val;
            return ;
        }
        inorder(root->right);
    }
    int kthSmallest(TreeNode* root, int k) {
        n = k;
        inorder(root);
        return res;
    }
};