#include <iostream>
using namespace std;

class Solution {
public:
    int binaryGap(int N) {
        int dist = 0;
        int flag = 0;
        int start;

        int i=0;
        while(N != 0){
        	if((N & 1) != 0){
        		if (flag != 0)
        			dist = max(i - start, dist);

        		flag = 1;
        		start = i;
        	}
        	i ++;
        	N >>= 1;
        }

        return dist;
    }
};

int main(){
	Solution s;
	int test = s.binaryGap(8);
	cout<< test << endl;

	return 0;
}