class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zero = -1;
        int one = -1;
        int two = -1;

        for(auto n: nums){
        	if (n == 0){
        		zero ++;
        		one ++;
        		two ++;

        		nums[two] = 2;
        		nums[one] = 1;
        		nums[zero] = 0;
        		
        	}
        	else if(n == 1){
        		one ++;
        		two ++;

        		nums[two] = 2;
        		nums[one] = 1;

        	}
        	else{
        		two ++;
        		nums[two] = 2;
        	}
        }
    }
};