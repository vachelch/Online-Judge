#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
    	string mose[] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
    	map<string, int> dict;

		for(int i=0; i< words.size(); i++){
			string word = words[i];
			string cur = "";
			for(int j=0; j < word.size(); j++){
				cur += mose[word[j] - 'a'];
			}

			if (dict.find(cur) == dict.end())
				dict[cur] ++;
			else
				dict[cur] = 1;
		}

		return dict.size();
    }
};

int main(){
	string ipt[] = {"gin", "zen", "gig", "msg"};
	vector<string> words;
	words.assign(ipt, ipt+4);

	Solution s;
	cout << s.uniqueMorseRepresentations(words) << endl;
	return 0;
}













