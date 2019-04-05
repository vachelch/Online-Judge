// AC
// multiset, insert, erase, find maximum
#include <iostream>
#include <set>
using namespace std;

void check(multiset<int, greater<int> > mset, int sum){
	if (mset.size() <3){
		cout << "No" << endl;
		return ;
	}

	multiset<int>::iterator itr = mset.begin();
	int mx = *itr;
	if (2*mx >= sum) 
		cout << "No" << endl;
	else
		cout << "Yes" << endl;
}

int main(){
	int N, opt, num;
	while(cin >> N){
		int sum = 0;
		multiset<int, greater<int> > mset;
		for(int i=0; i< N; i++){
			cin >> opt >> num;
			if (opt == 1){
				mset.insert(num);
				sum += num;

				check(mset, sum);
			}

			else{
				multiset<int>::iterator itr = mset.find(num);
				if (itr != mset.end()) {
					mset.erase(itr);
					sum -= num;
				}

				check(mset, sum);
			}
		}
	}

	return 0;
}

























