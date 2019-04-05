class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        set<int> B_st;
        int sm_B = 0, sm_A = 0;

        for(auto n: B){
        	sm_B += n;
        	B_st.insert(n);
        }

        for(auto a: A)
        	sm_A += a;

        int diff = (sm_A - sm_B) / 2;
        for(auto a: A){
        	if (B_st.find(a - diff) != B_st.end()){
        		vector<int> v;
        		v.push_back(a);
        		v.push_back(a-diff);

        		return v;
        	}
        }
    }
};