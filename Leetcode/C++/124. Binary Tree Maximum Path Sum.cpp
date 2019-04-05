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
    map<TreeNode*, pair<int, int>>node2lens;
    
    int dfs(TreeNode* root){
        if (root == NULL) return 0;
        
        int l = dfs(root->left);
        int r = dfs(root->right);
        
        node2lens[root] = make_pair(l, r);
        int cur = max(l, r);
        
        return max(cur+root->val, 0);
    }
    int maxPathSum(TreeNode* root) {
        dfs(root);
        
        int res = INT_MIN;
        for(auto ptr: node2lens){
            TreeNode * node = ptr.first;
            pair <int, int> pr = ptr.second;
            
            int candidates[] = {node->val, node->val + pr.first, node->val + pr.second, node->val + pr.first + pr.second};
            
            for(int i=0; i< 4; i++)
                res = max(res, candidates[i]);
                        
        }
        
        return res;
    }
};