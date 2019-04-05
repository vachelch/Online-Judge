/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/

// inorder
class Solution {
public:
    vector<TreeNode*> nodes;
    void inorder(TreeNode* pRootOfTree){
        if (pRootOfTree){
            inorder(pRootOfTree->left);
            nodes.push_back(pRootOfTree);
            inorder(pRootOfTree->right);
        }
    }
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        if (pRootOfTree == NULL) return NULL;
        inorder(pRootOfTree);
        TreeNode* last = nodes[0];
        for(int i=1; i< nodes.size(); i++){
            nodes[i]->left = last;
            last->right = nodes[i];
            last = nodes[i];
        }
        last->right = NULL;
        
        return nodes[0];
    }
};

// inorder2
// maintain a last node during inorder
class Solution {
public:
    TreeNode* last = NULL;
    TreeNode* head = NULL;
    
    void inorder(TreeNode* pRootOfTree){
        if (pRootOfTree == NULL){
            return ;
        }
        
        inorder(pRootOfTree->left);
        if (head == NULL) {
            head = pRootOfTree;
        }
        else{
            last->right = pRootOfTree;
            pRootOfTree->left = last;
        }
        
        last = pRootOfTree;
        
        inorder(pRootOfTree->right);
    }
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        inorder(pRootOfTree);
        return head;
    }
};













