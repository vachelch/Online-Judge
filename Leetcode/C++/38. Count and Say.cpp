class Solution {
public:
    string countAndSay(int n) {
        string dp = "1";

        for(int i=2; i<= n; i++){
        	int last = 0;
        	char last_chr = dp[0];

        	string new_str = "";
        	for(int j=1; j< dp.size(); j++){
        		if (dp[j] != last_chr){
        			new_str += to_string(j-last) + last_chr;
        			last_chr = dp[j];
        			last = j;
        		}
        	}
            
            new_str += to_string(dp.size()-last) + last_chr;
        	dp = new_str;
        }

        return dp;
    }
};