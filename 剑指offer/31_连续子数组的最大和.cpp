class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        int mx = INT_MIN;
        vector<int> dp(array.size());
        if (array.empty()) return 0;
            
        dp[0] = array[0];
        for(int i=1; i<array.size(); i++){
            dp[i] = max(0, dp[i-1]) + array[i];
            mx = max(dp[i], mx);
        }
        
        return mx;
    }
};