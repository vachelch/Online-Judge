class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int len = nums.size();
        vector<int> bits(32, 0);
        
        for(int i=0; i< len; i++){
            for(int j=0; j< 32; j++){
                bits[j] += ((nums[i] & (1<< j)) > 0);
            }
        }
        
        // for(int i=0; i< 32; i++)
        //     cout << bits[i] << endl;

        int res = 0;
        
        for(int i=0; i< 32; i++)
            res += (bits[i] * (len - bits[i]));
        
        return res;
    }
};