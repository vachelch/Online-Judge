class Solution {
public:
    double Pow(double x, int n){
        if (n == 1)
            return x;
        
        double ans = Pow(x, n/2);
        if (n % 2 == 0){
            return ans * ans;
        }
        else{
            return ans * ans * x;
        }
    }
    double myPow(double x, int n) {
        if (x == 0) return x;
        if (n == 0) return 1;
        
        double res = Pow(x, n/2);
        if (n % 2)
            return n< 0? 
    }
};


class Solution {
public:
   double myPow(double x, int n) {
        if (n==0) return 1;
        double t = myPow(x,n/2);
        if (n%2) {
            return n<0 ? 1/x*t*t : x*t*t;
        } else {
            return t*t;
        }
    }
};

