// (TLE)
class Solution {
public:
	int res;
	void dfs(vector<int>& nums, int sum, int target){
		if (sum == target){
			res ++;
			return ;
		}
		else if(sum > target)
			return ;

		for(int i=0; i< nums.size(); i++){
			dfs(nums, sum + nums[i], target);
		}
	}
    int combinationSum4(vector<int>& nums, int target) {
    	res = 0;
        dfs(nums, 0, target);

        return res;
    }
};






// DP(AC)
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
    	vector<int> dp(target+1, 0);
    	dp[0] = 1;

    	for(int i=1; i<= target; i++){
    		for(auto n: nums){
    			if (i >= n)
    				dp[i] += dp[i-n];
    		}
    	}
        
        return dp[target];
    }
};



































