class Solution {
public:
    void bigNumbers(int n, string& str){
        if (n == 0) printAsNumber(str);
        
        int moduler = n % 10;
        for(int i=0; i<= moduler; i++){
            bigNumbers(n / 10, str + ('0' + i));
        }
    }
    void Print(int n) {
        string str;
        bigNumbers(n, str);
    }
};