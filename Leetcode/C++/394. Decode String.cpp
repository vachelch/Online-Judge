#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string decodeString(string s) {
    	vector<string> q;
    	int s_size = s.size();

        for(int i=0; i< s_size; i++){
        	char c = s[i];
        	if (c == ']'){
        		string cur = "";
        		while(q.back() != "["){
        			cur = q.back() + cur;
        			q.pop_back();
        		}
        		q.pop_back();

        		int rpt = stoi(q.back());
        		q.pop_back();
        		string tmp = "";
        		while(rpt--)
        			tmp += cur;

        		q.push_back(tmp);
        	}
        	else{
        		if (isdigit(c)){
        			string rpt = "";
        			rpt.push_back(c);
        			while(i+1 <= s_size && isdigit(s[i+1])){
        				rpt.push_back(s[i+1]);
        				i++;
        			}
        			q.push_back(rpt);
        		}
        		else{
        			string cur = "";
	        		cur.push_back(c);
	        		q.push_back(cur);
        		}
        	}
        }

        string res = "";
        for(auto str: q)
        	res += str;

        return res;
    }
};




int main(){
	Solution s;
	string str = "10[leecode]";
	cout << s.decodeString(str) << endl;

	return 0;
}