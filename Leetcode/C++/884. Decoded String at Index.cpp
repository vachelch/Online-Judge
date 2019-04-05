class Solution {
public:
    string decodeAtIndex(string S, int K) {
        long long previous = 0, cur = 0, total = 0;
        long long i = 0;
        while(1){
            if(isalpha(S[i])){
                cur += 1;
                if (previous + cur == K)
                    return string(1, S[i]);
            }
            else{
                total = (previous + cur) * (S[i] - '0');
                
                if (total >= K){
                    K = K % (previous+cur);
                    if (K == 0)
                        return decodeAtIndex(S, previous+cur);
                    else
                        return decodeAtIndex(S, K);
                }
                else{
                    previous = total;
                    cur = 0;
                }
            }
            
            i++;
        }
        
    }
};