#include <iostream>
#include <vector>
#include <deque>
#include <stdlib.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        deque<int> arr1;
        deque<int> arr2;
        
        ListNode *cur = l1;
        while(cur){
            arr1.push_back(cur->val);
            cur = cur->next;
        }
        cur = l2;
        while(cur){
            arr2.push_back(cur->val);
            cur = cur->next;
        }
        
        int l1_size = arr1.size();
        int l2_size = arr2.size();

        int len = max(l1_size, l2_size);
        for(int i =0; i< len - l1_size; i++)
            arr1.push_front(0);
        for(int i =0; i< len - l2_size; i++)
            arr2.push_front(0);

        int mod = 0;
        int div = 0;
        for(int i=len-1; i>= 0; i--){
            arr1[i] += arr2[i] + div;
            div = arr1[i] / 10;
            mod = arr1[i] % 10;
            arr1[i] = mod;
        }
        
        if(div > 0)
            arr1.push_front(div);
        
        ListNode *head = (ListNode *)malloc(sizeof(struct ListNode));
        head->val = arr1[0];
        cur = head;
        
        for(int i=1; i< arr1.size(); i++){
            ListNode * node = (ListNode *)malloc(sizeof(struct ListNode));
            node->val = arr1[i];
            
            cur->next = node;
            cur = node;
        }
        cur->next = NULL;
        
        return head; 
    }
};

int main(){
    int arr1[] = {0};
    int arr2[] = {2, 7, 8};

    ListNode * l1 = (ListNode *)malloc(sizeof(struct ListNode));
    l1->val = 0;
    l1->next = NULL;

    ListNode * l2 = (ListNode *)malloc(sizeof(struct ListNode));
    l2->val = 2;
    ListNode *cur = l2;
    for(int i=1; i< 3; i++){
        ListNode * node = (ListNode *)malloc(sizeof(struct ListNode));
        node->val = arr2[i];
        cur->next = node;
        cur = node;
    }
    cur->next = NULL;

    Solution s;
    cur = s.addTwoNumbers(l1, l2);

    while(cur){
        cout << cur->val << endl;
        cur = cur->next;
    }

    return 0;
}






























