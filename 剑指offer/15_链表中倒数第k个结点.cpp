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
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        ListNode *front = pListHead, *back = pListHead;
        while(back && k){
            back = back->next;
            -- k;
        }
        
        if (back == NULL && k > 0) return NULL;
        while(back){
            back = back->next;
            front = front->next;
        }
        
        return front;
    }
};


// recursion
class Solution {
public:
    int n;
    ListNode* res = NULL;
    void findK(ListNode* pListHead){
        if(pListHead == NULL) return ;
        findK(pListHead->next);
        n --;
        
        if (n == 0){
            res = pListHead;
            return ;
        }
    }
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        n = k;
        findK(pListHead);
        
        return res;
    }
};