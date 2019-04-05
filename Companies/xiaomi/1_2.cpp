// AC
// divide array to to aprt

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    /**
     * 计算你能获得的最大收益
     * 
     * @param prices Prices[i]即第i天的股价
     * @return 整型
     */
	int profit(vector<int> prices, int l, int r){
		if (r <= l) return 0;

		vector<int>mx_vec(r-l+1);
		vector<int>mn_vec(r-l+1);
		int mx = 0, mn = 200;
		for(int i=l; i<= r; i++){
			mn = min(mn, prices[i]);
			mn_vec[i-l] = mn;
		}

		for(int i = r; i>=l; i--){
			mx = max(mx, prices[i]);
			mx_vec[i-l] = mx;
		}

		int res = 0;
		for(int i=0; i<= r-l; i++){
			res = max(res, mx_vec[i] - mn_vec[i]);
		}

		return res;
	}
    int calculateMax(vector<int> prices) {
    	int l = 0, r = prices.size()-1;
    	int mx = 0;
    	for(int i=0; i< prices.size(); i++){
    		mx = max(mx, profit(prices, 0, i) + profit(prices, i+1, r));
    	}

    	return mx;
    }
};

int main(){
	int vec[] = {10,7,3,1};
	vector<int> prices(vec, vec + 4);
	Solution s = Solution();
	cout << s.calculateMax(prices) << endl;

	return 0;
}