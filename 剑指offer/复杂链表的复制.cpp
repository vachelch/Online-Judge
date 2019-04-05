/*
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
*/
class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        if (pHead == NULL) return NULL;

        map <RandomListNode*, RandomListNode*> old2new;
        RandomListNode * last = new RandomListNode(pHead->label);
        RandomListNode * cur = pHead;
        RandomListNode * head = last;
        
        old2new[pHead] = head;
        cur = cur->next;
        while(cur){
            RandomListNode * node = new RandomListNode(cur->label);
            last->next = node;
            
            last = node;
            old2new[cur] = node;
            cur = cur->next;
        }
        cur = pHead;
        RandomListNode *newcur = head;
        while (cur){
            newcur->random = old2new[cur->random];
            
            cur = cur->next;
            newcur = newcur->next;
        }
        
        return head;
    }
};