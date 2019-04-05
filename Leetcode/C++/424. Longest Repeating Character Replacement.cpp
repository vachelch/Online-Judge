#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        int s_size = s.size();
        int  max_count = 0, stop = 1, start = 0;
        map<char, int> dict;

        for(int end = 0; end < s_size; end++){
        	dict[s[end]] ++;
        	max_count = max(max_count, dict[s[end]]);
        	if (end - start + 1 - max_count > k){
        		dict[s[start]] --;
        		start ++;
        	}
        }	

        return ((max_count + k) < s_size) ? (max_count + k) : s_size;
    }
};


int main(){
	string str = "";
	int k=0;

	Solution s;

	cout<< s.characterReplacement(str, k) << endl;

	return 0;
}
