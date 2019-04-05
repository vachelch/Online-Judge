class Solution {
public:
    int arrayNesting(vector<int>& nums) {
    	int l = nums.size();
    	int mx= 0;

    	for(int i=0; i<l; i++){
    		if(nums[i] != -1){
    			int count = 1;
    			int index = nums[i];
    			nums[i] = -1;
    			int init = i;

    			while(index != init){
    				count ++;
    				int tmp = index;
    				index = nums[index];
    				nums[tmp] = -1;
    			}
    			mx = max(mx, count);
    		}
    	}

    	return mx;
    }
};