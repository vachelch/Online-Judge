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
    ListNode* oddEvenList(ListNode* head) {
        if (head == NULL || head->next == NULL || head->next->next == NULL) return head;
        ListNode *odd_head = head;
        ListNode *even_head = head->next;
        ListNode *odd = head;
        ListNode *even = even_head;
            
        while(odd->next && odd->next->next){
            odd->next = odd->next->next;
            odd = odd->next;
            
            even->next = odd->next;
            even = even->next;
        }
        
        odd->next = even_head;
        
        return odd_head;
    }
};