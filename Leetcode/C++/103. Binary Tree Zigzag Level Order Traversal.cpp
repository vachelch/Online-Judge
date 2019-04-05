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
	vector<vector<int>> levels;
	void dfs(TreeNode *root, int depth){
		if (root == NULL) return ;

		if (levels.size() == depth){
			vector<int> v(1, root->val);
			levels.push_back(v);
		}
		else{
			levels[depth].push_back(root->val);
		}
		dfs(root->left, depth + 1);
		dfs(root->right, depth + 1);
	}
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        dfs(root, 0);

		for(int i=0; i< levels.size(); i++){
			if (i % 2 != 0){
				int l = 0, r = levels[i].size()-1;

				while(l < r){
					int tmp = levels[i][l];
					levels[i][l] = levels[i][r];
					levels[i][r] = tmp;

					l++;
					r--;
				}
			}
		}        

        return levels;
    }
};