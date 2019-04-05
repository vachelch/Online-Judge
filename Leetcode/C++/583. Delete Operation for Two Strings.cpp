class Solution {
public:
    int minDistance(string word1, string word2) {
        int size1 = word1.size();
        int size2 = word2.size();
        
        if (size1 == 0 || size2 == 0) return max(size1, size2);
        
        int dp[size2+1] = {0};
        int last[size2 + 1] = {0};
            
        for(int i=1; i<= size1; i++){
            for(int j=1; j<= size2; j++){
                last[j] = dp[j];
                if (word1[i-1] == word2[j-1])
                    dp[j] = last[j-1] + 1;
                else
                    dp[j] = max(dp[j], dp[j-1]);
            }
        }
        
        return size1+size2 - 2 * dp[size2];
    }
};