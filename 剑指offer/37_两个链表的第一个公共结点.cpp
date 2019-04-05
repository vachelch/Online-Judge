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
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        vector<ListNode*> stack1;
        vector<ListNode*> stack2;
        
        ListNode* cur = pHead1;
        while(cur){
            stack1.push_back(cur);
            cur = cur->next;
        }
        
        cur = pHead2;
        while(cur){
            stack2.push_back(cur);
            cur = cur->next;
        }
        
        ListNode* res = NULL;
        while(!stack1.empty() && !stack2.empty()  && stack1.back() == stack2.back()){
            res = stack1.back();
            stack1.pop_back();
            stack2.pop_back();
        }
        
        return res;
    }
};