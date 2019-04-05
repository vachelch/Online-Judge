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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *cur;
        ListNode *last = l1;
        ListNode *head = l1;

        int sum = l1->val + l2->val;
        int val = sum % 10;
        int addone = sum / 10;
        l1->val = val;

        l1 = l1->next;
        l2 = l2->next;

        while(l1 || l2){
            if (l1)
                cur = l1;
            else
                cur = l2;
            last->next = cur;

            sum = addone;
            if (l1)
                sum += l1->val;

            if (l2)
                sum += l2->val;

            val = sum % 10;
            addone = sum / 10;

            cur->val = val;
            last = cur;

            if (l1)
                l1 = l1->next;
            if (l2)
                l2 = l2->next;
        }
        
        if (addone){
            cur = new ListNode(1);
            last->next = cur;
        }
        return head;
    }
};