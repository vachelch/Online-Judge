/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// heap
class Solution {
public:
    struct cmp{
        bool operator() (pair<int, int>& a, pair<int, int>& b){
            return a.second >= b.second;
        }
    };
    
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> heap;
        ListNode* head = new ListNode(0);
        ListNode* cur = head;
            
        for(int i=0; i< lists.size(); i++){
            if (lists[i]){
                heap.push(make_pair(i, lists[i]->val));
                lists[i] = lists[i]->next;    
            }
        }
        
        pair<int, int> tmp;
        while(!heap.empty()){
            tmp = heap.top();    
            heap.pop();
            cur->next = new ListNode(tmp.second);
            cur = cur->next;
            
            if(lists[tmp.first]){
                heap.push(make_pair(tmp.first, lists[tmp.first]->val));
                lists[tmp.first] = lists[tmp.first]->next;
            }
        }
        
        return head->next;
    }
};


// merge two list, 
// We can merge first two lists. Keep doing this until there is only one list left
ListNode *mergeKLists(vector<ListNode *> &lists) {
    if(lists.empty()){
        return nullptr;
    }
    while(lists.size() > 1){
        lists.push_back(mergeTwoLists(lists[0], lists[1]));
        lists.erase(lists.begin());
        lists.erase(lists.begin());
    }
    return lists.front();
}
ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
    if(l1 == nullptr){
        return l2;
    }
    if(l2 == nullptr){
        return l1;
    }
    if(l1->val <= l2->val){
        l1->next = mergeTwoLists(l1->next, l2);
        return l1;
    }
    else{
        l2->next = mergeTwoLists(l1, l2->next);
        return l2;
    }
}








