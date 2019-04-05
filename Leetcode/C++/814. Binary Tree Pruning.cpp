/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

int NotRomove(TreeNode* root){
	if (root == NULL) return 0;

	int left = NotRomove(root->left);
	int right = NotRomove(root->right);

	if (left == 0)
		root->left = NULL;
	if (right == 0)
		root->right = NULL;

	if (root->val + left + right)
		return 1;
	else
		return 0;
}

class Solution {
public:
    TreeNode* pruneTree(TreeNode* root) {
    	if (NotRomove(root))
        	return root;
        else
        	return NULL;
    }
};