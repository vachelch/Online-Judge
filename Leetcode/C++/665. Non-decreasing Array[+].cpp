class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int flag =1;
        for(int i=1; i< nums.size(); i++){
            if (nums[i] < nums[i-1]){
                if (flag-- == 0) {
                    return false;   
                }
                if (i == 1 || nums[i] >= nums[i-2]) nums[i-1] = nums[i];
                else nums[i] = nums[i-1];
            }   
        }
        
        return true;
    }
};