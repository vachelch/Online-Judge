# include <iostream>
using namespace std;

int main(){
	string s;
	while(cin >> s){
		int res = 1;
		int cnt = 1;
		for(int i=1; i< s.size(); i++){
			if (s[i] + s[i-1] == '0' + '1'){
				cnt += 1;
				res = max(cnt, res);
			}
			else{
				cnt = 1;
			}
		}

		cout << res << endl;
	}

	return 0;
}