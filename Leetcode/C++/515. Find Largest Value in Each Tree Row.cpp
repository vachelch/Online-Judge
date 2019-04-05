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
	vector<int> res;
public:
	void dfs(TreeNode* root, int depth){
		if (root == NULL) return;

		if (depth+1 > res.size())
			res.push_back(root->val);
		else{
			res[depth] = max(res[depth], root->val);
		}
		dfs(root->left, depth + 1);
		dfs(root->right, depth + 1);
	}

    vector<int> largestValues(TreeNode* root) {
        dfs(root, 0);
        return res;
    }
};