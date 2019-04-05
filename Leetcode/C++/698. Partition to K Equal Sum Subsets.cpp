#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<int> visited;
	bool dfs(vector<int>& nums, int idx, int sum, int k, int target){
		if (k == 1) return true;

		if (sum == target){
			return  dfs(nums, 0, 0, k-1, target);
		}

		for(int i= idx+1; i< nums.size(); i++){
			if (!visited[i]){
				visited[i] = 1;
				if (dfs(nums, i, sum + nums[i], k, target)){
					return true;
				}
				visited[i] = 0;
			}
		}

		return false;
	}
    bool canPartitionKSubsets(vector<int>& nums, int k) {
    	int sum = 0;
    	for(auto n: nums)
    		sum += n;

    	if (sum % k != 0) return false;
    	sum /= k;

    	visited.assign(nums.size(), 0);

    	visited[0] = 1;

    	return dfs(nums, 0, nums[0], k, sum);
    }
};





int main(){
	int nums_[] = {2,2,10,5,2,7,2,2,13};
	vector<int> nums(nums_, nums_ + 9);
	Solution s;
	int k = 3;
	cout <<s.canPartitionKSubsets(nums, k) << endl;

	return 0;
}