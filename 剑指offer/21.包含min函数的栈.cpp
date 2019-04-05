class Solution {
public:
    vector<int> stk;
    vector<int> stk_min;
    void push(int value) {
        stk.push_back(value);
        if (stk_min.empty())
            stk_min.push_back(value);
        else{
             if (stk_min.back() > value)
                 stk_min.push_back(value);
            else
                stk_min.push_back(stk_min.back());
        }
    }
    void pop() {
        if (!stk.empty()){
            stk.pop_back();
            stk_min.pop_back();
        }
    }
    int top() {
        if (!stk.empty()) return stk.back();
        else return 0;
    }
    int min() {
        if (!stk_min.empty()) return stk_min.back();
        else return 0;
    }
};