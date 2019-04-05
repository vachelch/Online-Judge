// common ancestor, dfs, pi
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    /**
     * 返回git树上两点的最近分割点
     * 
     * @param matrix 接邻矩阵，表示git树，matrix[i][j] == '1' 当且仅当git树中第i个和第j个节点有连接，节点0为git树的跟节点
     * @param indexA 节点A的index
     * @param indexB 节点B的index
     * @return 整型
     */
    void dfs(vector<string> matrix, vector<int>& pi, vector<int>& visited, int idx, int fa){
        visited[idx] = 1;
        pi[idx] = fa;
        for(int i=0; i< matrix[idx].size(); i++){
            if (matrix[idx][i] == '1' && !visited[i]){
                dfs(matrix, pi, visited, i, idx);
            }
        }
    }
    
    int getSplitNode(vector<string> matrix, int indexA, int indexB) {
        vector<int> pi(matrix.size(), -1);
        vector<int> visited(matrix.size(), 0);
        for(int i=0; i<matrix.size(); i++){
            if (!visited[i]) dfs(matrix, pi, visited, i, -1);
        }
        
        vector<int> ancestors_A;
        vector<int> ancestors_B;
        while(indexA != -1){
            ancestors_A.push_back(indexA);
            indexA = pi[indexA];
        }
        while(indexB != -1){
            ancestors_B.push_back(indexB);
            indexB = pi[indexB];
        }

        int i=ancestors_A.size()-1;
        int j=ancestors_B.size()-1;
        int res;
        while(i >=0  && j >= 0 && ancestors_A[i] == ancestors_B[j]){
            res = ancestors_A[i--];
            j--;
        }
        return res;
    }
};


int main(){
    string matrix_[] = {"01011","10100","01000","10000","10000"};
    vector<string> matrix(matrix_, matrix_+5);
    int indexA = 1, indexB = 2;
    Solution s = Solution();
    cout << s.getSplitNode(matrix, indexA, indexB) << endl;

    return 0;
}

