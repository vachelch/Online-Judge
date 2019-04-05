class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        int l =0, r = array.size()-1;
        vector<int>  res;
        while(l < r){
            int sm = array[l] + array[r];
            if (sm == sum){
                res.push_back(array[l]);
                res.push_back(array[r]);
                
                return res;
            }
            else if (sm < sum){
                l++;
            }
            else{
                r--;
            }
        }
        
        return res;
    }
};