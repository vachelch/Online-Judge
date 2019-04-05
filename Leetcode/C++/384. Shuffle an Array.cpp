class Solution {
public:
    vector <int> initial;
    vector<int> cur;
    int len;
    Solution(vector<int> nums) {
        initial = nums;
        cur = nums;
        len = nums.size();
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return initial;
    }
    
    /** Returns a random shuffling of the array. */
    void swap(vector<int>& nums, int a, int b){
        int tmp = nums[a];
        nums[a] = nums[b];
        nums[b] = tmp;
    }
    vector<int> shuffle() {
        for(int i=0; i< len; i++){
            swap(cur, rand() % len, i);
        }
        
        return cur;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * vector<int> param_1 = obj.reset();
 * vector<int> param_2 = obj.shuffle();
 */