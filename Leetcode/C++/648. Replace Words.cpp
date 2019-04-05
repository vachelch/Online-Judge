#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;


class TrieNode {
public:
	map<char, TrieNode *> children;
	int end;
	string str;

	TrieNode(){
		end = 0;
	}
};

class Solution {
public:
	void insert(TrieNode * root, string predecessor){
		TrieNode *cur = root;
		for (int i=0; i< predecessor.size(); i++){
			if (cur->children.find(predecessor[i]) == cur->children.end()){
				TrieNode * node = new TrieNode;
				cur->children[predecessor[i]] = node;
			}	

			cur = cur->children[predecessor[i]];
		}
		cur->str = predecessor;
		cur->end = 1;
	}


	void split(const string& src, const string& delim, vector<string>& dest)  
	{  
	    string str = src;  
	    string::size_type start, index;  
	    string substr;  
	  	
	  	start = str.find_first_not_of(delim, 0);
	    index = str.find_first_of(delim, start);    //在str中查找(起始：start) delim的任意字符的第一次出现的位置  
	    while(index != string::npos)  
	    {  
	        substr = str.substr(start, index-start);  
	        dest.push_back(substr);  
	        start = str.find_first_not_of(delim, index);    //在str中查找(起始：index) 第一个不属于delim的字符出现的位置  
	        if(start == string::npos) return;  
	  
	        index = str.find_first_of(delim, start);  
	    }  
	} 

	bool find_successor(TrieNode *root, string word, string *successor){
		TrieNode *cur = root;

		for(int i=0; i< word.size(); i++){
			if (cur->children.find(word[i]) == cur->children.end()){
				if (cur->end){
					(*successor) = cur->str.c_str();
					return true;
				}
				else
					return false;
			}
			else{
				if (cur->children[word[i]]->end){
					(*successor) = cur->children[word[i]]->str.c_str();
					return true;
				}
				else
					cur = cur->children[word[i]];
			}
		}

		return false;
	}
    string replaceWords(vector<string>& dict, string sentence) {
    	TrieNode *root = new TrieNode;
        for(const auto it: dict){
        	insert(root, it);
        }

        vector<string> words;
        split(sentence + " ", " ", words);

        string res = "";
        for(int i=0; i< words.size(); i++){
        	string successor;
        	if (find_successor(root, words[i], &successor)){
        		res += successor + " ";
        	}
        	else
        		res += words[i] + " ";
        }

        res.pop_back();
        return res;
    }
};

int main(){
	string sentence = "a aa a aaaa aaa aaa aaa aaaaaa bbb baba ababa";
	string dict_arr[] = {"a", "aa", "aaa", "aaaa"};
	vector<string> dict(dict_arr, dict_arr + 4);

	Solution s;
	cout << s.replaceWords(dict, sentence) << endl;
}









