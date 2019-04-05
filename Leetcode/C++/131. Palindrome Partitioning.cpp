#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	vector<vector<string> > res;

	void backtrace(string s, vector<string>& v, int idx){
		if (idx == s.size()){
			res.push_back(v);
			return ;
		}

		string str_chr(1, s[idx]);
		// case 1
		v.push_back(str_chr);
		backtrace(s, v, idx+1);
		v.pop_back();

		// case 2
		if (!v.empty() && str_chr == v.back()){
			v.back() += str_chr;
			backtrace(s, v, idx+1);
			v.back() = v.back()[0];
		}

		// case 3
		if (v.size() >= 2 && str_chr == v[v.size()-2]){
			string back = v.back();
			string back2 = v[v.size()-2];

			string str = "";
			str += back2;
			str += back;
			str += s[idx];

			v.pop_back();
			v.pop_back();

			v.push_back(str);
			backtrace(s, v, idx+1);
			v.pop_back();
			v.push_back(back2);
			v.push_back(back);
		}
	}
    vector<vector<string> > partition(string s) {
    	if (s.empty()) return res;

    	vector<string> v;
    	backtrace(s, v, 0);

    	return res;
    }
};


int main(){
	Solution s;
	cout << s.partition("ccaacabacb")[0][0] << endl;

	return 0;
}