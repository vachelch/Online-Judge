// dp
class Solution {
public:
    int Fibonacci(int n) {
        int a = 0;
        int b = 1;
        if (n == 0) return a;
        if (n == 1) return b;
        
        for(int i=2; i<=n; i++){
            int tmp = a+b;
            a = b;
            b = tmp;
        }
        
        return b;
    }
};

// Linear Algebra
// [f(n), f(n-1)].T = [[1, 1] * [f(n-1), f(n-2)].T
//                     [1, 0]] 