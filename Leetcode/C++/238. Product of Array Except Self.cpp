class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int len = nums.size();
        vector<int> before(len, 1);
        
        for(int i=1; i< len; i++)
            before[i] = before[i-1] * nums[i-1];
        
        int behind = 1;
        for(int i=len-1; i>=0; i--){
            before[i] = behind * before[i];
            behind *= nums[i];
        }
        
        return before;
    }
};