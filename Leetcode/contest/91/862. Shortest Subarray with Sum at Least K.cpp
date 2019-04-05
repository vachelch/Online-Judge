#include <iostream>
#include <vector>
#include <deque>
using namespace std;

class Solution {
public:
    int shortestSubarray(vector<int>& A, int K) {
    	int len = A.size();
    	vector<int> sum(A.begin(), A.end());

    	int cursum = 0;
    	for (int i=0; i< len; i++){
    		cursum += A[i];
    		sum[i] = cursum;
    	}

    	sum.insert(sum.begin(), 0);

    	deque<int> queue;
    	queue.push_back(0);

    	int min_len = 50001;
    	for(int y=1; y< len + 1; y++){
    		while(queue.size() > 0 && sum[y] < sum[queue.back()]){
    			queue.pop_back();
    		}

    		queue.push_back(y);
    		
    		while(queue.size() > 0 && sum[y] - sum[queue[0]] >= K){
    			min_len = min(min_len, y - queue[0]);
    			queue.pop_front();
    		}
    	}

    	if (min_len == 50001) return -1;
    	return min_len;
    }

};

int main(){
	int A_arr[] = {48, 99, 37, 4, -31};
	vector<int> A(A_arr, A_arr + 5);
	int K = 140;

	Solution s;
	int res = s.shortestSubarray(A, K);

	cout << res << endl;
	return 0;
}



