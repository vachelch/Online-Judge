class Solution {
public:
    int bin_search(vector<int> &ascends, int n){
        int l = 0, r = ascends.size()-1;

        while(l < r){
            int mid = (l + r) /2 ;
            if (ascends[mid] >= n)
                r = mid;
            else
                l = mid + 1;
        }

        return l;
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<int> ascends;
        
        for(auto n: nums){
            if (ascends.empty() || ascends.back() < n)
                ascends.push_back(n);
            
            else if (ascends.back() > n){
                int idx = bin_search(ascends, n);
                ascends[idx] = n;
            }
        }
        
        return ascends.size();
    }
};