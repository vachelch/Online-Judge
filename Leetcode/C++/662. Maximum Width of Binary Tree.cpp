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
	vector<int> mn;
	vector<int> mx;
	int res;

	void dfs(TreeNode* root, int depth, int pos){
		if (!root) return ;

		if (depth == mn.size())
			mn.push_back(pos);
		else{
			mn[depth] = min(pos, mn[depth]);
		}

		if (depth == mx.size())
			mx.push_back(pos);
		else{
			mx[depth] = max(pos, mx[depth]);
		}

		dfs(root->left, depth+1, 2*pos);
		dfs(root->right, depth+1, 2*pos + 1);
	}
    int widthOfBinaryTree(TreeNode* root) {
    	int res = 0;
    	dfs(root, 0, 1);

    	int size = min(mn.size(), mx.size());
    	for(int i=0; i< size; i++){
    		res = max(res, mx[i] - mn[i] + 1);
    	}
    	return res;
    }
};



















