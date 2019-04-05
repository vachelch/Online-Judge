// WA, 85%
// array
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;

int main(){
	int n;
	string cur;
	while(cin >> n){
		vector<long long> chrs(10, 0);
		for(int i=0; i< n; i++){
			cin >> cur;

			int size = cur.size();
			for(int i=0; i< size; i++){
				chrs[cur[i]- 'A'] += pow(10, size - i -1);
			}
		}

		sort(chrs.begin(), chrs.end(), greater<long long>());

		long long res = 0;
		for(int i=0; i< chrs.size(); i++){
			res += chrs[i] * (9 - i);
		}

		cout << res << endl;
	}

	return 0;
}