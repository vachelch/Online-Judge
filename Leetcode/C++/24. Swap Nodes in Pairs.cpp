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
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL || head->next == NULL)
        	return head;

        // swap first and second
        ListNode* before = head;
        ListNode* behind = head->next;
        ListNode* last;

        ListNode* tmp = behind->next;
    	behind->next = before;
    	before->next = tmp;
    	
    	ListNode* res = behind;

    	last = before;
        before = tmp;
        if (tmp)
        	behind = tmp->next;

        while(before && behind ){
        	ListNode* tmp = behind->next;
        	last->next = behind;
        	behind->next = before;
        	before->next = tmp;

        	last = before;
        	before = tmp;
        	if (tmp)
        		behind = tmp->next;
        }

        return res;
    }
};
















