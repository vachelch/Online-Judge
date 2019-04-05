class Solution {
public:
    int numberOfOne(int num){
        int cnt = 0;
        while(num){
            cnt += ((num % 10) == 1);
            num /= 10;
        }
        return cnt;
    }
    int NumberOf1Between1AndN_Solution(int n)
    {
        int res = 0;
        for(int i=0; i <= n; i++){
            res += numberOfOne(i);
        }
        
        return res;
    }
};