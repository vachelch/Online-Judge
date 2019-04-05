// traverse
class Solution {
public:
	int res;
	
	void traverse(vector<int> &nums, int idx, int sum, int target){
		if (idx == nums.size()){
			if (sum == target)
				res++;
			return ;
		}

		traverse(nums, idx+1, sum + nums[idx], target);
		traverse(nums, idx+1, sum - nums[idx], target);
	}

    int findTargetSumWays(vector<int>& nums, int S) {
    	res = 0;
        traverse(nums, 0, 0, S);

        return res;
    }
};





// traverse with memorization
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
    	map<int, int>last;
    	map<int, int>sums;
    	last[0] = 1;
        for(int i=0; i<nums.size(); i++){
        	sums.clear();
        	for(auto it: last){
        		sums[it.first + nums[i]] += it.second;
        		sums[it.first - nums[i]] += it.second;
        	}
        	last = sums;
        }
        return sums[S];
    }
};




// recursion
class Solution {
public:
	int helper(vector<int>& nums, int idx, int S){
		if (idx == 0){
			int res = 0;
			if (nums[idx] == S)
				res++;
			if (0-nums[idx] == S)
				res++;

			return res;
		}
		return helper(nums, idx-1, S - nums[idx]) + helper(nums, idx-1, S + nums[idx]);
	}
    int findTargetSumWays(vector<int>& nums, int S) {
    	return helper(nums, nums.size()-1, S);
    }
};













