class Solution {
public:
    // f(n, m) = (f(n-1,m) + m) % n;
    int LastRemaining_Solution(int n, int m)
    {
        if (n <= 0) return -1;
        
        int last = 0;
        for(int i=2; i<= n; i++){
            last = (last + m) % i;
        }
        
        return last;
    }
};