// O(n), deque
class Solution {
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size)
    {
        deque<unsigned int> queue;
        vector<int> res;

        for(unsigned int i=0; i< num.size(); i++){
            // pop num not in window
            while(!queue.empty() && i - queue.front() >= size)
                queue.pop_front();

            // pop num less than cur
            while(!queue.empty() && num[queue.back()] <= num[i])
                queue.pop_back();
            // push cur
            queue.push_back(i);

            // append max
            if(i >= size-1) res.push_back(num[queue.front()]);
        }

        return res;
    }
};
// && !queue.empty()


// O(nlogk), heap
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