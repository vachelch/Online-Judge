#include <iostream>
#include <vector>
using namespace std;

// backtrace (TLE)
class Solution {
public:
	double res;
	void backtrace(vector<int>& A, vector<int>& B, double sm, int start, int cur, int k){
		if (cur == A.size() || (cur < A.size() && k == 0)) return ;

		if (k == 1 && cur == A.size()-1){
			sm += (double)(B.back() - B[start] + A[start]) / (cur - start + 1);
			res = max(sm, res);
			return ;
		}

		double tmp = (double)(B[cur] - B[start] + A[start]) / (cur - start + 1);
		backtrace(A, B, sm + tmp, cur+1, cur+1, k-1);
		backtrace(A, B, sm, start, cur+1, k);
	}
    double largestSumOfAverages(vector<int>& A, int K) {
    	res = 0;
		vector<int> B = A;
		for(int i=1; i< B.size(); i++)
			B[i] += B[i-1];

		backtrace(A, B, 0, 0, 0, K);

		return res;
    }
};



// DP
class Solution {
public:
    double largestSumOfAverages(vector<int>& A, int K) {
    	int size = A.size();
    	double dp[size][K+1];
    	memset( dp, 0, size*(K+1)*sizeof(double) );

    	vector<int> B = A;
    	for(int i=1; i< B.size(); i++)
			B[i] += B[i-1];

		for(int i=0; i<size; i++)
			for(int j=i; j< size; j++)
				dp[j][1] = ((double)B[j]) / (j + 1);

		for(int k=2; k<= K; k++){
	    	for(int i=1; i< size; i++){
    			for(int l = 0; l < i; l ++){
    				if (i+1 >= k)
    					dp[i][k] = max(dp[i][k], dp[l][k-1] + (double)(B[i] - B[l+1] + A[l+1]) / (i - l));
    			}
	    	}
    	}

    	return dp[size-1][K];
    }
};

int main(){
	// int a[] = {4,1,7,5,6,2,3};
	// int a[] = {8969,4910,8015,5009,4874,1092};
	int a[] = {8822,2355,6002,5176,8185,807,6152,4962,4402,5925};
	int K = 7;
	vector<int> A(a, a+10);

	Solution s;
	cout << s.largestSumOfAverages(A, K) << endl;

	return 0;
}










