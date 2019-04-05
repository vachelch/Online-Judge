class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        vector<int> stk;
        
        int i = 0, j = 0;
        while(i != pushV.size()){
            if(pushV[i] != popV[j]){
                stk.push_back(pushV[i++]);
            }
            else{
                ++ i;
                ++ j;
            }
        }
        
        while(j != popV.size()){
            if(stk.back() != popV[j]) return false;
            stk.pop_back();
            ++ j;
        }
        
        return true;
    }
};