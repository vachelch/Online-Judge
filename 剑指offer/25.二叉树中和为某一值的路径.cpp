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
    vector<vector<int> > res;
    void printPath(TreeNode* root, int number, vector<int>& path){
        if (!root->left && !root->right && number == root->val){
            path.push_back(number);
            res.push_back(path);
            path.pop_back();
        }
        else{
            if (root->left){
                path.push_back(root->val);
                printPath(root->left, number - root->val, path);
                path.pop_back();
            }
            if (root->right){
                path.push_back(root->val);
                printPath(root->right, number - root->val, path);
                path.pop_back();
            }
        }
    }
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        if (root == NULL) return res;
        
        vector<int> path;
        printPath(root, expectNumber, path);
        
        return res;
    }
};