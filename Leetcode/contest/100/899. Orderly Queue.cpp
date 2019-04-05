#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string orderlyQueue(string S, int K) {
        if (K == 0)
        	return S;
        if (K == 1){
        	int size = S.size();
        	string min_str = S;
        	for(int i=0; i< S.size(); i++){
        		string left = S.substr(0, i);
        		string right = S.substr(i, size-i);

        		string cur = right + left;

        		if (cur < min_str)
        			min_str = cur;
        	}
        	return min_str;
        }
        else{
        	sort(S.begin(), S.end());
        	return S;
        }

    }
};


int main(){
	Solution s;
	string S = "baaca";
	int K = 3;

	cout << s.orderlyQueue(S, K) << endl;

	return 0;
}