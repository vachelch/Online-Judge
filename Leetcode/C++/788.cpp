#include <iostream>
#include <string>
#include <set>
using namespace std;

class Solution {
    
public:
    int rotatedDigits(int N) {
        set<char> least_one;
        least_one.insert('2');
        least_one.insert('5');
        least_one.insert('6');
        least_one.insert('9');
        
        set<char> ban;
        ban.insert('3');
        ban.insert('4');
        ban.insert('7');

        int count = 0;
        for(int i=1; i<= N; i++)
            count += isGood(least_one, ban, i);

        return count;
    }
    
    int isGood(set<char> &least_one, set<char> &ban, int num){
        string s = to_string(num);
        int flag = 0;
        for (int i=0; i< s.size(); i++){
            if (ban.find(s[i]) != ban.end())
                return 0;
            else if (least_one.find(s[i]) != least_one.end())
                flag = 1;
        }
        
        return flag;
    }
};


int main(){
    Solution s;
    int count = s.rotatedDigits(10);
    cout<< count << endl;

    return 0;
}















