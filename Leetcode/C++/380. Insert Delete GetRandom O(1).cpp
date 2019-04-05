#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class RandomizedSet {
public:
    /** Initialize your data structure here. */
    unordered_map<int, int> val_idx;
    vector<int> rand_set;
    
    RandomizedSet() {
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (val_idx.find(val) != val_idx.end()){
            return false;
        }
        else{
            val_idx[val] = rand_set.size();
            rand_set.push_back(val);
            return true;
        }
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (val_idx.find(val) != val_idx.end()){

            int idx = val_idx[val];
            val_idx[rand_set.back()] = idx;
            rand_set[idx] = rand_set.back();

            // erase action should be placed after copying idx to map
            // otherwise, WA will happen when removed val is just the last val in rand_set (the val wouldn't be removed successfully).
            val_idx.erase(val);
            rand_set.pop_back();

            return true;
        }
        else{
            return false;
        }
        
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        int idx = rand() % rand_set.size();
        return rand_set[idx];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */

// void Print(vector<int>& vec){
//     for(auto it: vec)
//         cout << it << " ";
//     cout << endl;
// }
void Print(unordered_map<int, int>& dict){
    for(auto it: dict)
        cout << it.first << ": " << it.second << ";  " ;
    cout << endl;
}        


int main(){
    RandomizedSet *obj = new RandomizedSet();
    bool param_1 = obj->insert(0);
    Print(obj->val_idx);

    bool param_2 = obj->remove(0);
    Print(obj->val_idx);

    param_1 = obj->insert(-1);
    Print(obj->val_idx);

    param_2 = obj->remove(0);
    Print(obj->val_idx);

    int param_3 = obj->getRandom();
    Print(obj->val_idx);

    int param_4 = obj->getRandom();
    int param_5 = obj->getRandom();

    return 0;
}






















