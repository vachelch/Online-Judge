bool myfunc(vector<int>& pair1, vector<int>& pair2){
    return pair1[1] < pair2[1];
}

class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), myfunc);
        
        int res = 1;
        int last = pairs[0][1];
        for(int i=1; i< pairs.size(); i++){
            if(pairs[i][0] > last){
                res ++;
                last = pairs[i][1];
            }
        }
        
        return res;
    }
};