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
    vector<int> dfs(TreeNode* root){
        if (root == NULL) return vector<int>(2, 0);

        vector<int>res1;
        vector<int>res2;
        vector<int>res;
        res1 = dfs(root->left);
        res2 = dfs(root->right);

        int mx = 0;
        for(int i=0; i< 2;i++)
          for(int j=0; j< 2; j++)
            mx = max(res1[i] + res2[j], mx);

        res.push_back(mx);
        res.push_back(res1[0] + res2[0] + root->val);

        return res;
        
    }
    int rob(TreeNode* root) {
        vector<int>res;
        res = dfs(root);
        return max(res[0], res[1]);
    }
};