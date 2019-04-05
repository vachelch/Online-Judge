#include <iostream>
#include <string>
#include <map>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        if (t.empty()) return "";
            
        map<char, int> chrT2cnt;
        map<char, int> chrS2cnt;
        
        for(auto c : t)
            chrT2cnt[c] ++;
        
        int chr_num = chrT2cnt.size();
        int left, right;
        left = 0;
        right = -1;
        int cur_num = 0;
        string res = "";
        int flag = 1;
        int size = s.size();
        
        while(right < size){
            while(cur_num < chr_num){
                right ++;

                while (right < size && chrT2cnt.find(s[right]) == chrT2cnt.end())
                    right ++;

                if (right < size)
                    chrS2cnt[s[right]] ++;
                else
                    break;
            

                if (chrS2cnt[s[right]] == chrT2cnt[s[right]])
                    cur_num ++;
            }
            
            if (right == size)  break;

            while(chrT2cnt.find(s[left]) == chrT2cnt.end())
                left ++;

            // found

            if ((right - left + 1) < res.size() || flag){
                flag = 0;
                res = s.substr(left, right - left + 1);
            }

            chrS2cnt[s[left]] --;
            if (chrS2cnt[s[left]] < chrT2cnt[s[left]])
                cur_num --;
            left ++;
        }
        
        return res;
    }
};


int main(){
    string s = "p";
    string t = "q";
    Solution sol;
    string res = sol.minWindow(s, t);

    cout << res << endl;
    return 0;
}













