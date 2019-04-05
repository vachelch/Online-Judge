class Solution {
public:
    int myAtoi(string str) {
        int idx = 0;
        while(idx < str.size() && (str[idx] == ' ')){
            idx++;
        }
        
        if (idx > str.size()- 1) return 0;
        int sign = 1;
        
        if (str[idx] == '-'){
            sign = -1;
            idx ++;
        }
        else if (str[idx] == '+')
            idx ++;
        
        string res = "";
        while(idx < str.size() && isdigit(str[idx])){
            res += str[idx];
            idx ++;
        }
        
        // erase 0
        for(int i =0; i< res.size(); i++){
            if (res[i] != '0'){
                res = res.substr(i);
                break;
            }
        }
        if (res.size() == 0 || res[0] == '0') return 0;
            
        if (res.size() > 10){
            if (sign == 1)
                return INT_MAX;
            else
                return INT_MIN;
        }

        long long ll_res = 0;
        for(int i=0; i< res.size(); i++)
            ll_res = ll_res * 10 + res[i] - '0';

        if (res.size() == 10){
            if (sign == 1 && ll_res >= INT_MAX) return INT_MAX;
            if (sign == -1 && ll_res-1 >= INT_MAX) return INT_MIN;
        }
        
        return sign * ll_res;
    }
};





















