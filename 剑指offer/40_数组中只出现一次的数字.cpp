class Solution {
public:
    int findFirstBit(int diff){
        int offset = 0;
        while((diff & 1) == 0){
            diff >>= 1;
            offset ++;
        }

        return offset;
    }
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
        vector<int> group1;
        vector<int> group2;
        
        // divide data to 2 groups, num1, num2 in each group
        // insight: XOR of two same number get 0
        int diff = 0;
        for(auto d: data)
            diff ^= d;
        int offset = findFirstBit(diff);
        diff = 1 << offset;
        for(auto d: data){
            if (diff & d)
                group1.push_back(d);
            else
                group2.push_back(d);
        }
        
        // XOR to get num1, num2
        (*num1) = 0;
        (*num2) = 0;
        for(auto d: group1)
            (*num1) ^= d;
        for(auto d: group2)
            (*num2) ^= d;
        
        return ;
    }
};