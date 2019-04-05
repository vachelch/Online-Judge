#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int maximumSwap(int num) {
    	vector<int> n_arr;
    	int n = num;
    	while(n){
    		n_arr.push_back(n % 10);
    		n /= 10;
    	}

    	int l = n_arr.size();
    	vector<int> back(n_arr.begin(), n_arr.end());

    	for(int i=1; i<l; i++)
    		back[i] = max(back[i], back[i-1]);
    		

    	for(int i = l-1; i>=0; i--){
    		if(back[i] == n_arr[i]) continue;
    		for(int j=0; j<l; j++){
    			if(back[i] == n_arr[j]){
    				int tmp = n_arr[j];
    				n_arr[j] = n_arr[i];
    				n_arr[i] = tmp;

    				int sum = 0;
    				// cout<<n_arr[i]<<" "<<n_arr[j]<<endl;
    				for(int k=l-1; k>=0; k--)
    					sum = sum*10 + n_arr[k];

    				return sum;
    			}
    		}
    	}
    	return num;
    }
};


int main(){
	Solution s;
	cout<<s.maximumSwap(9973)<<endl;
	return 0;
}

















