#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
using namespace std;

// bool compare(string a, string b){
//     return (a.size() <= b.size()) ? true: false;
// }
// class Solution {
// public:
//     bool match(string a, string b){
//         int len_a = a.size();
//         int len_b = b.size();
//         for(int i=0; i< len_b; i++){
//             if (a[len_a-len_b+i] != b[i])
//                 return false;
//         }
        
//         return true;
//     }
//     int minimumLengthEncoding(vector<string>& words) {
//         if(words.size() == 0) return 0;
//         sort(words.begin(), words.end(), compare);

//         int res = 0;
//         for(int i=0; i< words.size(); i++){
//             int mtc = 0;
//             for(int j=i+1; j< words.size(); j++){
//                 if (match(words[j], words[i])){
//                     mtc = 1;
//                     break;
//                 }
//             }

//             if (!mtc)
//                 res += words[i].size() + 1;
//         }
        
//         return res;
//     }
// };

class trieNode {
public:
    map<char, trieNode*> childrens;
};


class Solution {
public:
	void Insert(trieNode *root, string word){
		trieNode* cur = root;
		for(int i=word.size()-1; i>=0; i--){
			if (cur->childrens.find(word[i]) != cur->childrens.end())
				cur = cur->childrens[word[i]];
			else{
				cur->childrens[word[i]] = new trieNode;
				cur = cur->childrens[word[i]];
			}
		}
	}
	bool match(trieNode *root, string word){
		trieNode *cur = root;
		for(int i=word.size()-1; i>=0; i--){
			if (cur->childrens.find(word[i]) != cur->childrens.end())
				cur = cur->childrens[word[i]];
		}

		if (cur->childrens.size() == 0)
			return false;
		return true;
	}
    int minimumLengthEncoding(vector<string>& words) {
    	trieNode *root = new trieNode;

    	set<string> words_set;
    	for(auto word: words)
    		words_set.insert(word);

        for (auto word: words_set)
        	Insert(root, word);

        int res = 0;
        for(auto word: words_set){
        	if (!match(root, word))
        		res += word.size() + 1;
        }

        return res;
    }
};

int main(){
	Solution s;
	string word[] = {"time", "me", "bell"};
	vector<string> words(word, word + 3);
	cout << s.minimumLengthEncoding(words) << endl;

	return 0;
}

















