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
    int last;
    int minest;
    bool inorder(TreeNode* root){
        if (root == NULL) return true;
        
        bool left = inorder(root->left);
        
        if (root->val == last && last == INT_MIN && minest)
            minest = 0;
        else{
            if (root->val <= last)
                return false;
            else
                last = root->val;   
        }
        bool right = inorder(root->right);
        return left && right;
    }
    bool isValidBST(TreeNode* root) {
        minest = 1;
        last = INT_MIN;
        return inorder(root);
    }
};


