#include <iostream>
#include <vector>
using namespace std;

// be careful to the situation of some weights appearing to be 0.
class Solution {
public:
    vector<int> period;
    int sum;
    Solution(vector<int> w) {
        for(int i=1; i< w.size(); i++){
            w[i] += w[i-1];
        }
        period.assign(w.begin(), w.end());
        sum = w.back();
    }
    
    int pickIndex() {
        float val = (float)rand() / RAND_MAX * sum;
        int left = 0, right = period.size()-1;
        
        while(left < right){
            int mid = (left + right)/2;
            if(period[mid] < val)
                left = mid+1;
            else
                right = mid;
        }
        return right;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(w);
 * int param_1 = obj.pickIndex();
 */

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(w);
 * int param_1 = obj.pickIndex();
 */

int main(){
    vector<int> w;
    int w_[] = {1,2,3};
    w.assign(w_, w_+3);

    cout << RAND_MAX << endl;

    Solution* obj = new Solution(w);
    cout << obj->pickIndex() << endl;
    cout << obj->pickIndex() << endl;
    cout << obj->pickIndex() << endl;
    cout << obj->pickIndex() << endl;
    return 0;
}






















