#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int orderOfLargestPlusSign(int N, vector<vector<int> >& mines) {
    	int dp_left[N][N];
    	int dp_right[N][N];
    	int dp_up[N][N];
    	int dp_down[N][N];

    	for(int i=0; i< N; i++)
    		for(int j=0; j< N; j++){
    			dp_left[i][j] = 1;
		    	dp_right[i][j] = 1;
		    	dp_up[i][j] = 1;
		    	dp_down[i][j] = 1;
    		}

        for(auto ord: mines){
        	int x = ord[0], y = ord[1];
        	dp_left[x][y] = 0;
        	dp_right[x][y] = 0;
        	dp_up[x][y] = 0;
        	dp_down[x][y] = 0;
        }

        for(int i=0; i< N; i++){
        	for(int j=1; j< N; j++){
        		if (dp_left[i][j] == 1)
        			dp_left[i][j] = dp_left[i][j-1] + 1;
        	}

        	for(int j=N-2; j>= 0; j--){
        		if (dp_right[i][j] == 1)
        			dp_right[i][j] = dp_right[i][j+1] + 1;
        	}

        }

        for(int j=0; j< N; j++){
        	for(int i=1; i< N; i++){
        		if (dp_up[i][j] == 1)
        			dp_up[i][j] = dp_up[i-1][j] + 1;
        	}

        	for(int i=N-2; i>= 0; i--){
        		if (dp_down[i][j] == 1)
        			dp_down[i][j] = dp_down[i+1][j] + 1;
        	}
        }

        int res = 0;
        for(int i=0; i< N; i++){
        	for(int j=0; j< N; j++){
        		int mn = dp_left[i][j];
        		mn = min(mn, dp_right[i][j]);
        		mn = min(mn, dp_up[i][j]);
        		mn = min(mn, dp_down[i][j]);

        		res = max(res, mn);
        	}
        }


        return res;
    }
};

int main(){
	int N = 5;
	int mines_arr[23][2] = {{0,1},{0,2},{0,3},{0,4},{1,0},{1,1},{1,2},{1,3},{1,4},{2,0},{2,1},{2,3},{2,4},{3,1},{3,2},{3,3},{3,4},{4,0},{4,1},{4,2},{4,3},{4,4}};
	vector<vector<int> > mines;
	for(int i=0; i< 23; i++){
		int x = mines_arr[i][0], y = mines_arr[i][1];
		vector<int> v;
		v.push_back(x);
		v.push_back(y);
		mines.push_back(v);
	}

	Solution s;
	cout << s.orderOfLargestPlusSign(N, mines) << endl;

	return 0;
}






