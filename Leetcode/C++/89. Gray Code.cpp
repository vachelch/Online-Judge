// dfs
class Solution {
public:
    vector<int> visited;
    vector<int> res;
    
    void backtrace(int num, int N){
        int code;
        visited[num] = 1;
        res.push_back(num);
        
        for(int i=0; i< N; i++){
            code = num ^ (1 << i);
            if (visited[code] == 0){
                backtrace(code, N);   
            }
        }
    }
    vector<int> grayCode(int n) {
        visited.assign(pow(2, n), 0);
        backtrace(0, n);
        
        return res;
    }
};




// dp
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res(1, 0);
        for(int i=0; i< n; i++){
            int size = res.size();
            while(--size >= 0){
                int num = res[size] + (1 << i);
                res.push_back(num);
            }
        }
        return res;
    }
};

































