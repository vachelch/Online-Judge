class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
       if(numerator == 0) return "0";
        
        string res;
        if (numerator< 0 ^ denominator < 0) res += "-";
        
        // abs(int param), go wrong when denominator == INT_MIN
        // int64_t r = abs(numerator); 
        // int64_t denom = abs(denominator);
        int64_t r = numerator;
        int64_t denom = denominator;
        
        if (numerator < 0)
        	r = numerator * -1.0;
        if (denominator < 0)
        	denom = -1.0 * denominator;
        
        res += to_string(r / denom);
        if (r % denom == 0) return res;
        
        map<int64_t, int> dict;
        res += ".";
        
        r = r % denom;
        while(r != 0){
            if (dict.count(r) > 0){
                res.insert(dict[r], 1, '(');
                res += ")";
                break;
            }

            dict[r] = res.size();
            r = r * 10;
            res += to_string(r / denom);
            r = r % denom;
        }
        
        return res;
    }
};

