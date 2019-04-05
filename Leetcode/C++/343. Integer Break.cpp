class Solution {
public:
    int helper(int n){
        if (n <= 3) return n;
        return max(helper(n-2)* 2, helper(n-3) * 3);
    }
    int integerBreak(int n) {
        if (n == 2) return 1;
        if (n==3) return 2;
        return helper(n);
        
    }
};


// dp
class Solution {
public:
    int integerBreak(int n) {
        if (n == 2) return 1;
        if (n == 3) return 2;
    	int dp[n+1];
    	dp[2] = 2;
    	dp[3] = 3;
    	dp[4] = 4;
        for(int i=5; i<=n; i++){
        	dp[i] = max(dp[i-3] * 3, dp[i-2]*2);
        }

        return dp[n];
    }
};