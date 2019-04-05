class TrieNode{
public:
    map<char, TrieNode*> children;
    int end;
    TrieNode() {end = 0;}
};

class Trie {
public:
    /** Initialize your data structure here. */
    TrieNode* root;

    Trie() {
        root = new TrieNode;
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* cur = root;

        for(auto c: word){
            if (cur->children.find(c) == cur->children.end())
                cur->children[c] = new TrieNode;
                
            cur = cur->children[c];
        }
        cur->end = 1;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* cur = root;
        for(auto c: word){
            if (cur->children.find(c) != cur->children.end())
                cur = cur->children[c];
            else
                return false;
        }

        if (cur->end == 1) return true;
        else return false;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* cur = root;
        for(auto c: prefix){
            if (cur->children.find(c) != cur->children.end())
                cur = cur->children[c];
            else
                return false;
        }

        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */