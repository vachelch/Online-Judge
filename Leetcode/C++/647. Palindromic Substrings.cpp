class Solution {
public:
    int countSubstrings(string s) {
    	int len = s.size();
    	int res = 0;
    	int left, right;
        for(int i=0; i< len; i++){
        	// odd palindrome
        	left = i - 1;
        	right = i + 1;
        	res ++;
        	while(left >= 0 && right <= len - 1 && s[left] == s[right]){
        		res += 1;
        		left --;
        		right ++;
        	}

        	// even palindrome
        	left = i;
        	right = i+1;
        	while(left >= 0 && right <= len - 1 && s[left] == s[right]){
        		res += 1;
        		left --;
        		right ++;
        	}
        }

        return res;
    }
};