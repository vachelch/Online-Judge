#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    vector<vector<int> > threeSum(vector<int>& nums) {
    	sort(nums.begin(), nums.end());
        int l = nums.size();
        vector<vector<int> > res;

        for(int i=0; i<l-2; i++){
        	int left = i+1;
        	int right = l-1;
        	int n_i = nums[i];

        	if (i==0 || n_i != nums[i-1]){
        		while (left < right){
        			int n_l = nums[left];
        			int n_r = nums[right];

        			int sum_ = n_i + n_l + n_r;

        			if(sum_ == 0){
        				if ((left == i+1 || n_l != nums[left-1]) && (right == l-1 || n_r != nums[right + 1]))
	        				res.push_back({n_i, n_l, n_r});
	        				left ++;
        			}

        			else if (sum_ < 0)
        				left ++;
        			else
        				right --;
        		}
        	}
        }

        return res;
    }
};


int main(){
	vector<int> nums(4, 0);
	Solution s;
	s.threeSum(nums);

	return 0;
}



