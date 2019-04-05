#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        // int dp[m+1][n+1] = {0};
        memset(dp, 0, (m+1)*(n+1)* sizeof(int));
        vector<int> ones(strs.size(), 0);
        vector<int>  zeros(strs.size(), 0);

        for(int i=0; i< strs.size(); i++){
            for(auto c: strs[i]){
                ones[i] += (c == '1');
                zeros[i] += (c == '0');
            }
        }
        
        for(int k=1; k<= strs.size(); k++){
            for(int i=m; i>= zeros[k-1]; i--){
                for(int j=n; j>= ones[k-1]; j--){
                    dp[i][j] = max(dp[i][j], dp[i-zeros[k-1]][j-ones[k-1]] + 1);
                }
            }
        }

        return dp[m][n];
    }
}; 

// // dp
// class Solution {
// public:
//     int findMaxForm(vector<string>& strs, int m, int n) {
//         int size = strs.size();
//         if (size == 0) return 0;

//         int dp[m+1][n+1];
//         memset(dp, 0, (m+1)*(n+1)* sizeof(int));

//         for(int k=0; k< size; k++){
//             int zero = 0;
//             int one = 0;

//             for(auto c: strs[k]){
//                 if (c - '0')
//                     one ++;
//                 else
//                     zero ++;
//             }

//             for(int i=m; i>= zero; i--){
//                 for(int j=n; j>= one; j--){
//                     dp[i][j] = max(dp[i][j], dp[i- zero][j - one] + 1);
//                 }
//             }
//         }
//         return dp[m][n];
//     }
// };

int main(){
    // string strs_[] = {"10", "0001", "111001", "1", "0"};
    string strs_[] = {"10", "0", "1"};
    vector<string> strs(strs_, strs_+3);
    int m = 1, n = 1;

    Solution s;
    cout << s.findMaxForm(strs, m, n) << endl;


    return 0;
}





