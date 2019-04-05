class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        int chrs[128] = {0};

        for(auto c: str){
            int offset = c;
            chrs[offset] ++;
        }
        
        for(int i=0; i< str.size(); i++){
            int offset = str[i];
            if (chrs[offset] == 1)
                return i;
        }
        
        return -1;
    }
};


class Solution {
public:
    // -1, initial 
    // -2, repeat
    // index
    int FirstNotRepeatingChar(string str) {
        vector<int> st(128, -1);
        
        for(int i=0; i< str.size(); i++){
            if (st[str[i]] == -1)  st[str[i]] = i;
            else if(st[str[i]] == -2) continue;
            else st[str[i]] = -2;
        }
        
        int mn_idx = str.size();
        for(auto val: st){
            if (val != -1 && val != -2){
                mn_idx = min(mn_idx, val);
            }
        }
        
        return (mn_idx == str.size())? -1: mn_idx;
    }
};