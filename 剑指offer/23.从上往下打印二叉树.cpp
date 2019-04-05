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
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        vector<int> res;
        if (!root) return res;
        
        deque<TreeNode*> queue;
        queue.push_back(root);
        
        while(!queue.empty()){
            TreeNode* cur = queue.front();
            res.push_back(cur->val);
            queue.pop_front();
            
            if(cur->left) queue.push_back(cur->left);
            if(cur->right) queue.push_back(cur->right);
        }
        
        return res;
    }
};