#include <iostream>
#include <vector>
using namespace std;

bool compare(int a, int b){
	return (a < b);
}

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
    	sort(nums.begin(), nums.end(), compare);
    	vector<pair<int, int> > points;

    	if (nums.size() == 0) return 0;
        if (nums.size() == 1) return nums[0];

    	int sum = nums[0];
    	for(int i=1; i< nums.size(); i++){
    		if (nums[i] == nums[i-1]){
    			sum += nums[i];
    		}
    		else{
    			points.push_back(make_pair(nums[i-1], sum));
    			sum = nums[i];
    		}
    	}

    	points.push_back(make_pair(nums.back(), sum));


    	int dp0 = points[0].second;
    	int dp1;
    	if (points[0].first == points[1].first - 1)
    		dp1 = max(points[1].second, points[0].second); 
    	else
    		dp1 = points[1].second + points[0].second;

    	for(int i=2; i< points.size(); i++){
    		if (points[i].first != points[i-1].first + 1){
    			dp0 = dp1;
    			dp1 = dp1 + points[i].second;
    		}
    		else{
    			int tmp = dp1;
    			dp1 = max(dp1, dp0 + points[i].second);
    			dp0 = tmp;
    		}
    	}

    	return dp1;
    }
};



int main(){
    int num[] = {1,1,1,2,4,5,5,5,6};
    vector<int> nums(num, num+9);
    Solution s;
    cout << s.deleteAndEarn(nums)<< endl;

    return 0;
}