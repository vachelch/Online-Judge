class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.empty()) return 0;
        
        vector<int> dp(nums.size());
        
        dp[0] = nums[0];
        int mx = nums[0];
        
        for(int i=1; i< nums.size(); i++){
            dp[i] = max(dp[i-1], 0) + nums[i];
            mx = max(dp[i], mx);
        }
        
        return mx;
    }
};