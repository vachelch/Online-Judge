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
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    ListNode* this_head;
    
    Solution(ListNode* head) {
        this_head = head;
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        int step = rand();
        int len = 0;
        ListNode *cur = this_head;
        
        while(step > 0){
            cur = cur->next;
            step--;
            len ++;
            
            if(cur == NULL)
                break;
        }
        if (step == 0 && cur == NULL){
            return this_head->val;
        }
        else if(step){
            step %= len;
            cur = this_head;
            while(step){
                cur = cur->next;
                step--;
            }
            return cur->val;
        }
        else{
            return cur->val;
        }
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.getRandom();
 */