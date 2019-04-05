// partition, O(1) space complexity
// O(n) Time complexity in average, O(n*n) Time complexity when in worst case
class Solution {
public:
    void swap(vector<int>& nums, int a, int b){
        int tmp = nums[a];
        nums[a] =nums[b];
        nums[b] = tmp;
    }
    int partition(vector<int>& nums, int start, int end){
        int pivot_val = nums[end];
        int pivot = start - 1;
        
        for(int i=start; i<= end; i++){
            if(nums[i] <= pivot_val){
                swap(nums, i, ++pivot);
            }
        }
        
        return pivot;
    }
    
    int majorityElement(vector<int>& nums) {
        int median = nums.size() / 2;
        int start = 0;
        int end = nums.size() -1;
        int index = -1;
            
        while(index != median){
            if (index < median){
                start = index + 1;
                index = partition(nums, start, end);
            }
            else if (index > median){
                end = index-1;
                index = partition(nums, start, end);
            }
        }
        
        return nums[median];
    }
};



// counter 
// O(n) time complexity, O(1) space complexity
class Solution {
public:  
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int res;

        for(auto num: nums){
            if (count == 0){
                res = num;
                count = 1;
            }
            else{
                if (num != res)
                    count --;
                else
                    count ++;
            }
        }

        return res;
    }
};





























