#include <iostream>
#include <string>
#include <vector>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x){
        val = x;
        left = NULL;
        right = NULL;
    } 
};
 
class Solution {
public:
    bool dfs(TreeNode* root, TreeNode* node, vector<TreeNode*>& vec){
        if (root == NULL) return false;
        if (root == node){
            vec.push_back(root);
            return true;
        }

        if (dfs(root->left, node, vec)){
            vec.push_back(root);
            return true;
        }
        if (dfs(root->right, node, vec)){
            vec.push_back(root);
            return true;
        }

        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> p_vec;
        vector<TreeNode*> q_vec;

        dfs(root, p, p_vec);
        dfs(root, q, q_vec);

        int p_size = p_vec.size();
        int q_size = q_vec.size();

        int size = min(p_size, q_size);
        TreeNode* res;

        for(int i=1; i<= size; i++){
            if (p_vec[p_size - i] == q_vec[q_size - i])
                res = p_vec[p_size - i];
        }
        
        return res;
    }
};


int main(){
    TreeNode* l0 = new TreeNode(3);
    TreeNode* l11 = new TreeNode(5);
    TreeNode* l12 = new TreeNode(1);
    
    TreeNode* l21 = new TreeNode(6);
    TreeNode* l22 = new TreeNode(2);
    TreeNode* l23 = new TreeNode(0);
    TreeNode* l24 = new TreeNode(8);

    TreeNode* l31 = new TreeNode(7);
    TreeNode* l32 = new TreeNode(4);

    l0->left = l11;
    l0->right = l12;

    l11->left = l21;
    l11->right = l22;
    l12->left = l23;
    l12->right = l24;

    l22->left = l31;
    l22->right = l32;

    Solution s;
    cout << s.lowestCommonAncestor(l0, l11, l32)->val << endl;

    return 0;
}






























