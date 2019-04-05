/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int idxInVin(vector<int>& vin, int l, int r, int val){
        for(int i=l; i<= r; i++){
            if (vin[i] == val) return i;
        }
        return r;
    }
    TreeNode* reConstruct(vector<int>& pre, vector<int>& vin, int l_pre, int r_pre, int l_vin, int r_vin){
        if (l_pre > r_pre) return NULL;
        
        int val = pre[l_pre];
        TreeNode* node = new TreeNode(val);
        int idx = idxInVin(vin, l_vin, r_vin, val);
        int l_diff = idx - l_vin;
        int r_diff = r_vin - idx;
        
        node->left = reConstruct(pre, vin, l_pre+1, l_pre+l_diff, l_vin, idx-1);
        node->right = reConstruct(pre, vin, l_pre+l_diff+1, r_pre, idx+1, r_vin);
        
        return node;
    }
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        return reConstruct(pre, vin, 0, pre.size()-1, 0, pre.size()-1);
    }
};