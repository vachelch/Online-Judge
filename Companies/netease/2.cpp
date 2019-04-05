#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// set
int main(){
	int N;
	vector<int> arr(50);
	while(cin >> N){
		for(int i=0; i< N; i++)
			cin >> arr[i];

		sort(arr.begin(), arr.begin() + N);

		int last = arr[1] - arr[0];
		bool res = true;
		for(int i=2; i< N; i++){
			if (arr[i] - arr[i-1] != last){
				res = false;
				break;
			}

		}

		if (res)
			cout << "Possible" << endl;
		else
			cout << "Impossible" << endl;
	}

	return 0;
}