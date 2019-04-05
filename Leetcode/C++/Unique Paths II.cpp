#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> >& obstacleGrid) {
    	int m = obstacleGrid.size();
    	int n = obstacleGrid[0].size();

    	vector<int> res(n+1, 0);
    	res[1] = 1;

    	for(int i=0; i<m; i++){
    		for(int j=1; j<=n; j++){
    			if(obstacleGrid[i][j-1] != 1)
    				res[j] += res[j-1];
    			else
    				res[j] = 0;
    		}
    	}
    	return res[n];
    }
};

int main(){
	vector<vector<int> > obstacleGrid;
	obstacleGrid.push_back(vector<int> (1, 0));
	obstacleGrid.push_back(vector<int> (1, 1));

	Solution s;

	cout<<s.uniquePathsWithObstacles(obstacleGrid)<<endl;

	return 0;
}