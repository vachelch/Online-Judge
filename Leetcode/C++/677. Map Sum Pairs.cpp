#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

class TrieNode{
public:
    map<char, TrieNode*> children;
    int score;
};

class MapSum {
private:
    TrieNode *root = new TrieNode;
    map<string, int> dic;
public:
    /** Initialize your data structure here. */
    MapSum() {
    }
    
    void insert(string key, int val) {
    	int delta = val;
    	if (dic.find(key) != dic.end()) {
    		delta = val - dic[key];
    	}
    	dic[key] = val;

    	TrieNode *cur = root;
        for(int i=0; i< key.size(); i++){
        	if (cur->children.find(key[i]) == cur->children.end()){
        		TrieNode * node = new TrieNode;
        		node->score = delta;

        		cur->children[key[i]] = node;
        	}
        	else{
        		cur->children[key[i]]->score += delta;
        	}
        	cur = cur->children[key[i]];
        }
    }
    
    int sum(string prefix) {
        TrieNode *cur = root;
        for(int i=0; i< prefix.size(); i++){
        	if (cur->children.find(prefix[i]) == cur->children.end()){
        		return 0;
        	}
        	cur = cur->children[prefix[i]];
        }
        return cur->score;
    }
};

int main(){
	MapSum m;
	string keys[] = {"apple", "app"};
	string prefixs[] = {"ap", "ap"};
	m.insert(keys[0], 3);
	cout << m.sum(prefixs[0]) << endl;;
	m.insert(keys[1], 2);
	cout << m.sum(prefixs[1]) << endl;

	return 0;
}

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum obj = new MapSum();
 * obj.insert(key,val);
 * int param_2 = obj.sum(prefix);
 */