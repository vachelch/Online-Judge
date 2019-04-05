#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
  		int sum = 0;
  		for(auto n: nums)
  			sum += n;

  		if (sum % 2 != 0) return false;
  		sum /= 2;

  		int dp[nums.size()+1][sum+1];
  		dp[0][0] = 1;
  		for(int i=1; i<= nums.size(); i++)
  			dp[i][0] = 1;
  		for(int j=1; j<= sum; j++)
  			dp[0][j] = 0;

  		for(int i=1; i<= nums.size(); i++){
  			for(int j=1; j <= sum; j++){
  				if (j - nums[i-1] < 0)
  					dp[i][j] = dp[i-1][j];
  				else
  					dp[i][j] = dp[i-1][j] || dp[i-1][j - nums[i-1]];
  			}
  		}
  		
  		return dp[nums.size()][sum];
    }
};


int main(){
	int num[] = {1, 5, 11, 5};
	Solution s;
	vector<int> nums(num, num + 4);

	cout << s.canPartition(nums) << endl;

	return 0;
}