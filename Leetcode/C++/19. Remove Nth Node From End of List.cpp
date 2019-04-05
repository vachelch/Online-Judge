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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == NULL) return NULL;
        
        ListNode* last = head;
        ListNode* cur = head;
        
        while(n--)
            cur = cur->next;
        
        // if delete head, return head->next;
        if (cur == NULL) return head->next;
        
        while(cur->next){
            last = last->next;
            cur = cur->next;
        }
        
        last->next = last->next->next;
        
        return head;
    }
};