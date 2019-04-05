class Solution {
public:
    int res = 0;
    int REMINDER = 1000000007;
    vector<int> buffer;
    void swap(vector<int>& data, int l, int r){
        int tmp = data[l];
        data[l] = data[r];
        data[r] = tmp;
    }
    void merge(vector<int>& data, int l, int r, int ll, int rr){
        int i = l, j = ll, pos = l;
        int cur = 0;

        // sort
        i = l, j = ll;
        while(i<= r && j <= rr){
            if (data[i] <= data[j]){
                buffer[pos ++] = data[i++];
                res = (res + j - ll) % REMINDER;
            }
            else{
                buffer[pos ++] = data[j++];
            }
        }
        while(i<= r){
            buffer[pos ++] = data[i++];
            res = (res + j - ll) % REMINDER;
        }
        while(j <= rr){
            buffer[pos ++] = data[j++];
        }
        
        // copy
        for(int i=l; i<= rr; i++){
             data[i] = buffer[i];
        }
    }
    void divide_and_conquer(vector<int>& data, int l, int r){
        if(l + 1 >= r){
            if (data[l] > data[r]){
                swap(data, l, r);
                res = (res + 1)% REMINDER;
            }
            return ;
        }
        
        int mid = l + ((r-l)>>2);
        divide_and_conquer(data, l, mid);
        divide_and_conquer(data, mid+1, r);

        merge(data, l, mid, mid+1, r);
    }
    int InversePairs(vector<int> data) {
        if (data.empty()) return 0;

        buffer.assign(data.size(), 0);
        divide_and_conquer(data, 0, data.size()-1);
        
        return res;
    }
};
