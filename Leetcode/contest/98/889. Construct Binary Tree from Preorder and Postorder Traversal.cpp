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
    map<int, int> pre_map;

    TreeNode* dfs(vector<int> &pre, vector<int> &post, int left, int right){
        if (left > right) return NULL;
        if (left == right) {
            TreeNode* root = new TreeNode(pre[left]);
            return root;
        }

        TreeNode * root = new TreeNode(pre[left]);

        int idx = pre_map[post[right-1]];
        root->left = dfs(pre, post, left+1, idx - 1);
        root->right = dfs(pre, post, idx, right);

        cout << pre[left] << endl;
        return root;
    }
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        int left = 0;
        int right = pre.size()-1;
        
        for(int i=0; i< pre.size(); i++)
            pre_map[pre[i]] = i;

        return dfs(pre, post, left, right);
    }
};