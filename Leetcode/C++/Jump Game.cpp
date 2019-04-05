class Solution {
public:
    bool canJump(vector<int>& nums) {
    	int l = nums.size();
    	int mx = 0;

        for(int i=0; i<l; i++){
        	mx = max(nums[i] + i, mx);

        	if(mx == i){
        		if (i == l-1) return true;
        		else
        			return false;
        	}
        }

        return true;
    }
};