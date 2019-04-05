/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// recursion, beat 17.66%
class Solution {
public:
	vector<string> subtree_vec(TreeNode *root){
		vector<string> v;
		if (!root) return v;

		vector<string> left = subtree_vec(root->left);
		vector<string> right = subtree_vec(root->right);

		for(auto l :left)
        	v.push_back(to_string(root->val) + l);

	    for(auto l :right)
	    	v.push_back(to_string(root->val) + l);

        if (v.empty())
        	v.push_back(to_string(root->val));

        return v;
	}
    int sumNumbers(TreeNode* root) {
        vector<string> nums = subtree_vec(root);

        int res = 0;
        for(auto n: nums)
        	res += stoi(n);

        return res;
    }
};

// dfs, beat 100%
