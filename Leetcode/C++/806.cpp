class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string S) {
        int line = 0;
        int units = 0;
        
        for (int i=0; i< S.size(); i++){
            int width = widths[S[i] - 'a'];
            if(units + width > 100){
                line += 1;
                units = width;
            }
            else{
                units += width;
            }
        }
        
        vector<int> res(2, 0);
        res[0] = line + 1;
        res[1] = units;
        
        return res;
    }
};