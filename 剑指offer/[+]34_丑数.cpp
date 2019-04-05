class Solution {
public:
    int GetUglyNumber_Solution(int index) {
        if (index <= 0) return 0; // in case of index is negative
        
        vector<int> uglies(index);
        uglies[0] = 1;
        vector<int> ptr(3, 0);
        int nums[] = {2, 3, 5};
        
        for(int i=1; i< index; i++){
            int mn = INT_MAX;
            int idx;
            // find next ugly number
            for(int j=0; j< 3; j++){
                if (uglies[ptr[j]]*nums[j]< mn){
                    idx = j;
                    mn = uglies[ptr[j]]*nums[j];
                }
            }
            uglies[i] = mn;
            ptr[idx]++;
            
            // update every ptr
            for(int j=0; j< 3; j++){
                while (uglies[ptr[j]] * nums[j] <= mn)
                    ptr[j] ++;
            }
        }
        
        return uglies.back();
    }
};