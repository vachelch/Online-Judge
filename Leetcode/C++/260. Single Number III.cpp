bool myfunc(int a, int b){
	return a < b;
}

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
    	sort(nums.begin(), nums.end(), myfunc);
    	vector<int> res;

		for (int i = 0; i < nums.size()-1; i++){
    		if(nums[i] == nums[i+1])
    			i ++;
    		else
    			res.push_back(nums[i]);
    	}

    	if(res.size() == 1)
    		res.push_back(nums.back());

    	return res;

    }
};