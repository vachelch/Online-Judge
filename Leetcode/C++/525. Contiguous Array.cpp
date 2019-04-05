class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int mx = 0;
        int sum = 0;
        map<int, int> dict;
        dict[0] = -1;
        
        for(int i=0; i< nums.size(); i++){
        	if (nums[i] == 0)
        		sum --;
        	else
        		sum ++;
        	
        	if (dict.find(sum) != dict.end())
        		mx = max(mx, i - dict[sum]);
        	else
        		dict[sum] = i;
        }
            
        return mx;
    }
};