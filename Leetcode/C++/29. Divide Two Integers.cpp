class Solution {
public:
    int divide(int dividend, int divisor) {
        int sign = (dividend < 0) ^ (divisor < 0)? -1: 1;
        
        // avoid overflow
        long long a = labs(dividend);
        long long b = labs(divisor);
        long long res = 0;
        
        // get tmp which is nearest number to a
        long long tmp = b;
        long long shift_mul = 1;
        while(tmp <= a){
            tmp <<= 1;
            shift_mul <<= 1;
        }
        tmp >>= 1;
        shift_mul >>= 1;
        res += shift_mul;
        a = a - tmp;
        
        // decrease tmp, keep just less than a
        while(a >= b){
            while(tmp > a){
                tmp >>= 1;
                shift_mul >>= 1;
            }
            res += shift_mul;
            a = a - tmp;
        }   
        
        res = res * sign;
        return (res - 1 == INT_MAX)? INT_MAX : res;
    }
};