class Solution {
public:
    void reverse(string& str, int l, int r){
        while(r > l){
            // swap(str, l, r)
            int tmp = str[l];
            str[l] = str[r];
            str[r] = tmp;
            
            ++ l;
            -- r;
        }
    }
    string ReverseSentence(string str) {
        if (str.empty()) return "";
        reverse(str, 0, str.size()-1);
        
        int start = 0;
        for(int i=0; i< str.size()-1; i++){
            if (str[i] == ' '){
                reverse(str, start, i-1);
                start = i+1;
            }
        }
        
        reverse(str, start, str.size()-1); // Do not forget this line
        return str;
    }
};