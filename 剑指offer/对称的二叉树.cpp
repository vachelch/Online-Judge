/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
public:
    bool isEqual(TreeNode* left, TreeNode* right){
        if (left == NULL && right == NULL) return true;
        else if (left == NULL || right == NULL) return false;
        else if (left->val != right->val) return false;
        else return isEqual(left->left, right->right) && isEqual(left->right, right->left);
    }
    bool isSymmetrical(TreeNode* pRoot)
    {
        if (pRoot == NULL) return true;
        return isEqual(pRoot->left, pRoot->right);
    }
};