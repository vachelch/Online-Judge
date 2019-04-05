/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/

// stupid method
class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead)
    {
        if (pHead == NULL) return NULL;
        
        ListNode* head = pHead;
        ListNode* cur = pHead;
        set<int> values;
        set<int> repeat;
        
        while(cur){
            if (values.find(cur->val) != values.end())
                repeat.insert(cur->val);
            else
                values.insert(cur->val);
            
            cur = cur->next;
        }
        
        cur = head;
        while(cur && repeat.find(cur->val) != repeat.end())
            cur = cur->next;
        head = cur;
        if (head == NULL) return NULL;
            
        while(cur->next){
            if (repeat.find(cur->next->val) != repeat.end())
                cur->next = cur->next->next;
            else cur = cur->next;
        }
        
        return head;
    }
};


// recursion, mine
class Solution {
public:
    int repeated;

    ListNode* noDuplicate(ListNode* pHead)
    {
        if (pHead == NULL) return NULL;
        
        ListNode* list = noDuplicate(pHead->next);
        if (list == NULL) {
            if (pHead->val == repeated) return NULL;
            
            pHead->next = NULL;
            return pHead;
        }

        if(pHead->val == list->val){
            repeated = pHead->val;
            list = list->next;
            return list;
        }
        else if (pHead->val == repeated){
            return list;
        }
        
        else{
            pHead->next = list;
            return pHead;
        }
    }

    ListNode* deleteDuplication(ListNode* pHead){
        if (pHead == NULL) return NULL;

        repeated = pHead->val - 1;
        return noDuplicate(pHead);
    }
};


// three pointer; 
class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead)
    {
        if (pHead == NULL) return NULL;
        
        ListNode* head = new ListNode(0);
        head->next = pHead;
        pHead = pHead->next;
        ListNode* pre = head;
        ListNode* tail = head->next;
        ListNode* last = head->next;
        
        while(pHead){
            if(pHead->val == last->val){
                if(tail->val == pHead->val){
                    tail = pre;
                }
            }
            else{
                tail->next = pHead;
                pre = tail;
                tail = pHead;
            }
            last = pHead;
            pHead = pHead->next;
        }
        tail->next = NULL;
        
        return head->next;
    }
};

// recursion, provided by discussion board
public class Solution {
    public ListNode deleteDuplication(ListNode pHead) {
        if (pHead == null || pHead.next == null) { // 只有0个或1个结点，则返回
            return pHead;
        }
        if (pHead.val == pHead.next.val) { // 当前结点是重复结点
            ListNode pNode = pHead.next;
            while (pNode != null && pNode.val == pHead.val) {
                // 跳过值与当前结点相同的全部结点,找到第一个与当前结点不同的结点
                pNode = pNode.next;
            }
            return deleteDuplication(pNode); // 从第一个与当前结点不同的结点开始递归
        } else { // 当前结点不是重复结点
            pHead.next = deleteDuplication(pHead.next); // 保留当前结点，从下一个结点开始递归
            return pHead;
        }
    }
}