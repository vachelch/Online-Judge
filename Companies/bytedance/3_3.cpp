// WA, 85.00%
// 8 1
// ABABABABABABABABABAB
// ABABABABABABABABABAB
// AAAAAAAAAAAAAAAAAAAA
// AAAAAAAAAAAAAAAAAAAA
// AAAAAAAAAAAAAAAAAAAA
// AAAAAAAAAAAAAAAAAAAA
// AAAAAAAAAAAAAAAAAAAA
// AAAAAAAAAAAAAAAAAAAA

// brute force Full Permutation
#include<iostream>
#include<vector>
#include<string>
using namespace std;

void swap(vector<string>&strs, int a, int b){
	string tmp = strs[a];
	strs[a] = strs[b];
	strs[b] = tmp;
}

void helper(vector<string>& strs, int idx, vector<vector<string> >& res){
	if (idx == strs.size() - 1){
		res.push_back(strs);
		return ;
	}
	for(int i=idx; i< strs.size(); i++){
		swap(strs, i, idx);
		helper(strs, idx+1, res);
		swap(strs, i, idx);
	}
}

vector<vector<string> > get_all_combinations(vector<string> strs){
	vector<vector<string> > res;
	helper(strs, 0, res);

	return res;
}

int check_is_K(vector<string> combinations, int K){
	string cur;
	for(int i=0; i< combinations.size(); i++){
		cur += combinations[i];
	}

	if(cur.size() % K != 0) {
		return 0;
	}

	long long len = cur.size() / K;
	string patt = cur.substr(0, len);
	for(long long i=0; i< cur.size(); i+= len){
		if (cur.substr(i, len) != patt){
			return 0;
		} 
	}

	return 1;
}

int main(){
	int n, K;
	while(cin >> n >> K){
		vector<string> strs;
		string ipt; 
		for(int i=0; i< n; i++){
			cin >> ipt;
			strs.push_back(ipt);
		}
	
	
		vector<vector<string> > all_combinations;
		all_combinations = get_all_combinations(strs);

		long long  res = 0;
		for(int i=0; i< all_combinations.size(); i++){
			res += check_is_K(all_combinations[i], K);
		}

		cout << res << endl;
	}
}