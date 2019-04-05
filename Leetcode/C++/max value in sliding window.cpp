class Solution {
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size)
    {
        multiset<int, greater<int>> st;
        vector<int> res;
            
        for (int i=0; i< num.size(); i++){
            if (st.size() < size-1)
                st.insert(num[i]);
            else if (st.size() == size-1){
                st.insert(num[i]);
                res.push_back(*(st.begin()));
            }
            else{
                // delete
                int rm = num[i-size];
                multiset<int>::iterator it = st.find(rm);
                if (it != st.end()){
                    st.erase(it);
                }
                // push
                st.insert(num[i]);
                // max
                res.push_back(*(st.begin()));
            }
        }
         
        return res;
    }
};