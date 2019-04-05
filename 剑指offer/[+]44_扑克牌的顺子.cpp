#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

class Solution {
public:
    // condition 1: no repeated number 
    // condition 2: max - min + 1 <= 5
    bool IsContinuous( vector<int> numbers ) {
        set <int> num_st(numbers.begin(), numbers.end());
        
        int king_cnt = 0;
        int mx = -1, mn = 14;
        for(auto num: numbers){
            if (num != 0){
                mx = max(num, mx);
                mn = min(num, mn);
            }
            else
                king_cnt ++;
        }
        if(king_cnt >= 1){
            if (num_st.size() - 1 + king_cnt < 5) return false;
        }
        else{
            if (num_st.size() < 5) return false;
        }
        
        return (mx - mn + 1 <= 5)? true: false;
    }
};


int main (){
    int a[] = {1,3,0,5,0};
    vector<int> numbers(a, a+5);
    Solution s;

    cout << s.IsContinuous(numbers) << endl;
    
    return 0;
}



