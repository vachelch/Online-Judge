// set
// time complexity: O(n) , space complexity: O(n)
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        set<int> st;
        long long total = 0;
        for(auto n: nums){
            st.insert(n);
            total += n;
        }
        
        long long sum = 0;
        for(auto n: st)
            sum += n;
        
        return (sum*3 - total)/2;
    }
};




// bit manipulation
// time complexity: O(n) , space complexity: O(1)
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for(int i=0; i<32; i++){
            int sum = 0;
            for(auto n: nums){
                sum += (n >> i) & 1;
                sum %= 3;
            }

            res = res | (sum << i);
        }

        return res;
    }
};





















