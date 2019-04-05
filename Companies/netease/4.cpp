# include <iostream>
# include <deque>
using namespace std;

int main(){
	int N;
	while(cin >> N){
		deque<int> nums;
		int cur;

		for(int i=0; i< N; i++){
			cin >> cur;
			if (i % 2 == 0){
				nums.push_front(cur);	
			}
			else{
				nums.push_back(cur);	
			}
		}

		if ((N-1) % 2 == 0){
			for(int i=0; i< N-1; i++)
				cout << nums[i] << " ";
			cout << nums[N-1] << endl;
		}
		else{
			for(int i=N-1; i> 0; i--)
				cout << nums[i] << " ";
			cout << nums[0] << endl;
		}
		
	}
	

	return 0;
}