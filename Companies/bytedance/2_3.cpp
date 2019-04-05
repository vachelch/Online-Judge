#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
#include <limits.h>
using namespace std;

int main(){
	int N, n;
	vector<int> a(1000000);

 	while(cin >> N){
 		for(int k=0; k< N; k++){
 			cin >> n;
			for(int i=0; i< n; i++){
				cin >> a[i];
			}

			int i=0;
			int res = 0;
			while(i < n-1){
				int start = i;
				if ( a[i+1] > a[i] ){
					while(i+1 < n && a[i+1] > a[i]){
						i++;
					}
					res += (1 + i)*(i-start + 1)/2;
					i++;
				}
				else if (a[i+1] < a[i]){
					while(i+1 < n && a[i+1] < a[i]){
						i++;
					}
					res += (1 + i)*(i-start + 1)/2;
					i++;
				}
				else{
					while(i+1 < n && a[i+1] == a[i]){
						i++;
					}
					res += (i-start);
				}
			}

			cout << res << endl;
 		}	
	}
	return 0;
}



// 2
// 2
// 1 2
// 4
// 1 2 3 3












