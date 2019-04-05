class Solution {
public:
    int getLength(int num, set<int>& nums_set, set<int>& seen){
        int len = 1;
        seen.insert(num);
        int tmp = num+1;
        while(nums_set.find(tmp) != nums_set.end()){
            seen.insert(tmp);
            tmp ++;
            len ++;
        }     
        
        tmp = num-1;
        while(nums_set.find(tmp) != nums_set.end()){
            seen.insert(tmp);
            len ++;
            tmp --;
        }
           
        return len;
    }
    int longestConsecutive(vector<int>& nums) {
        set<int> seen;
        set<int> nums_set;
        for(auto num: nums)
            nums_set.insert(num);
        
        int mx = 0;
        for(auto num: nums_set){
            if (seen.find(num) == seen.end()){
                int len = getLength(num, nums_set, seen);
                mx = max(mx, len);
            }
        }
        
        return mx;
    }
};