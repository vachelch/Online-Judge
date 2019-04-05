class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int i=0;
        while(i < nums.size() -1){
            if (nums[i] != nums[i+1])
                return nums[i];
            else
                i += 2;
        }
        return nums.back();
    }
};



class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if (nums.size() == 1 || nums[0] != nums[1]) return nums[0];
        if (nums.back() != nums[nums.size()-2]) return nums.back();

        int left = 1;
        int right = nums.size()-2;
        int middle;

        while (left <= right){
            middle = (left + right) /2;
            if (nums[middle] != nums[middle - 1] && nums[middle] != nums[middle + 1])
                return nums[middle];
            else if((middle % 2 == 0 && nums[middle] == nums[middle+1]) || (middle % 2 != 0 && nums[middle] == nums[middle-1]))
                left = middle + 1;
            else
                right = middle - 1;
        }

        return nums[middle];
    }
};













