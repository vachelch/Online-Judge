class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        vector<vector<int>> B;
        for(int i=0; i< A.size(); i++){
            vector<int> row;
            for(int j=0; j< A[0].size(); j++){
                int item = (A[i][j] == 1)? 0: 1;
                row.insert(row.begin(), item);
            }
            B.push_back(row);
        }
        
    return B;
    }
};