class Solution {
public:
    int factorial(int n){
        int prime = 1;
        int res;
        for(int i=2; i<=sqrt(n); i++){
            if (n % i == 0){
                prime = 0;
                res = i;
                break;
            }
        }
        
        if (prime) return n;
        return res;
    }
    int minSteps(int n) {
        vector<int>dp(2,0);

        for(int i=2; i<= n; i++){
            int fac = factorial(i);
            if (fac == i)
                dp.push_back(i);
            else
                dp.push_back(dp[fac] + dp[i / fac]);
        }
        return dp[n];
    }
};