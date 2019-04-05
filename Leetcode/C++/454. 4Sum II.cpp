class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int len = A.size();
        int res = 0;
        map<int, int> dict1;
        map<int, int> dict2;
        
        for(int i=0; i< len; i++)
            for(int j=0; j< len; j++){
                if (dict1.find(A[i] + B[j]) == dict1.end())
                    dict1[A[i] + B[j]] = 1;
                else
                    dict1[A[i] + B[j]] ++;
            }
        
        for(int i=0; i< len; i++)
            for(int j=0; j< len; j++){
                if (dict2.find(C[i] + D[j]) == dict2.end())
                    dict2[C[i] + D[j]] = 1;
                else
                    dict2[C[i] + D[j]] ++;
            }
        
        for(const auto it: dict1){
            if (dict2.find(-1 * it.first) != dict2.end())
                res += it.second * dict2[-1 * it.first];
        }
        
        return res;
    }
};



// less memory
class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int res = 0;
        unordered_map<int, int> dict;
        
        for(auto a: A)
            for(auto b: B){
                dict[a + b] ++;
            }
        
        for(auto c: C)
            for(auto d: D){
                if (dict.find(0 - c - d) != dict.end())
                    res += dict[0 - c - d];
            }
        
        
        return res;
    }
};