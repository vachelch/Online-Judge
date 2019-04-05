// set + backtrace, beat 1.55%
class Solution {
public:
	vector<vector<int>> res;
	set<string> st;

	string ToString(vector<int>& v){
		string v_str = "";
		vector<int> v_ = v;

		sort(v_.begin(), v_.end());
		for(auto val: v_){
			v_str += to_string(val) + ",";
		}

		return v_str;
	}
	void backtrace(vector<int>& nums, vector<int>& v, int i){
		if (i == nums.size()){
			string v_str = ToString(v);
			if (st.find(v_str) == st.end()){
				res.push_back(v);
				st.insert(v_str);
			}
			return ;
		}

		v.push_back(nums[i]);
		backtrace(nums, v, i+1);
		v.pop_back();

		backtrace(nums, v, i+1);

	}
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    	vector<int> v;
        backtrace(nums, v, 0);

        return res;
    }
};




// backtrace + map, beat 100%
class Solution {
public:
	vector<vector<int>> res;
	
	void backtrace(vector<pair<int, int>>& nums_uniq, vector<int>& v, int i){
		if (i == nums_uniq.size()){
			res.push_back(v);
			return ;
		}

		int n = nums_uniq[i].second;
		while((n--) >= 0){
			backtrace(nums_uniq, v, i+1);
			v.push_back(nums_uniq[i].first);
		}

		n = nums_uniq[i].second;
		while((n--) >= 0)
			v.pop_back();
	}
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    	map<int, int> dict;
    	for(auto n: nums)
    		dict[n] ++;

    	vector<pair<int, int>> nums_uniq;
    	for(auto it: dict){
    		nums_uniq.push_back(make_pair(it.first, it.second));
    	}


    	vector<int> v;
        backtrace(nums_uniq, v, 0);

        return res;
    }
};



