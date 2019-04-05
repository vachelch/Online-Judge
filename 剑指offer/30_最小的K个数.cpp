// O(nlog(k)), mutiset
class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        vector<int> res;
        if (k <= 0 || input.size() < k) return res;
            
        multiset<int, greater<int>> mset;
        
        for(auto num: input){
            if (mset.size() < k) mset.insert(num);
            else{
                multiset<int>::iterator it = mset.begin();
                int mx = (*it);
                if (mx > num){
                    mset.erase(mx);
                    mset.insert(num);
                }
            }
        }
        
        res.assign(mset.begin(), mset.end());
        
        return res;
    }
};


// O(n) in average, partition 
class Solution {
public:
    int partition(vector<int>& input, int l, int r){
        int pivot = input[r];
        int next = l-1;
        
        for(int i=l; i<= r; i++){
            if (input[i] <= pivot){
                next ++;
                // swap(input, next, i);
                int tmp = input[i];
                input[i] = input[next];
                input[next] =tmp;
            }
        }
        
        return next;
    }
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        vector<int> res;
        if (k <= 0 || input.size() < k) return res;
        int l = 0, r = input.size()-1;
        int pivot = partition(input, l, r);
        while(pivot != k-1){
            if (pivot < k-1)
                l = pivot +1;
            else
                r = pivot -1;
            pivot = partition(input, l, r);
        }
        
        res.assign(input.begin(), input.begin() + k);
        return res;
    }
};




// nlog(n), sort















