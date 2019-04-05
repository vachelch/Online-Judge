class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int count = 0;
        int l = nums.size();
        for(int i=2; i<l; i++){
        	int left = 0, right = i-1;
        	while(right > left){
        		if(nums[left] + nums[right] > nums[i]){
        			count += right - left;
        			right --;
        		}
        		else
        			left ++;
        	}
        }

        return count;
    }
};