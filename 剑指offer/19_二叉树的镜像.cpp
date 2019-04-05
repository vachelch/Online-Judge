/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    TreeNode *get_mirror(TreeNode *pRoot){
        if (pRoot == NULL) return NULL;
        TreeNode * tmp = pRoot->right;
        pRoot->right = get_mirror(pRoot->left);
        pRoot->left = get_mirror(tmp);
        
        return pRoot;
    }
    void Mirror(TreeNode *pRoot) {
        pRoot = get_mirror(pRoot);
    }
};