// a + 2b, 2a + b, 2*mx- mn, a + b
#include <iostream>
#include <vector>
using namespace std;

int  main(){
	long long  t;
	long long  n, k, d1, d2;
	while(cin >> t){
		while(t--){
			cin >> n >> k >> d1 >> d2;

			bool poss = false;
			long long  mx = max(d1, d2);
			long long  mn = min(d1, d2);
			if ((k - (2*d1 + d2)) % 3 == 0 && (n-k-(d1 + 2*d2)) % 3 == 0 && k >= 2*d1 + d2 && n-k >= d1 + 2*d2){
				poss = true;
			}
			if ((k - (2*d2 + d1)) % 3 == 0 && (n - k-(2*d1 + d2)) %3 == 0 && k >= (2*d2 + d1) && n-k >= (2*d1 + d2)){
				poss = true;
			}
			if ((k - (mx + mn)) % 3 == 0 && (n-k - (2*mx - mn)) % 3 == 0 && k >= (mx + mn) && n-k >= (2*mx - mn)){
				poss = true;
			}
			if ((k - (2*mx - mn)) % 3 == 0 && (n-k - (mx + mn))% 3 == 0 && k >= (2*mx - mn) && n-k >= (mx + mn)){
				poss = true;
			}

			if(poss) cout << "yes" << endl;
			else cout << "no" << endl;
		}
	}
}