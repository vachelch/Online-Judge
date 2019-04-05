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
    ListNode* merge(ListNode* head1, ListNode* head2){
        ListNode * head;
        ListNode * last;
        ListNode * cur;
        
        bool start = true;
        while(head1 && head2){
            if (head1->val < head2->val){
                    cur = head1;
                    head1 = head1->next;
                }
                else{
                    cur = head2;
                    head2 = head2->next;
                }
            
            if (start){
                head = cur;
                start = false;
            }   
            else{
                last->next = cur;   
            }
            last = cur;
        }
        
        if (head1)
            last->next = head1;
        if (head2)
            last->next = head2;
        
        return head;
    }
    ListNode* sortList(ListNode* head) {
        // size = 0, 1
        if (head == NULL || head->next == NULL)
            return head;
        // size = 2
        if (head->next && head->next->next == NULL){
            if (head->val > head->next->val){
                ListNode* tmp = head->next;
                tmp->next = head;
                head->next = NULL;
                
                return tmp;
            }
            return head;
        }
        
        ListNode* slow = head; 
        ListNode* fast = head;
        // find mid of list
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
            
        ListNode* head2 = slow->next;
        slow->next = NULL;
        
        head = sortList(head);
        head2 = sortList(head2);
        
        return merge(head, head2);
    }
};