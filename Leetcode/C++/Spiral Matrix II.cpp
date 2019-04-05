#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
    	// if (n == 0) return {};

        vector<vector<int> > res(n, vector<int>(n, 0));
        int direction[][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        int i = 0;
        int j = 0;
        int k = 0;
        int start = 1;
        vector<int> dirct(direction[0], direction[0]+2);
        int end = n*n+1;

        while (start != end){
        	while(i>=0 && i<n && j>=0 && j<n && res[i][j] == 0){
	        	res[i][j] = start;
	        	start ++;
	        	i += dirct[0];
	        	j += dirct[1];
	        	
	        }

	        i -= dirct[0];
	        j -= dirct[1];

	        if (k==3) 
	        	k =0;
	        else 
	        	k ++;
	        dirct.assign(direction[k], direction[k]+2);
	        
	        i += dirct[0];
	        j += dirct[1];

        }
	        
        return res;

    }
};


int main(){
	int n = 3;
	Solution s;

	vector<vector<int> > res = s.generateMatrix(n);
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++)
			cout<<res[i][j]<<' ';
		cout<<'\n';
	}
		
	return 0;
}


