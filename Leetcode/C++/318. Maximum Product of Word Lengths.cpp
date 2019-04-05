class Solution {
public:
    int maxProduct(vector<string>& words) {
        vector<int> nums;
        for(int i=0; i< words.size(); i++){
            int num = 0;
            for(int j =0; j< words[i].size(); j++){
                num = num | (1 << (words[i][j] - 'a'));
            }
            nums.push_back(num);
        }
        
        int res = 0;
        for(int i=0; i< words.size(); i++){
            for(int j=i+1; j< words.size(); j++){
                if ((nums[i] & nums[j]) == 0){
                    int l1 = words[i].size();
                    int l2 = words[j].size();
                    res = max(l1* l2, res);
                }
            }
        }
        
        return res;
    }
};