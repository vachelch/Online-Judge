/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

TreeNode* Find_Root(vector<int>& nums, int l, int r){
	if (l > r) return NULL;

	int mx = -2000000000, mx_idx;
	for(int i=l; i<= r; i++){
		if (nums[i] > mx){
			mx = nums[i];
			mx_idx = i;
		}
	}

	TreeNode *root = new TreeNode(mx);
	root->left = Find_Root(nums, l, mx_idx - 1);
	root->right = Find_Root(nums, mx_idx + 1, r);

	return root;
}

class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
    	TreeNode* root = Find_Root(nums, 0, nums.size()-1);
    	return root;
    }
};