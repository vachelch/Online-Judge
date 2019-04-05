bool compare(int a, int b){
    return a<=b? true: false;
}

class Solution {
public:
    int sumSubseqWidths(vector<int>& A) {
        int res = 0;
        int moduler = 1000000000 + 7;
        sort(A.begin(), A.end(), compare);
        for(int i=0; i< A.size(); i++){
            int power = 1;
            for(int j=i+1; j< A.size(); j++){
                res = (res + power * (A[j] - A[i])) % moduler;
                power = (power * 2) % moduler;
            }
        }
        
        return res;
    }
};