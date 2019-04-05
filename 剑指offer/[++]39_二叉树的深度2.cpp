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
	bool res;
	int depth(TreeNode* root){
		if (root == NULL) return 0;

		int left, right;
		if (res)
			left = depth(root->left);	
		if (res)
			right = depth(root->right);

		if (res){
			res = ( -1 <= left - right && left - right <= 1)? true: false;
		}

		return max(left, right) + 1;
	}
    bool isBalanced(TreeNode* root) {
    	res = true;
        depth(root);

        return res;
    }
};