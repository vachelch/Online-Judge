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
    vector<vector<string>> res;
    int m = 0;
public:
    void depth(TreeNode* root, int d){
        if (root != NULL){
            m = max(d, m);
            depth(root->left, d + 1);
            depth(root->right, d + 1);
        }  
    }
    void fill(TreeNode* root, int left, int right, int depth){
        if (root != NULL){
            int middle = (left + right)/2;
            res[depth][middle] = to_string(root->val);
            
            fill(root->left, left, middle-1, depth + 1);
            fill(root->right, middle+1, right, depth + 1);   
        }   
    }
    vector<vector<string>> printTree(TreeNode* root) {
        depth(root, 0);

        int n = 1;
        for (int i=0; i< m; i++)
            n = 2 * n + 1;
        
        for(int i=0; i< m+1; i ++){
            vector<string> tmp(n, "");
            res.push_back(tmp);
        }
        
        fill(root, 0, n-1, 0);
        
        return res;
    }
};