class Solution {
public:
    bool verify(vector<int> &sequence, int l, int r){
        if (l >= r-1) return true;
        
        int value = sequence[r];
        int i = l;
        while(i < r){
            if (sequence[i] > value)
                break;
            ++ i;
        }
        
        int l_r = i-1;
        int r_l = i;
        while(i < r){
            if (sequence[i] < value) return false;
            ++ i;
        }
        
        return verify(sequence, l, l_r) && verify(sequence, r_l, r-1);
    }
    bool VerifySquenceOfBST(vector<int> sequence) {
        if (sequence.empty()) return false;
        return verify(sequence, 0, sequence.size()-1);
    }
};