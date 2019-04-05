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
    TreeNode* res = NULL;
    bool counting = false;
    int cnt;
    
    void inorder(TreeNode* pRoot){
        // begin to count
        if (pRoot == NULL){
            counting = true;
            return ;
        }
        // found
        if(res != NULL) return ;
        
        inorder(pRoot->left);
        if (counting){
            cnt --;
            if(cnt == 0){
                 res = pRoot;
                return;
            }
        }
        inorder(pRoot->right);
    }
    TreeNode* KthNode(TreeNode* pRoot, int k)
    {
        cnt = k;
        inorder(pRoot);
        return res;
        
    }

    
};