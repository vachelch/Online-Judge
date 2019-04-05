// AC
// binary to int, brainstorm
#include<iostream>
#include<vector>
#include<string>
#include<math.h>
using namespace std;

vector<int> int2bin(int num){
	vector<int> bin;
	while(num){
		bin.push_back(num%2);
		num /= 2;
	}

	vector<int> res;
	for(int i=bin.size()- 1; i>=0; i--)
		res.push_back(bin[i]);

	return res;
}


string str_add(string a, string b){
	string res;

	string tmp;
	int diff = b.size() - a.size();
	for(int i=0; i< abs(diff); i++){
		tmp +="0";
	}
	if (a.size() > b.size()) b = tmp + b;
	else a = tmp + a;

	int add = 0;
	for(int i=a.size()-1; i>=0; i--){
		int a_int = a[i] - '0';
		int b_int = b[i] - '0';
		char cur = (a_int + b_int + add) % 10 + '0';
		add = (a_int + b_int + add) / 10;

		res.push_back(cur);
	}

	if (add > 0)
		res.push_back(add + '0');

	while(!res.empty() && res.back() == '0')
		res.pop_back();

	string res_;
	for (int i=res.size()-1; i>=0; i--)
		res_.push_back(res[i]);
	
	return res_;
}

int main(){
	int x, k;
	while(cin >> x >> k){
		vector<int> x_bin;
		vector<int> k_bin;
		x_bin = int2bin(x);
		k_bin = int2bin(k);

		vector<int> res_vec;
		int i= x_bin.size()-1;
		int j= k_bin.size()-1;

		while(i>=0 && j>= 0){
			if(x_bin[i--] == 1){
				res_vec.push_back(0);
			}
			else
				res_vec.push_back(k_bin[j--]);
		}
		while(j>=0){
			res_vec.push_back(k_bin[j--]);
		}

		long long res = 0;
		for(int i=res_vec.size()- 1; i>=0; i--){
			// string tmp = str_add(res, res);
			// res = str_add(tmp, to_string(res_vec[i]));
			res = res*2 + res_vec[i];
		}

		cout << res << endl;
	}
}