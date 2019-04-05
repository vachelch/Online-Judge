class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int W) {
        int size = hand.size();
        if(size % W != 0) return false;
        
        map<int, int> dict;
        for(auto num: hand)
            dict[num]++;
        
        for(auto it: dict){
            if (it.second != 0){
                for(int i=0; i<W; i++){
                    if (dict.find(it.first + i) != dict.end()){
                        dict[it.first + i] -= it.second;
                        if (dict[it.first + i] < 0)
                            return false;
                    }
                    else
                        return false;
                }
            }
        }
        
        return true;
    }
};