class Solution {
public:
    int numDecodings(string s) {
        if (s[0] == '0') return 0;
        if (s.size() <= 1) return s.size();
        
        int lastlast = 1;
        int last = 1;
        if (s[1] == '0'){
            if (s[0] >= '3') return 0;
        }   
        else if (s[0] == '1' || (s[0] == '2' && s[1] <= '6'))
            last = 2;
        
        int i = 2;
        while(i != s.size()){
            int cur;
            if (s[i] == '0'){
                if (s[i-1] == '0' || s[i-1] >= '3')
                     return 0;
                cur = lastlast;
            }
            else if (s[i-1] == '1' || (s[i-1] == '2' && s[i] <= '6'))
                cur = last + lastlast;
            else
                cur = last;
            
            lastlast = last;
            last = cur;
            i++;
        }
        
        return last;
    }
};