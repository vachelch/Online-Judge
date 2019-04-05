/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/

// insight: distance between meeting point and pHead is multiple loop length (x+a = nQ)
// step1: check loop (fast, slow pointer)
// step2: find entrance. 
// slow: m = x + a + nP
// fast: 2m
// fast - slow = nL = m
// x + a = nQ
class Solution {
public:
    ListNode* loop_ptr(ListNode* pHead){
        ListNode* slow = pHead;
        ListNode* fast = pHead;
        
        if (pHead == NULL) return NULL;
        while(slow->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
            
            if (slow == fast) return slow;
        }
        
        return NULL;
    }
    ListNode* EntryNodeOfLoop(ListNode* pHead)
    {
        ListNode* meet = loop_ptr(pHead);
        if (meet == NULL) return NULL;
        
        ListNode * head = pHead;
        while(meet != head){
            meet = meet->next;
            head = head->next;
        }
        
        return meet;
    }
};