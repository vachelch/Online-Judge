class Solution {
public:
    vector<vector<int> > FindContinuousSequence(int sum) {
        int l = 1;
        int r = 2;
        vector<vector<int> > res;
        vector<int> seq;
        
        int total = 3;
        while(r < sum){
            if (total == sum){
                seq.clear();
                for(int i=l; i<= r; i++)
                    seq.push_back(i);
                res.push_back(seq);
                
                r++;
                total += r;
            }
            else if (total < sum){
                ++ r;
                total += r;
            }
            else{
                total -= l;
                l++;
            }
        }
        
        return res;
    }
};