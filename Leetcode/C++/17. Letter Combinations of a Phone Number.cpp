class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> dp;
        vector<string> last;
        last.push_back("");
        vector<vector<string>> chars;
        string arr1[] = {"a", "b", "c"};
        string arr2[] = {"d", "e", "f"};
        string arr3[] = {"g", "h", "i"};
        string arr4[] = {"j", "k", "l"};
        string arr5[] = {"m", "o", "n"};
        string arr6[] = {"p", "q", "r", "s"};
        string arr7[] = {"t", "u", "v"};
        string arr8[] = {"w", "x", "y", "z"};
        
        vector<string> v1(arr1, arr1+3);
        vector<string> v2(arr2, arr2+3);
        vector<string> v3(arr3, arr3+3);
        vector<string> v4(arr4, arr4+3);
        vector<string> v5(arr5, arr5+3);
        vector<string> v6(arr6, arr6+4);
        vector<string> v7(arr7, arr7+3);
        vector<string> v8(arr8, arr8+4);

        
        chars.push_back(v1);
        chars.push_back(v2);
        chars.push_back(v3);
        chars.push_back(v4);
        chars.push_back(v5);
        chars.push_back(v6);
        chars.push_back(v7);
        chars.push_back(v8);

        for(auto digit: digits){
            dp.clear();
            for(auto s1: last)
                for(auto s2: chars[digit - '2'])
                    dp.push_back(s1 + s2);

            last = dp;
        }

        return dp;
    }
};













