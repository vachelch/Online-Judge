class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int mn = INT_MAX;
        int res;
        int l = nums.size();

        for(int i=0; i<l-2; i++){
        	int left = i+1;
        	int right = l-1;

        	while (left < right){
        		int sum_ = nums[i] + nums[left] + nums[right];
        		int difference = abs(target - sum_);
        		if (difference < mn){
        			mn = difference;
        			res = sum_;
        		}
        		if(target - sum_ > 0)
        			left ++;
        		else if(target - sum_<0)
        			right--;
        		else
        			return res;
        	}
        }

        return res;

    }
};