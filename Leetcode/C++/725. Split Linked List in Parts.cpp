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
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        ListNode *cur = root;
        int len = 0;
        
        while(cur){
            len ++;
            cur = cur->next;
        }
        
        int divi = len / k;
        int mod = len % k;
        
        vector<ListNode*> res;
        ListNode * start;
        ListNode *last;
        
        cur = root;
        for(int i=0; i< k; i++){
            start = cur;
            for(int j=0; j< divi; j++){
                last = cur;
                cur = cur->next;
            }
            if(mod-- > 0){
                last = cur;
                cur = cur->next;   
            }
            if (start != cur){
                last->next = NULL;
                res.push_back(start);
            }
            else
                res.push_back(NULL);
        }
        
        return res;
    }
};