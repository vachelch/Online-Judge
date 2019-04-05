class Solution {
public:
    string LeftRotateString(string str, int n) {
        if (str.empty()) return str;
        
        int remainder = n % str.size();
        string res;
        if (remainder >= 0){
            string left = str.substr(0, remainder);
            string right = str.substr(remainder);
            res = right + left;
        }
        else{
            n = -1 * n;
            remainder = -1 * remainder;
            string left = str.substr(0, n - remainder);
            string right = str.substr(n - remainder);
            res = right + left;
        }
        
        return res;
    }
};