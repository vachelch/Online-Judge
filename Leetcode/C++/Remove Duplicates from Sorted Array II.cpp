class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int l = nums.size();
        if (l<= 2) return l;
        int total = 2;

        for(int i=2; i<l; i++){
            if(nums[i] != nums[i-2])
                total ++;
        }

        return total;
    }
};

