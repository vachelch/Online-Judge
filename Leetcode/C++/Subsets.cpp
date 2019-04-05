// class Solution {
// public:
//     vector<vector<int> > subsets(vector<int>& nums) {
//     	sort(nums.begin(), nums.end());
//         vector<vector<int> > res;
//         vector<int> sol;
//         res.push_back(sol);
//         findSubsets(0, nums, res, sol);

//         return res;
//     }

//     void findSubsets(int start, vector<int>& nums, vector<vector<int> > &res, vector<int> sol){
//     	for(int i=start; i<nums.size(); i++){
//     		sol.push_back(nums[i]);
//     		res.push_back(sol);
//     		findSubsets(i+1, nums, res, sol);
//     		sol.pop_back();
//     	}
//     }

// };


class Solution {
public:
    vector<vector<int> > subsets(vector<int>& nums) {
    	sort(nums.begin(), nums.end());
    	int l_n = nums.size();
    	long long l_sub = pow(2, l_n);
    	vector<vector<int>> res;

    	for(long long i=0; i<l_sub; i++){
    		int val = i;
    		vector<int> sol;

    		for(int j = 0; j<l_n; j++){
    			if (val & 1) sol.push_back(nums[j]);
    			val >>= 1;
    		}
    		res.push_back(sol);
    	}

        return res;
    }

};


















