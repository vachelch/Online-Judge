class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
       vector<int>dp;
        dp.push_back(1);
        dp.push_back(10);
        
        for(int m=2; m<= n; m++){
            int num = 1;
            int cur = m;
            while(cur){
                num *= (10-cur+1);   
                cur--;
            }

            cur = m-1;
            int num_ = 1;
            while(cur){
                num_ *= (9-cur+1);   
                cur--;
            }
            
            dp.push_back(num - num_ + dp.back());
        }
        if (n == 0) return 1;
        else if(n == 1) return 10;
        else
            return dp.back();
    }
};