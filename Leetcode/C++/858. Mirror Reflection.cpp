class Solution {
public:
    int mirrorReflection(int p, int q) {
        int g = lcm(p, q);
        int a = g / p;
        int b = g / q;
        
        if (a % 2 && b % 2) return 1;
        else if(a%2 && b%2 == 0) return 2;
        else return 0;
    }
    int lcm(int p, int q){
        return p*q/gcd(p, q);
    }
    int gcd(int p, int q){
        while(q){
            int r = p % q;
            p = q;
            q = r;
        }
        return p;
    }
};