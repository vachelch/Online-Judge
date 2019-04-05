class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
    	// vec[i] represents the minimun value of the last element in the subsequence of len = (i+1)
        vector<int> vec;

        for(auto n: nums){
        	if (vec.empty() || n > vec.back())
        		vec.push_back(n);

        	else if (n < vec.back()){
        		int i=0;
        		while(i < vec.size()){
        			if (vec[i] < n) 
        				i ++;
        			else if (vec[i] >= n){
        				vec[i] = n;
        				break;
        			}
        		}
        	}
        	
        	if (vec.size() == 3)
        		return true;
        }

        return false;
    }
};