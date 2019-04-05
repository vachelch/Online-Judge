#include <iostream>
#include <map>
#include <vector>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
    	int l = nums.size();
        vector<int> back(l);

        int sm = 0;
        for(int i=0; i<l; i++){
        	sm += nums[i];
        	back[i] = sm;
        }


        map<int, int> idict;
        idict[0] = 1;
        int count = 0;

        for(int i=0; i<l; i++){
        	int num = back[i];
        	if(idict.find(num - k) != idict.end()){
        		count += idict[num-k];
        	}
        	if (idict.find(num) != idict.end()){
        		idict[num] += 1;
        	}
        	else{
        		idict[num] = 1;
        	}
        }

        return count;

    }
};

int main(){
	Solution s;
	int n_arr[] = {1,1,1};
	vector<int> nums(n_arr, n_arr+3);
	int k = 2;

	cout<<s.subarraySum(nums, 2)<<endl;
	return 0;
}
























