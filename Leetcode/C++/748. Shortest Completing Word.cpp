#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctype.h>
using namespace std;

class Solution {
public:
	bool iscomplete(string word, map<char, int>& dic){
		map<char, int> cur;
		for(int i=0; i< word.size(); i++){
			if (cur.find(word[i]) == cur.end())
				cur[word[i]] = 1;
			else
				cur[word[i]] += 1;
		}

		for (map<char, int>::iterator it = dic.begin(); it != dic.end(); it++){
			if (cur.find(it->first) == cur.end() || cur[it->first] < it->second)
				return false;
		}

		return true;
	}
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
    	map<char, int> dic;
        for(int i=0; i< licensePlate.size(); i++){
        	if(isalpha(licensePlate[i])){
        		char tmp = tolower(licensePlate[i]);
        		if (dic.find(tmp) == dic.end())
        			dic[tmp] = 1;
        		else
        			dic[tmp] += 1;
        	}
        }

        // for (map<char, int>::iterator it = dic.begin(); it != dic.end(); it++){
        // 	cout << it->first << " " << it->second << endl;
        // }

        string res;
        int min_len = 1001;
        for(int i=0; i< words.size(); i++){
        	if (iscomplete(words[i], dic)){
        		if (words[i].size() < min_len){
                    res = words[i];
                    min_len = words[i].size();
                }		
        	}
        }

        return res;
    }
};

int main(){
	Solution s;
	string licensePlate = "TE73696";
	string word_arr[] = {"ten","two","better","talk","suddenly","stand","protect","collection","about","southern"};

	vector<string> words(word_arr, word_arr + 10);

	string res = s.shortestCompletingWord(licensePlate, words);

	cout << res << endl;
	
	return 0;

}