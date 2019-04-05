class Solution {
public:
    double get_power(double base, int exponent){
        if (exponent == 1) return base;
        double factor = get_power(base, exponent/2);
        
        return (exponent % 2)? factor*factor*base: factor*factor;
    }
    double Power(double base, int exponent) {
        if (exponent == 0) return 1;
        else if (exponent > 0) return get_power(base, exponent);
        else return 1/get_power(base, -1 * exponent);
    }
};