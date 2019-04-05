// [error] cmp must exist in out side of class Solution

bool cmp(string & a, string & b){
        string c = a + b;
        string d = b + a;
        
        if (c <= d)
            return true;
        else
            return false;
    }

class Solution {
public:
    string PrintMinNumber(vector<int> numbers) {
        vector<string> num_strs;
        for(auto num: numbers){
            num_strs.push_back(to_string(num));
        }
        
        sort(num_strs.begin(), num_strs.end(), cmp);
        
        string res;
        for(auto num: num_strs)
            res += num;
        
        return res;
    }
};