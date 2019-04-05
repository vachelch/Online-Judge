// "  +123   " -> 123
// "  -123   " -> 123
// "123a" -> 0
// "a123" -> 0
class Solution {
public:
    int cleanSpace(string& str, int k){
        int idx = k;
        while(idx < str.size() && str[idx] == ' ')
            ++ idx ;
        
        return idx;
    }
        
    int StrToInt(string str) {
        if (str.empty()) return 0;
        
        int idx = cleanSpace(str, 0);
        if (idx < str.size() && (('0' <= str[idx] && str[idx] <= '9') || str[idx] == '+' || str[idx] == '-')){
            int sign = 1;
            
            if (str[idx] == '-'){
                sign = -1;
                ++ idx;
            } 
            else if (str[idx] == '+'){
                ++ idx ;
            }
            
            int number = 0;
            while(idx < str.size() && '0' <= str[idx] && str[idx] <= '9'){
                number = number * 10 + (str[idx] - '0');
                idx ++;
            }
            idx = cleanSpace(str, idx);
            if (idx < str.size()) return 0;
            
            return sign * number;
        }
        else
            return 0;
    }
};