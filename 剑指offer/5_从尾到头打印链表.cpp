/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
class Solution {
public:
    vector<int> res;
    void printList(ListNode* head){
        if(head){
            printList(head->next);
            res.push_back(head->val);
        }
    }
    vector<int> printListFromTailToHead(ListNode* head) {
        printList(head);
        return res;
    }
};