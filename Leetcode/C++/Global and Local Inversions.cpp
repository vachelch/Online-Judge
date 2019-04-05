#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isIdealPermutation(vector<int>& A) {
    	int l = A.size();
    	if(l < 2) return true;

    	int max_ = A[0];
        for(int i= 2; i<l; i++){
        	if(A[i] < max_)
        		return false;
        	max_ = max(A[i-1], max_);
        }
        return true;
    }
};

int main(){
	int A_tmp[] = {1, 0, 2};
	// int A_tmp[] = {1, 2, 0};
	vector<int>A(A_tmp, A_tmp+3);
	
	Solution s;
	cout<<s.isIdealPermutation(A)<<endl;

	return 0;
}