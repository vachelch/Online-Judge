// recursion
class Solution {
public: 
    int helper(vector<int>& nums, int l, int r){
        if (r == l) return nums[r];
        return max(nums[r] - helper(nums, l, r-1), nums[l] - helper(nums, l+1, r));
    }
    bool PredictTheWinner(vector<int>& nums) {
       return helper(nums, 0, nums.size()-1) >= 0;      
    }
};


// dp
class Solution {
public: 
    bool PredictTheWinner(vector<int>& nums) {
    	int size = nums.size();

     	int dp[size][size] = {0};
     	for(int i=0; i< size; i++)
     		dp[i][i] = nums[i];

     	for(int d=1; d< size; d++){
     		for(int i = 0; i+d < size; i++){
     			int a = nums[i] - dp[i+1][i+d];
     			int b = nums[i+d] - dp[i][i+d-1];

     			dp[i][i+d] = max(a, b);
     		}
     	}

     	return (dp[0][size-1] >= )0;
    }
};