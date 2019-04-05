#include <iostream>
#include <vector>
using namespace std;

// space complexity, O(m*n)
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int hit = 0;
        for(int i=0; i< nums.size(); i++)
            hit += nums[i];
        
        if (hit % 2 != 0) return false;
        
        hit /= 2;
        vector<vector<int> >dp(nums.size()+1, vector<int>(hit+1, 0));
        for(int i=0; i<= nums.size(); i++) dp[i][0] = 1;
        
        // dp[i][j] = dp[k][j - nums[i]] + nums[i] || dp[k][j];
        for(int i=0; i< nums.size(); i++){
            for(int j=1; j<= hit; j++){
            	if (dp[i][j])
            		dp[i+1][j] = dp[i][j];

                else if (j - nums[i] >= 0)
                    dp[i+1][j] = dp[i][j - nums[i]] || dp[i][j];
                    
            }
        }

        return dp[nums.size()][hit];
    }
};

// space complexity, O(n)
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int hit = 0;
        for(int i=0; i< nums.size(); i++) hit += nums[i];
        
        if (hit % 2 != 0) return false;
        
        hit /= 2;
        int dp[hit+1];
        memset(dp, 0, (hit+1)* sizeof(int));
        dp[0] = 1;
        
        for(int i=1; i<= nums.size(); i++){
            for(int j=hit; j>= nums[i-1]; j--){
                dp[j] = dp[j] || dp[j-nums[i-1]];
            }
        }
        

        return dp[hit];
    }
};

int main(){
	int num[] = {1,2,5};
	vector<int> nums(num, num+3);
	Solution s;
	cout << s.canPartition(nums) << endl;



	return 0;
}




















