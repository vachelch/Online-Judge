class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        set<int> st;
        st.insert(1);
        
        for(auto num: nums){
            if (num >= 0)
            st.insert(num+1);
        }
        
        for(auto num: nums){
            st.erase(num);
        }
        
        int res = INT_MAX;
        for(auto num: st)
            res = min(res, num);
        
        return res;
    }
};