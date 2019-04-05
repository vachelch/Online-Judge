class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0, r = 0;
        map<char, int> alphas;

        int res = 0;
        while(r < s.size()){
        	alphas[s[r]] ++;
        	while(alphas[s[r]] == 2){
        		alphas[s[l]] --;
        		l ++;
        	}

        	res = max(r - l + 1, res);
        	r ++;
        }

        return res;
    }
};