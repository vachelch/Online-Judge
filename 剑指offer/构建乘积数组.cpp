class Solution {
public:
    vector<int> multiply(const vector<int>& A) {
        vector<int> left(A.size());
        vector<int> res(A.size());
        
        int mul = 1;
        for(int i=0; i< A.size(); i++){
            left[i] = mul;
            mul *= A[i];
        }
        
        mul = 1;
        for(int i=A.size()-1; i>= 0; i--){
            res[i] = mul * left[i];
            mul *= A[i];
        }
        
        return res;
    }
};




