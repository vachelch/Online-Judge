/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
        if (!pHead) return pHead;
        
        ListNode* cur = pHead;
        ListNode* next = pHead->next;
        cur->next = NULL;
        
        while(next){
            ListNode* tmp = next->next;
            next->next = cur;
            
            cur = next;
            next = tmp;
        }
        
        return cur;
    }
};