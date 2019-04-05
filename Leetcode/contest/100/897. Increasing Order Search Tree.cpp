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
	vector<int> vec;
	void inorder(TreeNode* root){
		if (root->left)
			inorder(root->left);

		vec.push_back(root->val);

		if (root->right)
		inorder(root->right);
	}
    TreeNode* increasingBST(TreeNode* root) {
    	if (!root)
    		return NULL;

        inorder(root);
        TreeNode * last = new TreeNode(vec[0]);
        TreeNode * head = last;
        for(int i=1; i< vec.size(); i++){
        	TreeNode * cur = new TreeNode(vec[i]);
        	last->right = cur;

        	last = cur;
        }

        return head;
    }
};