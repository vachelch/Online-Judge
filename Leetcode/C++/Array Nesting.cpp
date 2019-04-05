class Solution {
public:
    int arrayNesting(vector<int>& nums) {
    	int mx = 0;
    	int l = nums.size();
    	set<int> nest;
        for(int i=0; i<l; i++){
        	if(nest.find(nums[i]) != nest.end()){

        		int init = i;
        		int index = i;
        		set<int> iset;

        		while 1{
        			if(iset.find(index) != iset.end()){
        				if(index == init)
        					mx = max(mx, iset.size());
        				break;
        			}
        			else{
        				nest.insert(index);
        				index = nums[index];
        			}
        		}
        		set_intersection(nest.begin(), nest.end(), iset.begin, iset.end(), inserter(nest, nest.end()))
        	}
        }
        return mx;
    }
};