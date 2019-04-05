bool cmp(string a, string b){
	return a + b > b + a;
}

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> nums_str(nums.size());

        for (int i=0; i< nums.size(); i++)
        	nums_str[i] = to_string(nums[i]);

        sort(nums_str.begin(), nums_str.end(), cmp);

        if (nums_str[0] == "0") return "0";

        string res = "";

        for(int i= 0; i < nums_str.size(); i++){
        	res += nums_str[i];
        }

        return res;
    }
};