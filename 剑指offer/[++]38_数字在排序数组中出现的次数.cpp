class Solution {
public:
    int idx_l;
    int idx_r;
    
    int bin_search_left(vector<int>& data, int k){
        int l = 0; 
        int r = data.size() - 1; 
        int mid = (l + r) / 2;
        
        while(l <= r){
            if(data[mid] < k)
                l = mid + 1;
            else
                r = mid - 1;

            mid = (l + r) / 2;
        }
        
        return l;
    }
    
    int bin_search_right(vector<int>& data, int k){
        int l = idx_l; 
        int r = data.size() - 1;
        int mid = (l + r) / 2;
        
        while(l <= r){
            if(data[mid] <= k)
                l = mid + 1;
            else
                r = mid - 1;

            mid = (l + r) / 2;
        }
        
        return r;
    }
    
    int GetNumberOfK(vector<int> data ,int k) {
        if ( data.empty() ) return 0;
        
        idx_l = bin_search_left(data, k);
        if (data[idx_l] != k) return 0;
        
        idx_r = bin_search_right(data, k);

        cout << idx_l << " " << idx_r << endl;
        
        return idx_r - idx_l + 1;
    }
};