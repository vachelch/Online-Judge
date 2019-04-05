class Solution {
public:
    bool is_number(char *string, int l, int r, int point = 0){
        if (l > r) return false;
        
        if (string[l] == '+' || string[l] == '-')
            l ++;
        while(l <= r){
            if(string[l] == '.' && point == 0)
                point = 1;
            else if ('0' <= string[l] && string[l] <= '9')
                ;
            else return false;
            
            l ++;
        }
        
        return true;
    }
    bool isNumeric(char* string)
    {
        int i=0;
        while(i< strlen(string) && string[i] != 'e' && string[i] != 'E'){
            ++ i;
        }
        
        if (is_number(string, 0, i-1)){
            if (i == strlen(string)) return true;
            
            if (is_number(string, i+1, strlen(string)-1, 1)) return true;
        }
        
        return false;
    }

};