//dp, beat 22.68%
class Solution {
public:
	int largest_square(int n){
		int s = 1;
		while(s * s <= n){
			s++;
		}

		return s-1;
	}
    int numSquares(int n) {
        vector<int> dp(n+1, INT_MAX);
        vector<int> square;

        int i = 1;
        while(i * i <= n){
        	square.push_back(i*i);
        	i++;
        }

        dp[0] = 0;
        for(i=1; i<= n; i++){
        	int s = largest_square(i);
        	for(int j=0; j< s; j++){
        		dp[i] = min(dp[i], 1 + dp[i - square[j]]);
        	}
        }

        return dp[n];
    }
};


//dp + (largest_square = floor(sqrt(n)))
class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1, INT_MAX);

        dp[0] = 0;
        for(int i=1; i<= n; i++){
        	int s = floor(sqrt(i));
        	for(int j=1; j<= s; j++){
        		dp[i] = min(dp[i], 1 + dp[i - j*j]);
        	}
        }

        return dp[n];
    }
};