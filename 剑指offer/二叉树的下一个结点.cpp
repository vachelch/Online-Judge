/*
struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {
        
    }
};
*/
class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode)
    {
        if (pNode == NULL) return NULL;
        
        if (pNode->right){
            TreeLinkNode* cur = pNode->right;
            while(cur->left)
                cur = cur->left;
            return cur;
        }
        else{
            TreeLinkNode* cur = pNode->next;
            while(cur && cur->val < pNode->val)
                cur = cur->next;
            return cur;
        }
    }
};