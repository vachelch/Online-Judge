class Solution {
public:
    int matrixScore(vector<vector<int>>& A) {
        int M = A.size();
        int N = A[0].size();
        	
        int score = (1 << (N - 1)) * M;
        // second column and after
        for(int j = 1; j< N; j++){
        	int sum = 0;
        	for (int i=0; i < M; i++)
        		sum += (A[i][j] == A[i][0]);

        	if (sum < M - sum)
                score += (1 << (N - 1 - j)) * (M - sum);
            else
                score += (1 << (N - 1 - j)) * sum;
        }

        return score;
    }
};
