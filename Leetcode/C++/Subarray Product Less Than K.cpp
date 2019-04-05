class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k<=1) return 0;
        
        int multi = 1;
        int left = 0, count = 0;
        int l = nums.size();
        
        for(int right=0; right<l; right++){
            multi *= nums[right];
            while(multi >= k){
                multi /= nums[left];
                left++;
            }
            count += right - left + 1;
        }
        
        return count;
    }
};