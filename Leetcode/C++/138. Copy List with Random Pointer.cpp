/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (head == NULL) return NULL;
        map<RandomListNode *, RandomListNode *> ini2copy;
        
        // cur node     
        RandomListNode* copy_head = new RandomListNode(head->label);
        ini2copy[head] = copy_head;

        // random node
        RandomListNode* copy_rand;
        if (head->random){
            copy_rand = new RandomListNode(head->random->label);
            ini2copy[head->random] = copy_rand;
        }
        else
            copy_rand = NULL;
        
        // pointers
        copy_head->random = copy_rand;
        RandomListNode* last = copy_head;

        RandomListNode* cur = head->next;
        while(cur){
            // cur node
            RandomListNode * copy_cur;
            if (ini2copy.find(cur) == ini2copy.end()){
                copy_cur = new RandomListNode(cur->label);
                ini2copy[cur] = copy_cur;
            }
            else
                copy_cur = ini2copy[cur];

            // random node
            if (cur->random){
                if (ini2copy.find(cur->random) != ini2copy.end())
                    copy_rand = ini2copy[cur->random];
                else{
                    copy_rand = new RandomListNode(cur->random->label);
                    ini2copy[cur->random] = copy_rand;
                }
            }
            else
                copy_rand = NULL;

            // pointer
            copy_cur->random = copy_rand;
            last->next = copy_cur;
            last = copy_cur;

            cur = cur->next;
        }

        return copy_head;
    }
};























