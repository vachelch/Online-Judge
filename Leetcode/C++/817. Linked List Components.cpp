/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
    set<int> dic;
public:
    int numComponents(ListNode* head, vector<int>& G) {
        ListNode *cur = head;
        for(int i=0; i< G.size(); i++)
        dic.insert(G[i]);
        
        int linked = 0, res = 0;
        while(cur){
            if (dic.find(cur->val) != dic.end()){
                if (!linked)
                    res ++;
                linked = 1;
            }
            else{
                linked = 0;
            }
                
            cur = cur->next;
        }
        
        return res;
    }
};