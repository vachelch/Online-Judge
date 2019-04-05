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
	map<int, int> inorder_idx;
	TreeNode* recursive(vector<int>& preorder, int pre_l, int pre_r, vector<int>& inorder, int in_l, int in_r){
		if (pre_r < pre_l)
			return NULL;
		
		if (pre_r == pre_l){
			TreeNode * node = new TreeNode(preorder[pre_l]);
			return node;
		}

		TreeNode * root = new TreeNode(preorder[pre_l]);
		int in_root_idx = inorder_idx[preorder[pre_l]]; // 1

		int in_subtree_l1 = in_l; // 0
		int in_subtree_r1 = in_root_idx - 1; // 0
		int in_subtree_l2 = in_root_idx + 1; // 2
		int in_subtree_r2 = in_r; // 1

		int pre_subtree_l1 = pre_l+1; // 1
		int pre_subtree_r1 = pre_l + (in_root_idx - in_l); // 1
		int pre_subtree_l2 = pre_r - (in_r - in_root_idx) + 1; // 2
		int pre_subtree_r2 = pre_r; // 4

		root->left = recursive(preorder, pre_subtree_l1, pre_subtree_r1, inorder, in_subtree_l1, in_subtree_r1);
		root->right = recursive(preorder, pre_subtree_l2, pre_subtree_r2, inorder, in_subtree_l2, in_subtree_r2);;

		return root;
	}
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    	if (inorder.empty()) return  NULL;

    	for(int i=0; i< inorder.size(); i++)
    		inorder_idx[inorder[i]] = i;

        return recursive(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);
    }
};