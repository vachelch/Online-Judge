class Solution
{
public:
  //Insert one char from stringstream
    vector<int> cnt;
    vector<int> position;
    int length;
    
    void Insert(char ch)
    {
        if (position[ch] == -1)
            position[ch] = length;
        else
            position[ch] = -2;

        ++ length;
    }
  //return the first appearence once char in current stringstream
    char FirstAppearingOnce()
    {
        int mn_idx = INT_MAX;
        int res = -1;
        for(int i=0; i< 128; i++){
            if (position[i] >= 0 && mn_idx > position[i]) {
                mn_idx = position[i];
                res = i;
            }
        }
        
        if (res == -1) return '#';
        
        char chr = res;
        return chr;
    }
    
    Solution(){
        position.assign(128, -1);
        length = 0;
    }

};