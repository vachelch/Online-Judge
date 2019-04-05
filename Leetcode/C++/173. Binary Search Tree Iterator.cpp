/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    int idx;
    int length;
    vector<int>inorder;
    
    void traverse(TreeNode *root){
    	if (root){
    		traverse(root->left);
        	
        	inorder.push_back(root->val);
        	length++;
        	
        	traverse(root->right);
    	}
    }

    BSTIterator(TreeNode *root) {
    	idx = -1;
    	length = 0;
    	traverse(root);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return (idx != length-1);
    }

    /** @return the next smallest number */
    int next() {
        ++idx ;
        return inorder[idx];
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */