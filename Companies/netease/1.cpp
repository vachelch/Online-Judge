#include <iostream>
#include <string>
#include <set>
using namespace std;

// set
int main(){
	string s;
	while(cin >> s){
		set<char> colors;
		for(int i=0; i< s.size(); i++){
			colors.insert(s[i]);
			if (colors.size() == 3)
				break;
			else
				colors.insert(s[i]);
		}

		if(colors.size() > 2)
			cout << 0 << endl;
		else if (colors.size() == 2)
			cout << 2 << endl;
		else
			cout << 1 << endl;
	}

	return 0;
}

// only record 2 color
int main(){
	string s;
	while(cin >> s){
		int col_a = -1, col_b = -1;
		int res = 2;
		for(int i=0; i< s.size(); i++){
			if (s[i] == col_a || s[i] == col_b){
				continue;
			}
			else if (col_a == -1 || col_b == -1){
				if (col_a == -1)
					col_a = s[i];
				else
					col_b = s[i];
			}
			else{
				res = 0;
				break;
			}
		}
		if (col_a == -1 || col_b == -1)
			cout << 1 << endl;
		else 
			cout << res << endl;
	}

	return 0;
}












