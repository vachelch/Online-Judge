#include <iostream>
#include <vector>
#include <map>
using namespace std;

class ListNode{
public: 
    int key;
    int val;
    ListNode *last;
    ListNode *next;
    ListNode(int k, int v){
        key = k;
        val = v;
    }
};

class LRUCache {
public:
    map<int, ListNode*> key2node;
    ListNode* head;
    ListNode* tail;
    int cap;
    
    LRUCache(int capacity) {
        cap = capacity;
        head = new ListNode(1, 1);
        tail = head;
    }
    
    int get(int key) {
        if(key2node.find(key) == key2node.end()) return -1;
        
        ListNode * node = key2node[key];
        if (node == tail) return node->val;
        
        // Increase order
        ListNode * front = node->last;
        ListNode * behind = node->next;
        
        front->next = behind;
        behind->last = front;
        
        node->last = tail;
        node->next = NULL;
        tail->next = node;
        tail = node;
        
        return node->val;
    }
    
    void put(int key, int value) {
        if (cap == 0) return ;
        if (key2node.find(key) != key2node.end()){
            get(key);
            ListNode* node = key2node[key];
            node->val = value;
        }
        
        else if(key2node.size() == cap){
            ListNode *rm_node = head->next;
            
            ListNode *newNode = new ListNode(key, value);
            key2node[key] = newNode;
            
            // removre least recent
            key2node.erase(rm_node->key);    
            if (rm_node == tail){
                head->next = newNode;
                newNode->last = head;
                tail = newNode;
            }
            else{
                head->next = rm_node->next;
                rm_node->next->last = head;
                
                tail->next = newNode;
                newNode->last = tail;
                tail = newNode;
            }
            
            free(rm_node);
        }
        else{
            ListNode* node = new ListNode(key, value);
            node->last = tail;
            tail->next = node;
            tail = node;
            key2node[key] = node;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */

int main(){
    LRUCache cache = LRUCache( 2 /* capacity */ );

    cache.put(1, 1);
    cache.put(2, 2);
    cout << cache.get(1) << endl;    // returns 1
    cache.put(3, 3);    // evicts key 2
    cout << cache.get(2) << endl;    // returns -1 (not found)
    cache.put(4, 4);    // evicts key 1
    cout << cache.get(1) << endl;    // returns -1 (not found)
    cout << cache.get(3) << endl;    // returns 3
    cout << cache.get(4) << endl;    // returns 4

    return 0;
}






















