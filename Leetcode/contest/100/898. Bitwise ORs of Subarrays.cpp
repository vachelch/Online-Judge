#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;


class Solution {
public:
    int subarrayBitwiseORs(vector<int>& A) {
    	set<int> current;
    	set<int> all;

    	for(int i= A.size()-1; i >= 0; i--){
    		set<int> behind = current;
    		current.clear();

    		current.insert(A[i]);
    		for(auto b: behind){
    			current.insert(b | A[i]);
    		}

    		for(auto c: current){
    			all.insert(c);
    		}
    	}

    	return all.size();
    }
};

int main(){
	Solution s;
	int a[] = {1,2,4};

	vector<int> A(a, a+ 3);

	cout<< s.subarrayBitwiseORs(A)<< endl;

	return 0;
}