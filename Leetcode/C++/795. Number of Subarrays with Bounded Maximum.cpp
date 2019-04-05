#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& A, int L, int R) {
        int before = 0;
        int res = 0;
        int last = -1;
        for(int i=0; i< A.size(); i++){
            if (L <= A[i] && A[i] <= R){
                before ++;
                last = i;
                res += before;
            }
            else if(A[i] < L){
                before ++;
                if (last != -1){
                    res += before - (i - last);
                }
            }
            else{
                last = -1;
                before = 0;
            }
        }
        
        return res;
    }
};


int main(){
    int B[] = {73,55,36,5,55,14,9,7,72,52};
    int L = 32, R = 69;
    vector<int> A(B, B+ 10);

    Solution s;
    cout << s.numSubarrayBoundedMax(A, L, R) << endl;

    return 0;
}

