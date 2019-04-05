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
	vector<int> leaf;
public:
	void traverse(TreeNode * root){
		if (root->left == NULL && root->right == NULL) leaf.push_back(root->val);
		if (root->left) traverse(root->left);
		if (root->right) traverse(root->right);
	}
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        traverse(root1);
        traverse(root2);

        if (leaf.size() % 2 != 0) return false;
        int start1 = 0;
        int start2 = leaf.size()/2;

        while(start2 < leaf.size()){
        	if(leaf[start1] != leaf[start2]) return false;
        	start1 ++;
        	start2 ++;
        }

        return true;
    }
};