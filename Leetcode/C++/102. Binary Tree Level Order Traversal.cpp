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
	deque<pair<TreeNode *, int>> q;
	vector<vector<int>>res;

	void bfs(TreeNode * node, int d){
		if (node){
			if (res.size() > d)
				res[d].push_back(node->val);
			else{
				vector<int> v(1, node->val);
				res.push_back(v);
			}

			q.push_back(make_pair(node->left, d+1));
			q.push_back(make_pair(node->right, d+1));
		}
	}
    vector<vector<int>> levelOrder(TreeNode* root) {
    	q.push_back(make_pair(root, 0));

    	while(!q.empty()){
    		pair<TreeNode *, int>cur = q.front();
    		q.pop_front();
    		bfs(cur.first, cur.second);
    	}

    	return res;
        
    }
};