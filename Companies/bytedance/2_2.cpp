#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits.h>
using namespace std;

int main(){
	int N;
	while(cin >> N){
		string s;
		for(int k=0; k< N; k++){
			cin  >> s;
			if (s.size() == 0){
				cout << s << endl;
				continue;
			}

			// rule 1
			int cnt = 1;
			char last = s[0];
			string res_tmp;
			for(int i=1; i< s.size(); i++){
				while(s[i] == last){
					i++;
					cnt ++;
				}
				string tmp(1, last);
				if (cnt >= 2) {
					tmp += last;
				}
				
				res_tmp += tmp;
				cnt = 1;
				last = s[i];
			}

			string tmp(1, last);
			if (cnt >= 2) {
				tmp += last;
			}
			res_tmp += tmp;

			// cout << res_tmp << endl;

			// rule 2
			bool pair = false;
			string res;
			bool last_is_pair = false;
			for(int i=0; i< res_tmp.size()-1; i++){
				if (res_tmp[i] == res_tmp[i+1]){
					if (pair){
						res.push_back(res_tmp[i]);
						pair = false;
					}
					else{
						res.push_back(res_tmp[i]);
						res.push_back(res_tmp[i]);
						pair = true;
					}
					i += 1;

					if (res_tmp.size()-1 == i) last_is_pair = true;
				}
				else{
					res += res_tmp[i];
					pair = false;
				}
			}

			if (!last_is_pair) res += res_tmp.back();

			cout << res << endl;
		}
	}
	return 0;
}









3
helloo
woooooooow
aaddaaccbba





















