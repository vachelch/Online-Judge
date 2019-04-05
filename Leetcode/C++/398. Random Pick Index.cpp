// slower
class Solution {
public:
    map<int, vector<int> >dict;
    Solution(vector<int> nums) {
        for(int i=0; i< nums.size(); i++){
            if (dict.find(nums[i]) != dict.end())
                dict[nums[i]].push_back(i);
            else
                dict[nums[i]] = vector<int> (1, i);
        }
    }
    
    int pick(int target) {
        vector<int> idxs = dict[target];
        return idxs[rand() % idxs.size()];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int param_1 = obj.pick(target);
 */



// faster
// faster
class Solution {
public:
	vector<int> arr;
    Solution(vector<int> nums) {
        arr = nums;
    }
    
    int pick(int target) {
        vector<int> res;
    	for(int i=0; i< arr.size(); i++){
    		if (arr[i] == target)
    			res.push_back(i);
    	}

    	return res[rand() % res.size()];
    }
};

