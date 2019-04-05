class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int size = nums.size();
        if (size == 0) return;
        
        sort(nums.begin(), nums.end());
        int middle;
        int odd = 1;
        int even;
        
        if (size % 2){
            middle = nums[size/2];   
            even = size-1;
        }   
        else{
            middle = (nums[size/2] + nums[(size-1)/2]) / 2;   
            even = size-2;
        }
        
        vector<int> res(size);
        for(int i=0; i < size; i++){
            if (nums[i] < middle){
                res[even] = nums[i];
                even -= 2;
            }
            else if(nums[i] > middle){
                res[odd] = nums[i];
                odd += 2;
            }
        }
        
        while(odd < size){
            res[odd] = middle;
            odd += 2;
        }
        
        while(even >= 0){
            res[even] = middle;
            even -= 2;
        }
        
        nums = res;
    }
};