class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        if (tokens.empty()) return 0;
        
        vector<int> stk;
    
        for(auto t: tokens){
            if (t == "+"){
                int a = stk.back();
                stk.pop_back();
                int b = a + stk.back();
                stk.pop_back();
                
                stk.push_back(b);
            }
            else if (t == "-"){
                int a = stk.back();
                stk.pop_back();
                int b = stk.back() - a;
                stk.pop_back();
                
                stk.push_back(b);
            }
            else if (t == "*"){
                int a = stk.back();
                stk.pop_back();
                int b = a * stk.back();
                stk.pop_back();
                
                stk.push_back(b);
            }
            else if (t == "/"){
                int a = stk.back();
                stk.pop_back();
                int b = stk.back() / a;
                stk.pop_back();
                
                stk.push_back(b);
            }
            else{
                stk.push_back(stoi(t));
            }
        }
        
        return stk[0];
    }
};