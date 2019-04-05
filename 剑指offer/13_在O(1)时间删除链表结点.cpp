/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* pHead, ListNode* node) {
    	if (pHead == NULL || node == NULL) return ;

        if (node && node->next){
            node->val = node->next->val;
            node->next = node->next->next;
            return ;
        }

        // node is tail or node is head and tail
        if (node == pHead && pHead->next == NULL){
        	pHead = NULL;
        	return ;
        }

        ListNode* last = pHead;
        ListNode* cur = pHead->next;
        if (cur != node){
        	last = cur;
        	cur = cur->next;
        }
        last->next = NULL;
    }
};