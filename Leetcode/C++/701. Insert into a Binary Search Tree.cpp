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
    void Insert(TreeNode* cur , int val){
        if (val < cur->val){
            if (cur->left)
                Insert(cur->left, val);
            else
                cur->left = new TreeNode(val);
        }
        else{
            if (cur->right)
                Insert(cur->right, val);
            else
                cur->right = new TreeNode(val);
        }
        
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        Insert(root, val);
        return root;
    }
};