#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    int numRabbits(vector<int>& answers) {
        if (answers.size() == 0) return 0;
        map<int, int> same;
        int res = 0;
        
        for(int i=0; i< answers.size(); i++){
            if (same.find(answers[i]) == same.end())
                same[answers[i]] = 1;
            else
                same[answers[i]] += 1;
        }
        
        for(const auto it : same){
            res += it.second / (it.first + 1) * (it.first + 1);
            res += (it.second % (it.first + 1) != 0) * (it.first + 1);
        }
        
        return res;
    }
};
int main(){
    int ans[] = {0, 0, 1, 1, 1};
    vector <int> answers(ans, ans+5);
    Solution s;
    cout << s.numRabbits(answers) << endl;
}