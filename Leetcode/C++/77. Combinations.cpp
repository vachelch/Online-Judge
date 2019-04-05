class Solution {
public:
	vector<vector<int>> res;
	void backtrace(int num, vector<int>& cur, int k, int limit){
		if (k == 0 && cur.back() <= limit) {
			res.push_back(cur);
			return;
		}
		if (num > limit) return;

		backtrace(num + 1, cur ,k, limit);

		cur.push_back(num);
		backtrace(num + 1, cur, k-1, limit);
		cur.pop_back();
	}
    vector<vector<int>> combine(int n, int k) {
    	vector<int> cur;
  		backtrace(1, cur, k, n);

  		return res;
    }
};