// Brute force
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> res;
        for(int i=0;i < nums.size(); i++){
            int mx = 1;
            for(int j= i+1; j < nums.size(); j++){
                if (nums[j] > nums[i]){
                    res.push_back(nums[j]);
                    mx = 0;
                    break;
                }
            }
            if (mx){
                for(int j=0; j< i; j++){
                    if (nums[j] > nums[i]){
                        res.push_back(nums[j]);
                        mx = 0;
                        break;
                    }
                }
            }
            if (mx)
                res.push_back(-1);  
        }
        
        return res;
    }
};



// stack
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> res(nums.size());
        deque<int> q;
        for(int i = nums.size()-1; i>=0; i--){
            if(q.empty()){
                res[i] = -1;
                q.push_back(nums[i]);
            }
            else{
                while(!q.empty() && q.back() <= nums[i]){
                    q.pop_back();
                }
                if (q.empty()){
                    res[i] = -1;
                    q.push_back(nums[i]);
                }
                else{
                    res[i] = q.back();
                    q.push_back(nums[i]);
                }
            }
        }
    

        for(int i = nums.size()-1; i>=0; i--){
            while(!q.empty() && q.back() <= nums[i]){
                q.pop_back();
            }
            if (q.empty()){
                return res;
            }
            else{
                res[i] = q.back();
                q.push_back(nums[i]);
            }
        }
        
        return res;
    }
};
































