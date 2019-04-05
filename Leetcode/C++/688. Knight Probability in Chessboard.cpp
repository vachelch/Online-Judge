#include <iostream>
using namespace std;

class Solution {
public:
    double knightProbability(int N, int K, int r, int c) {
  		int rp[] = {2, 2, -2, -2, 1, 1, -1, -1};
  		int cp[] = {1, -1, 1, -1, 2, -2, 2, -2};
  		double poss = 0.125;
  		double dp[N][N][K+1];
  		memset(dp, 0.0, N*N*(K+1)*sizeof(double));

  		for(int i=0; i< N; i++)
  			for(int j=0; j< N; j++)
  				dp[i][j][0] = 1.0;

  		for(int k=1; k<= K; k++){
  			// for every cell
  			for(int i=0; i< N; i++)
  				for(int j=0; j< N; j++){
  					// per cell
  					for(int p=0; p< 8; p++){
			  			int x = i + rp[p];
			  			int y = j + cp[p];
						
						if (0 <= x && x < N && 0 <= y && y < N){
							dp[i][j][k] += poss * dp[x][y][k-1];
						}
			  		}
  				}
  		}

		return dp[r][c][K];
	}
};

int main(){
	Solution s;
	cout << s.knightProbability(10, 13, 5, 3) << endl;

	return 0;
}