#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

bool compare(string a, string b){
	if (a.size() > b.size() || (a.size() == b.size() && a[0] < b[0]))
		return true;
	else
		return false;
}

class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        sort(d.begin(), d.end(), compare);
        int i,j;
        int s_size = s.size();

        for(auto word: d){
        	i = j = 0;
        	while(i < s_size && j< word.size()){
        		if (s[i] == word[j]){
        			i++;
        			j++;
        			if (j == word.size())
        				return word;
        		}
        		else
        			i++;
        	}

        }

        return "";
    }
};


int main(){
	string s = "aewfafwafjlwajflwajflwafj";
	string d_[] = {"apple","ewaf","awefawfwaf","awef","awefe","ewafeffewafewf"};
	vector<string> d(d_, d_ + 6);

	Solution slt;
	cout << slt.findLongestWord(s, d) << endl;

	return 0;
}















