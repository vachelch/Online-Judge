#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits.h>
using namespace std;

int main(){
	int N;
	while(cin >> N){
		int capacity = 1024 - N;
		int res = 0;
		int tmp;

		while(capacity >= 64){
			tmp = capacity % 64;
			res += capacity /64;
			capacity = tmp;
		}
		while(capacity >= 16){
			tmp = capacity % 16;
			res += capacity /16;	
			capacity = tmp;
		}
		while(capacity >= 4){
			tmp = capacity % 4;
			res += capacity /4;	
			capacity = tmp;
		}

		cout << res + capacity << endl;
		
	}
	return 0;
}