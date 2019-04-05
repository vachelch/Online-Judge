#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
#include <math.h>
#include <limits.h>
using namespace std;


bool enough(vector<int>& arr, double mid, int m, int n){
	double cnt = 0;
	for(int i=0; i< arr.size(); i++){
		cnt += floor(arr[i] / mid);
	}

	return cnt >= m;
}
int main(){
	int m, n;
	vector<int> arr(100000);
 	while(cin >> n >> m){	
 		double maxLen = 0;
		for(int i=0; i< n; i++){
			cin >> arr[i];
			maxLen += arr[i];
		}	
		maxLen /= m;
		
		double l=0, r = maxLen;
		while(l <= r){
			double mid = l + (r-l) / 2;
			if (enough(arr, mid, m, n))
				l += 0.001;
			else
				r -= 0.001;
		}

		printf("%.2f\n", l-0.001);
	}
	return 0;
}
