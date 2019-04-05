#include <iostream>
#include <vector>
// #include <limits.h>
using namespace std;
int main(){
    int N = 6;

    vector<int> dp;
    int idx[3] = {0, 0, 0};
    int ugly[3] = {2, 3, 5};
    dp.push_back(1);
    
    for(int i=1; i< N; i++){
        int mn = INT_MAX;
        for(int j=0; j< 3; j++){
            mn = min(mn, ugly[j] * dp[idx[j]]);
        }
        dp.push_back(mn);
        for(int j=0; j< 3; j++){
            while(ugly[j] * dp[idx[j]] <= mn)
                idx[j]++;
        }
    }


    cout << dp.back() << endl;

    return 0;
}

