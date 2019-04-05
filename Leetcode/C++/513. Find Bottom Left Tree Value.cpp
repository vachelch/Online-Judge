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
private:
	int leftmost;
	int mx_depth = -1;
public:
	void traverse(TreeNode* root, int depth){
		if (root == NULL) return ;
		traverse(root->left, depth + 1);
		
		if (depth > mx_depth){
			mx_depth = depth;
			leftmost = root->val;
		}

		traverse(root->right, depth + 1);

	}
    int findBottomLeftValue(TreeNode* root) {
        traverse(root, 0);
        return leftmost;
    }
};